//------------------------------------------------------------
//
// Luminária de LEDs com vários efeitos
//
// File:     marquee.h
//
// Descrição: Responsável pela criação do efeito Marquee
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

void marquee()
{
    static byte j = HUE_BLUE;
    j += 4;
    byte k = j;

    CRGB c;
    for (int i = 0; i < NUM_LEDS; i++)
        g_LEDs[i] = c.setHue(k += 8);

    static int scroll = 0;
    scroll++;
    
    for (int i = scroll % 5; i < NUM_LEDS - 1; i += 5)
        g_LEDs[i] = CRGB::Black;
    
    delay(50);    
    FastLED.setBrightness(valPot);
    FastLED.show();
    delay(50);
}