// Demo program for testing library and board - flip the switch to turn on/off buzzer

#include <Adafruit_CircuitPlayground.h>
#include <Wire.h>
#include <SPI.h>

void setup() {
  Serial.begin(9600);
  Serial.println("Circuit Playground test!");

  CircuitPlayground.begin();
  CircuitPlayground.setAccelRange(LIS3DH_RANGE_2_G);
}


void loop() {
  get_shakey();
  check_shakey();
  // output
}

float X,Y,Z;

void get_shakey() {
  // Sanity check
  CircuitPlayground.redLED(HIGH);
  delay(100);
  CircuitPlayground.redLED(LOW);
  delay(100);
  // Read Input
  X = CircuitPlayground.motionX();
  Y = CircuitPlayground.motionY();
  Z = CircuitPlayground.motionZ();

  // Generate feedback
  uint32_t Xc = (int)(1000 * CircuitPlayground.motionX()) % 256;
  uint32_t Yc = (int)(1000 * CircuitPlayground.motionY()) % 256;
  uint32_t Zc = (int)(1000 * CircuitPlayground.motionZ()) % 256;


  CircuitPlayground.setPixelColor(7,Xc,Yc,Zc);
  CircuitPlayground.setPixelColor(8,Zc,Xc,Yc);
  CircuitPlayground.setPixelColor(9,Yc,Zc,Xc);
}

// part 2
float delta;
float threshold = 6;
int tick_threshold = 2;
int ticks = 0;
bool rolled = false;

void check_shakey() {
  delta = (abs(X) + abs(Y) + abs(Z)) / 3;

  // Check if should roll dice.
  if (delta > threshold) {
    // feedback on threshold value being correctly tuned 
    CircuitPlayground.setPixelColor(9,255,0,0);
    if (ticks++ > tick_threshold && !rolled) {
      CircuitPlayground.setPixelColor(8,0,255,0);
      rolled = true;

      // handle dice roll
      roll_dice();
    }
  } else {
    // don't forget to reset
    CircuitPlayground.setPixelColor(9,0,0,0);
    CircuitPlayground.setPixelColor(8,0,0,0);
    ticks = 0;
    rolled = false;
  }
}

//part 3
int no_sides = 6;

void roll_dice() {
  // clear last roll
  int i;
  for (i = 0; i < 5; i++) {
    CircuitPlayground.setPixelColor(i,0,0,0);
  }

  
  // use delta for random input.
  int dice_no = 1 + ((int)(delta * 1000) % (no_sides));
  Serial.print("Rolled:"); Serial.println(dice_no);
  
  // calculate output
  for (i = 0; i < dice_no; i++) {
      CircuitPlayground.setPixelColor(i,128,128,128);
  }
}
