// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// Released under the GPLv3 license to match the rest of the
// Adafruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN        6

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 25

// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals. Note that for older NeoPixel
// strips you might need to change the third parameter -- see the
// strandtest example for more information on possible values.
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

enum States {EMPTY, HOLDING, HANDOFF};

States currentState; // state the robot is in

void setup() {
  // the line below this should change based on which state you want to test
  // options are "empty", "holding", and "handoff"
  currentState = States::HANDOFF;

 
  /* IGNORE THE LINES BELOW
  These lines are specifically to support the Adafruit Trinket 5V 16 MHz.
  Any other board, you can remove this part (but no harm leaving it): */
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  // END of Trinket-specific code.

  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels.setBrightness(50);
}


void loop() {
  // check the state the robot is in and display the corresponding color
  if(currentState == States::EMPTY) {
    // solid purple
    setColor(100, 0, 100);
  } else if(currentState == States::HOLDING) {
    // flashing purple
    setColor(100, 0, 100);
    delay(500);
    setColor(0, 0, 0);
    delay(500);
    // can you figure our how to do this without the delay?
    // remember, you can't check for state changes when delay is active
  } else if(currentState == States::HANDOFF) {
    int a=0;{
      pixels.setPixelColor(a, pixels.Color(100, 0, 0));
    }
    int b=1;{
      pixels.setPixelColor(b, pixels.Color(100, 0, 0));
    }
    int c=2;{
      pixels.setPixelColor(c, pixels.Color(100, 0, 0));
    }
    int d=3;{
      pixels.setPixelColor(d, pixels.Color(100, 0, 0));
    }
    int e=4;{
      pixels.setPixelColor(e, pixels.Color(100, 0, 0));
    }
    int f=5;{
      pixels.setPixelColor(f, pixels.Color(100, 0, 0));
    }
    int g=6;{
      pixels.setPixelColor(g, pixels.Color(100, 0, 0));
    }
    int h=7;{
      pixels.setPixelColor(h, pixels.Color(100, 0, 0));
    }
    int i=8;{
      pixels.setPixelColor(i, pixels.Color(0, 100, 0));
    }
    int j=9;{
      pixels.setPixelColor(j, pixels.Color(0, 100, 0));
    }
    int k=10;{
      pixels.setPixelColor(k, pixels.Color(0, 100, 0));
    }
    int l=11;{
      pixels.setPixelColor(l, pixels.Color(0, 100, 0));
    }
    int m=12;{
      pixels.setPixelColor(m, pixels.Color(0, 100, 0));
    }
    int n=13;{
      pixels.setPixelColor(n, pixels.Color(0, 100, 0));
    }
    int o=14;{
      pixels.setPixelColor(o, pixels.Color(0, 100, 0));
    }
    int p=15;{
      pixels.setPixelColor(p, pixels.Color(0, 100, 0));
    }
    int q=16;{
      pixels.setPixelColor(q, pixels.Color(0, 0, 100));
    }
    int r=17;{
      pixels.setPixelColor(r, pixels.Color(0, 0, 100));
    }
    int s=18;{
      pixels.setPixelColor(s, pixels.Color(0, 0, 100));
    }
    int t=19;{
      pixels.setPixelColor(t, pixels.Color(0, 0, 100));
    }
    int u=20;{
      pixels.setPixelColor(u, pixels.Color(0, 0, 100));
    }
    int v=21;{
      pixels.setPixelColor(v, pixels.Color(0, 0, 100));
    }
    int w=22;{
      pixels.setPixelColor(w, pixels.Color(0, 0, 100));
    }
    int x=23;{
      pixels.setPixelColor(x, pixels.Color(0, 0, 100));
    }
    int y=24;{
      pixels.setPixelColor(y, pixels.Color(0, 0, 100));
    }
    pixels.show();
  }

}

void setColor(int red, int green, int blue) {
  // The first NeoPixel in a strand is #0, second is 1, all the way up
  // to the count of pixels minus one.
  for(int i=0; i<NUMPIXELS; i++) {
    // Sets the color of each individual pixel
   
    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(red, green, blue));
  }

   pixels.show();   // Send the updated pixel colors to the hardware.
}
