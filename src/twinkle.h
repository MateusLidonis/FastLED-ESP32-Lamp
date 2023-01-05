//------------------------------------------------------------
//
// Luminária de LEDs com vários efeitos
//
// File:     twinkle.h
//
// Descrição: Responsável pela criação do efeito Twinkle
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

#define NUM_COLORS 6
  static const CRGB TwinkleColors [NUM_COLORS] = 
   {
    CRGB::Red,
    CRGB::Blue,
    CRGB::Yellow,
    CRGB::Green,
    CRGB::Purple,
    CRGB::Orange  
   };

void twinkleOld()
{
    FastLED.clear(false);

    for (int i = 0; i < NUM_LEDS; i++)
    {
        g_LEDs[random(NUM_LEDS)] = TwinkleColors[random(NUM_COLORS)];
        FastLED.show(g_Brightness);
        delay(200);
    }
}

void twinkle()
{
    static int passCount = 0;
    passCount++;

    if (passCount == NUM_LEDS / 2)
    {
        passCount = 0;
        FastLED.clear(false);
    }
    
    g_LEDs[random(NUM_LEDS)] = TwinkleColors[random(NUM_COLORS)];
    delay(300);

    
    FastLED.setBrightness(valPot);
    FastLED.show();
    delay(50);
}