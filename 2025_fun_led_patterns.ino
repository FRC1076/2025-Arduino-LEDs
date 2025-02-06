
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>  // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN 6

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 32

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

enum States {
  EMPTY,
  CORAL,
  ALGAE
};


enum States currentState;
const int delayVal = 200;

void setup() {
  // put your setup code here, to run once:

  currentState = ALGAE;


  pixels.begin();
}

void loop() {
 pixels.clear();
  // put your main code here, to run repeatedly:
  if (currentState == EMPTY) {
    for (int i = 0; i < NUMPIXELS; i++) {
    
        pixels.setPixelColor(i, pixels.Color(50, 50, 0));
     
       
      }
    
    pixels.show();


  } else if (currentState == CORAL) {
    for (int i = 0; i < NUMPIXELS; i++) {
      pixels.setPixelColor(i, pixels.Color(100, 0, 100));
    }
    pixels.show();
    delay(delayVal);

    for (int i = 0; i < NUMPIXELS; i++) {
      pixels.setPixelColor(i, pixels.Color(0, 0, 0));
    }
    pixels.show();
    delay(delayVal);

  } else if (currentState == ALGAE) {
    for (int i = 0; i < NUMPIXELS; i++) {
    if (i % 8 < 4) {
      pixels.setPixelColor(i, pixels.Color(50, 50, 0));
    } else {
      pixels.setPixelColor(i, pixels.Color(0, 0, 0));
    }
  }
  pixels.show();
  delay(delayVal);
  for (int i = 0; i < NUMPIXELS; i++) {
    if (i % 8 < 4) {
      pixels.setPixelColor(i, pixels.Color(0, 0, 0));
    } else {
      pixels.setPixelColor(i, pixels.Color(50, 0, 50));
    }
  }
  pixels.show();
  delay(delayVal);
    }
  }




/*
if(i < NUMPIXELS / 2){
     pixels.setPixelColor(i, pixels.Color(25, 0, 100));
 }else{
  pixels.setPixelColor(i, pixels.Color(0, 0, 0));
 }
}
 pixels.show();
 delay(delayVal);

for(int i=0; i<NUMPIXELS; i++) {
 
 if(i < NUMPIXELS / 2){
     pixels.setPixelColor(i, pixels.Color(0, 0, 0));
 }else{
  pixels.setPixelColor(i, pixels.Color(25, 0, 100));
 }
}
 pixels.show();
delay(delayVal);
 

}
 */

/*


  if( i % 3 == 0){
  pixels.setPixelColor(i, pixels.Color(0,50,0));
  }else if( i % 3 == 1) {
    pixels.setPixelColor(i, pixels.Color(25, 0, 100));
  }else{pixels.setPixelColor(i, pixels.Color(128, 0, 128));}
}
pixels.show();
delay(delayVal);


  for(int i=0; i<NUMPIXELS; i++) {
  if( i % 3== 0){
    pixels.setPixelColor(i, pixels.Color(50, 0, 0));
  }else if( i % 3== 1){
    pixels.setPixelColor(i, pixels.Color(50, 50, 0));

  }else{
     pixels.setPixelColor(i, pixels.Color(100, 100, 100));
      }
}
pixels.show();
 delay(delayVal);

 for(int i=0; i<NUMPIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(0, 0, 0));
}
pixels.show();
 delay(delayVal);
 }



*/

/*
for (int i = 0; i < NUMPIXELS; i++) {
    if (i % 8 < 4) {
      pixels.setPixelColor(i, pixels.Color(50, 50, 0));
    } else {
      pixels.setPixelColor(i, pixels.Color(0, 0, 0));
    }
  }
  pixels.show();
  delay(delayVal);
  for (int i = 0; i < NUMPIXELS; i++) {
    if (i % 8 < 4) {
      pixels.setPixelColor(i, pixels.Color(0, 0, 0));
    } else {
      pixels.setPixelColor(i, pixels.Color(50, 0, 50));
    }
  }
  pixels.show();
  delay(delayVal);
}
*/
