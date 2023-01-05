//------------------------------------------------------------
//
// Luminária de LEDs com vários efeitos
//
// File:     rainbow.h
//
// Descrição: Responsável pela criação do efeito Rainbow
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

#define NUM_LEDS          15
#define g_Brightness      64




// Rainbow Effect Variables
uint8_t initialHue =          0;  // Onde o efeito começa
const uint8_t  deltaHue =     16; // O tamanho do efeito
const uint8_t  hueDensity =   4;  // Velocidade do efeito

void rainbow()
{
    fill_rainbow(g_LEDs, NUM_LEDS, initialHue += hueDensity, deltaHue);
    FastLED.setBrightness(valPot);
    FastLED.show();
    delay(50);
}