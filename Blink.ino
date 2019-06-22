#include "FastLED.h"
#include "FastLED_RGBW.h"
 
#define NUM_LEDS 60
#define DATA_PIN 5
 
CRGBW leds[NUM_LEDS];
CRGB *ledsRGB = (CRGB *) &leds[0];
 
const uint8_t brightness = 128;
 
void setup() { 
  FastLED.addLeds<WS2812B, DATA_PIN, RGB>(ledsRGB, getRGBWsize(NUM_LEDS));
  FastLED.setBrightness(brightness);
  FastLED.show();
}


void loop() { 
  // Turn the LED on, then pause
  leds[7] = CRGB::Red;
  FastLED.show();
  delay(500);
  // Now turn the LED off, then pause
  leds[7] = CRGB::Black;
  FastLED.show();
  delay(500);
}
