
#include <Adafruit_NeoPixel.h>

#define PIN 3

Adafruit_NeoPixel strip = Adafruit_NeoPixel(3, PIN, NEO_GRB + NEO_KHZ800);


int sensorValue = A1;


int currentColourValue;
int currentColourValue2;
int currentColourValue3;


void setup() {
  strip.begin();
  strip.show(); 
 Serial.begin(9600);
 
 
}

void loop() {

int potRead = analogRead(sensorValue);
 Serial.println(potRead);
   
 
 currentColourValue = (255 - map( analogRead(sensorValue), 0, 1023, 0, 255 ) );
 
 
 colorWipe(strip.Color(currentColourValue, currentColourValue2, currentColourValue3), 50); // Red
 

 }

void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, c);
      strip.show();
      delay(10);
  }
}
