//------------------------------------------------------------
//
// Luminária de LEDs com vários efeitos
//
// File:     bounce.h
//
// Descrição: Responsável pela criação do efeito Bounce
//
// Autor: Mateus Lidonis Blanco
//
// Data de criação:    12/12/2020
// Última atualização: 19/12/2020 
//
//------------------------------------------------------------


using namespace std;                        
#include <vector> 

// Incluo a biblioteca do Arduino, pois estou usando um FrameWork
#include <Arduino.h>

// Incluo a biblioteca que me permite controlar os LEDs
#include <FastLED.h>

// Tira algumas mensagens do Terminal
#define FASTLED_INTERNAL

void bounce()
{
    for (int i = 0 ; i < NUM_BALLS ; i++) 
    {
        tCycle[i] =  millis() - tLast[i] ;     

 
        h[i] = 0.5 * GRAVITY * pow( tCycle[i]/1000 , 2.0 ) + vImpact[i] * tCycle[i]/1000;

        if ( h[i] < 0 ) 
        {                      
            h[i] = 0;                           
            vImpact[i] = COR[i] * vImpact[i] ;
            tLast[i] = millis();

        if ( vImpact[i] < 0.01 )    
            vImpact[i] = vImpact0; 
        }
        pos[i] = round( h[i] * (NUM_LEDS - 1) / h0); 
  }

 
  for (int i = 0 ; i < NUM_BALLS ; i++) 
    g_LEDs[pos[i]] += CHSV( uint8_t (i * 40) , 255, 255);
    FastLED.show();
 
  for (int i = 0 ; i < NUM_BALLS ; i++) 
  {
    g_LEDs[pos[i]] = CRGB::Black;
  }

  FastLED.setBrightness(valPot);

  
}


