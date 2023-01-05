//------------------------------------------------------------
//
// Luminária de LEDs com vários efeitos
//
// File:     comet.h
//
// Descrição: Responsável pela criação do efeito Comet
//
// Autor: Mateus Lidonis Blanco
//
// Data de criação:    12/12/2020
// Última atualização: 19/12/2020 
//
//------------------------------------------------------------

// Incluo a biblioteca do Arduino, pois estou usando um FrameWork
#include <Arduino.h>

// Incluo a biblioteca que me permite controlar os LEDs
#include <FastLED.h>

// Tira algumas mensagens do Terminal
#define FASTLED_INTERNAL
#define NUM_LEDS 15
#define g_Brightness      64

extern CRGB g_LEDs[];

void comet()
{      
    const byte fadeAtm = 128;
    const int cometSize = 1;
    const int deltaHue = 4;

    static byte hue = HUE_RED;
    static int iDirection = 1;
    static int iPos = 0;

    hue += deltaHue;
    iPos += iDirection;

    if (iPos == (NUM_LEDS - cometSize) || iPos == 0)
        iDirection *= -1;

    for (int i = 0; i < cometSize; i++)
        g_LEDs[iPos + i].setHue(hue);

    for (int j = 0; j < NUM_LEDS; j++)
        if (random(2) == 1)
        g_LEDs[j] = g_LEDs[j].fadeToBlackBy(fadeAtm);

    FastLED.setBrightness(valPot);
    FastLED.show();
    delay(100);
}