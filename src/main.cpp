//------------------------------------------------------------
//
// Luminária de LEDs com vários efeitos
//
// File:     main.cpp
//
// Descrição: Desenhar os efeitos na fita de LED
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


#define BTN_PIN           2
int efeito = 0;
boolean botaoAnt = false;
boolean botaoAtu = false;

#define potPin 34

int valPot = 0;

#define NUM_LEDS          15
#define DATA_PIN          5
#define COLOR_ORDER       GRB
#define CHIPSET           WS2812B
int g_Brightness = valPot;
#define GRAVITY           -3              
#define h0                1                 
#define NUM_BALLS         10                

float h[NUM_BALLS] ;                         
float vImpact0 = sqrt( -2 * GRAVITY * h0 );  
float vImpact[NUM_BALLS] ;                   
float tCycle[NUM_BALLS] ;                    
int   pos[NUM_BALLS] ;                      
long  tLast[NUM_BALLS] ;                     
float COR[NUM_BALLS] ;                       

CRGB g_LEDs[NUM_LEDS] = {0};

// Incluo as bibliotecas de efeitos

#include "rainbow.h"
#include  "marquee.h"
#include "twinkle.h"
#include "comet.h"
#include "bounce.h"
#include "fire.h"

// Void Setup para as configurações
void setup() 
{
    delay(2000);                               
    FastLED.addLeds<CHIPSET, DATA_PIN, COLOR_ORDER>(g_LEDs, NUM_LEDS);
    LEDS.setBrightness(g_Brightness);
    for (int i = 0 ; i < NUM_BALLS ; i++) 
    {    
        tLast[i] = millis();
        h[i] = h0;
        pos[i] = 0;                              
        vImpact[i] = vImpact0;                   
        tCycle[i] = 0;
        COR[i] = 0.90 - float(i)/pow(NUM_BALLS,2); 
    }

    pinMode(BTN_PIN, INPUT);
    pinMode(potPin, INPUT);    
}


// Void Loop, que se repete
void loop() 
{ 
    valPot = analogRead(potPin);
    valPot = map(valPot, 0, 1023, 2, 8);
    
    botaoAtu = digitalRead(BTN_PIN);
    if (botaoAtu && !botaoAnt)
    {
        efeito++;

        if (efeito > 10)
        {
            efeito = 0;
        }
    }
    botaoAnt = botaoAtu;

    switch (efeito)
    {
    case 0:
        FastLED.clear();
        rainbow();
        FastLED.clear();
        break;
    
    case 1:
        FastLED.clear();
        marquee();
        FastLED.clear();        
        break;

    case 2:        
        twinkle();        
        break;

    case 3:        
        comet();        
        break;

    case 4:
        FastLED.clear();
        bounce();        
        break;

    case 5:
        FastLED.clear();
        Fire(40,100,15);       
        break;

    case 6:
        FastLED.clear();
        fill_solid(g_LEDs, NUM_LEDS, CRGB::Yellow);
        FastLED.show(valPot);              
        break;

    case 7:
        FastLED.clear();
        fill_solid(g_LEDs, NUM_LEDS, CRGB::DeepPink);
        FastLED.show(valPot);
        break;

    case 8:
        FastLED.clear();
        fill_solid(g_LEDs, NUM_LEDS, CRGB::FloralWhite);
        FastLED.show(valPot);
        break;

    case 9:
        FastLED.clear();
        fill_solid(g_LEDs, NUM_LEDS, CRGB::YellowGreen);
        FastLED.show(valPot);
        break;

    case 10:
        FastLED.clear();
        fill_solid(g_LEDs, NUM_LEDS, CRGB::DarkGreen);
        FastLED.show(valPot);
        break;
    }
}


