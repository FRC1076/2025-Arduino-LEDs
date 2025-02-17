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


String state; // state the robot is in

void setup() {
  // the line below this should change based on which state you want to test
  // options are "empty", "holding", and "handoff"
  state = "holding";

 
  /* IGNORE THE LINES BELOW
  These lines are specifically to support the Adafruit Trinket 5V 16 MHz.
  Any other board, you can remove this part (but no harm leaving it): */
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  // END of Trinket-specific code.

  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
}

void loop() {
  // check the state the robot is in and display the corresponding color
  if(state.equals("empty")) {
    // solid purple
    setColor(50, 0, 100);
  } else if(state.equals("holding")) {
    // flashing brighter purple
    setColor(100, 0, 200);
    delay(500);
    setColor(0,0,0);
    delay(500);
    // can you figure our how to do this without the delay?
    // remember, you can't check for state changes when delay is active
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
