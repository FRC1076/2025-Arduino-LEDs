
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>  // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN 6

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 32

int serialInput = 9;
unsigned long startTime;
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

  currentState = CORAL;
  Serial.begin(9600);

  pixels.begin();
}

void loop() {

  unsigned long currentTime = millis();
  unsigned long time = currentTime - startTime;

  Serial.println(time);

  if (Serial.available() > 0) {
    serialInput = Serial.read();
    // Serial.println(currentState);
    Serial.println(serialInput);
    Serial.println(currentState);
    delay(1000);

    if (serialInput == 48) {
      currentState = 0;
    } else if (serialInput == 49) {
      currentState = 1;
    } else if (serialInput == 50) {
      currentState = 2;
    }
  }

  pixels.show();
  // put your main code here, to run repeatedly:
  if (currentState == EMPTY) {
    for (int i = 0; i < NUMPIXELS; i++) {

      pixels.setPixelColor(i, pixels.Color(50, 50, 50));
    }

    pixels.show();


  } else if (currentState == CORAL) {
    if( time % 400 < 200) {
      for (int i = 0; i < NUMPIXELS; i++) {
        pixels.setPixelColor(i, pixels.Color(100, 0, 100));
      }
      pixels.show();
    } else {
      for (int i = 0; i < NUMPIXELS; i++) {
        pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      }
      pixels.show();
    }

  } else if (currentState == ALGAE) {
    if (time % 400 < 200) {
      for (int i = 0; i < NUMPIXELS; i++) {
        if (i % 8 < 4) {
          pixels.setPixelColor(i, pixels.Color(50, 50, 0));
        } else {
          pixels.setPixelColor(i, pixels.Color(0, 0, 0));
        }
      }
      pixels.show();
    } else {
      for (int i = 0; i < NUMPIXELS; i++) {
        if (i % 8 < 4) {
          pixels.setPixelColor(i, pixels.Color(0, 0, 0));
        } else {
          pixels.setPixelColor(i, pixels.Color(50, 0, 50));
        }
      }
      pixels.show();
    }
  }
  /*if (time > 4000 && time <8000) {
    pixels.clear();
    currentState = (States)EMPTY;
    pixels.show();
  } else if (  time > 8000){
    currentState = (States)CORAL;
    pixels.show();

  }
  */
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
