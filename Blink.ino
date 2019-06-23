#include "FastLED.h"
#include "FastLED_RGBW.h"
 
#define NUM_LEDS 60
#define LED_PIN 5
#define GREEN_BUTTON_PIN 3
#define RED_BUTTON_PIN 0
 
CRGBW leds[NUM_LEDS];
CRGB *ledsRGB = (CRGB *) &leds[0];
 
const uint8_t brightness = 128;
int buttonState;
volatile byte state = LOW;
int greenI = -1;
int redI = 59;

 
void setup() { 
  FastLED.addLeds<WS2812B, LED_PIN, RGB>(ledsRGB, getRGBWsize(NUM_LEDS));
  FastLED.setBrightness(brightness);
  FastLED.show();
  pinMode(LED_PIN, OUTPUT);
  pinMode(GREEN_BUTTON_PIN, INPUT);
  pinMode(RED_BUTTON_PIN, INPUT);
  //attachInterrupt(digitalPinToInterrupt(GREEN_BUTTON_PIN), setGreen, FALLING);
  attachInterrupt(digitalPinToInterrupt(RED_BUTTON_PIN), setGreen, FALLING);
  //attachInterrupt(digitalPinToInterrupt(RED_BUTTON_PIN), setRed, FALLING);
}


void loop() { 
  // Turn the LED on, then 
/*
  leds[7] = CRGB::Blue;
  FastLED.show();
  delay(500);
  // Now turn the LED off, then pause
  leds[7] = CRGB::Black;
  FastLED.show();
  delay(500);
  */
  //digitalWrite(ledPin, state);
  leds[greenI] = CRGB::Green;
  leds[redI] = CRGB::Red;
  FastLED.show();
  delay(80);
  
}

void setGreen() {
  static unsigned long last_interrupt_time = 0;
 unsigned long interrupt_time = millis();
 // If interrupts come faster than 200ms, assume it's a bounce and ignore
 if (interrupt_time - last_interrupt_time > 50)  {
   greenI += 1;
   greenI = greenI%60;
 }
 last_interrupt_time = interrupt_time;
  
}

void setRed() {
  static unsigned long last_interrupt_time = 0;
 unsigned long interrupt_time = millis();
 // If interrupts come faster than 200ms, assume it's a bounce and ignore
 if (interrupt_time - last_interrupt_time > 50)  {
   redI -= 1;
 }
 last_interrupt_time = interrupt_time;
  
}
