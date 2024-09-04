#include <FastLED.h>
#define NUM_LEDS 24
#define DATA_PIN 23
#define CLOCK_PIN 22
int infrarrojo=15;
int valor=0;
CRGB leds[NUM_LEDS];

unsigned char i;
unsigned char m;
unsigned int wait = 100;
unsigned int wait2 = 1000;
bool hall = 1;
bool S[8][7] = {

{1,1,1,1,1,1,1},
{0,0,0,0,0,0,1},
{0,0,0,0,0,0,1},
{0,0,0,0,0,0,1},
{1,1,1,1,1,1,1},
{1,0,0,0,0,0,0},
{1,0,0,0,0,0,0},
{1,1,1,1,1,1,1},

};

bool E[8][7] = {

{1,1,1,1,1,1,1},
{0,0,0,0,0,0,1},
{0,0,0,0,0,0,1},
{0,0,0,0,0,0,1},
{1,1,1,1,1,1,1},
{0,0,0,0,0,0,1},
{0,0,0,0,0,0,1},
{1,1,1,1,1,1,1},
};
bool P[8][7] = {
  

{1,1,1,1,1,1,1},
{1,0,0,0,0,0,1},
{1,0,0,0,0,0,1},
{1,0,0,0,0,0,1},
{1,1,1,1,1,1,1},
{0,0,0,0,0,0,1},
{0,0,0,0,0,0,1},
{0,0,0,0,0,0,1},
  
};

bool T[8][7] = {

{1,1,1,1,1,1,1},
{0,0,0,1,0,0,0},
{0,0,0,1,0,0,0},
{0,0,0,1,0,0,0},
{0,0,0,1,0,0,0},
{0,0,0,1,0,0,0},
{0,0,0,1,0,0,0},
{0,0,0,1,0,0,0},

};
bool I[8][7] = {

{1,1,1,1,1,1,1},
{0,0,0,1,0,0,0},
{0,0,0,1,0,0,0},
{0,0,0,1,0,0,0},
{0,0,0,1,0,0,0},
{0,0,0,1,0,0,0},
{0,0,0,1,0,0,0},
{1,1,1,1,1,1,1},

};
bool M[8][7] = {

{1,1,0,0,0,1,1},
{1,0,1,0,1,0,1},
{1,0,0,1,0,0,1},
{1,0,0,0,0,0,1},
{1,0,0,0,0,0,1},
{1,0,0,0,0,0,1},
{1,0,0,0,0,0,1},
{1,0,0,0,0,0,1},

};
bool O[8][7] = {

{1,1,1,1,1,1,1},
{1,0,0,0,0,0,1},
{1,0,0,0,0,0,1},
{1,0,0,0,0,0,1},
{1,0,0,0,0,0,1},
{1,0,0,0,0,0,1},
{1,0,0,0,0,0,1},
{1,1,1,1,1,1,1},

};

void setup(){
  Serial.begin(9600);
  FastLED.addLeds<APA102, DATA_PIN, CLOCK_PIN, BGR>(leds, NUM_LEDS);
  pinMode(infrarrojo, INPUT);


}


void loop(){
  valor= digitalRead(infrarrojo);
  if(valor==LOW){

    for (m = 0; m < 7; m++) {
      for (i = 0; i < 8; i++) {
        if (O[i][m] == 1) {
          leds[i + 11] = CRGB::Red;
        }
        else {
          leds[i + 11] = CRGB::Black;
        }
      }
      FastLED.show();
      delayMicroseconds(wait);
    }

    for (int i = 0; i < 24; i++) {
      leds[i] = CRGB ::Black;
    }
    FastLED.show();
    delayMicroseconds(wait2);

    for (m = 0; m < 7; m++) {
      for (i = 0; i < 8; i++) {
        if (M[i][m] == 1) {
          leds[i + 11] = CRGB::Green;
        }
        else {
          leds[i + 11] = CRGB::Black;
        }
      }
      FastLED.show();
      delayMicroseconds(wait);
    }

    for (int i = 0; i < 24; i++) {
      leds[i] = CRGB ::Black;
    }
    FastLED.show();
    delayMicroseconds(wait2);

    for (m = 0; m < 7; m++) {
      for (i = 0; i < 8; i++) {
        if (I[i][m] == 1) {
          leds[i + 11] = CRGB::Yellow;
        }
        else {
          leds[i + 11] = CRGB::Black;
        }
      }
      FastLED.show();
      delayMicroseconds(wait);
    }

    for (int i = 0; i < 24; i++) {
      leds[i] = CRGB ::Black;
    }
    FastLED.show();
    delayMicroseconds(wait2);

     for (m = 0; m < 7; m++) {
      for (i = 0; i < 8; i++) {
        if (T[i][m] == 1) {
          leds[i + 11] = CRGB::Blue;
        }
        else {
          leds[i + 11] = CRGB::Black;
        }
      }
      FastLED.show();
      delayMicroseconds(wait);
    }

    for (int i = 0; i < 24; i++) {
      leds[i] = CRGB ::Black;
    }
    FastLED.show();
    delayMicroseconds(wait2);

     for (m = 0; m < 7; m++) {
      for (i = 0; i < 8; i++) {
        if (P[i][m] == 1) {
          leds[i + 11] = CRGB::Orange;
        }
        else {
          leds[i + 11] = CRGB::Black;
        }
      }
      FastLED.show();
      delayMicroseconds(wait);
    }

    for (int i = 0; i < 24; i++) {
      leds[i] = CRGB ::Black;
    }
    FastLED.show();
    delayMicroseconds(wait2);

     for (m = 0; m < 7; m++) {
      for (i = 0; i < 8; i++) {
        if (E[i][m] == 1) {
          leds[i + 11] = CRGB::Purple;
        }
        else {
          leds[i + 11] = CRGB::Black;
        }
      }
      FastLED.show();
      delayMicroseconds(wait);
    }

    for (int i = 0; i < 24; i++) {
      leds[i] = CRGB ::Black;
    }
    FastLED.show();
    delayMicroseconds(wait2);

     for (m = 0; m < 7; m++) {
      for (i = 0; i < 8; i++) {
        if (S[i][m] == 1) {
          leds[i + 11] = CRGB::White;
        }
        else {
          leds[i + 11] = CRGB::Black;
        }
      }
      FastLED.show();
      delayMicroseconds(wait);
    }

    for (int i = 0; i < 24; i++) {
      leds[i] = CRGB ::Black;
    }
    FastLED.show();
    delayMicroseconds(wait2);

   
    for (int i = 11; i < 17; i++) {
      leds[i] = CRGB ::Red;
    }
    leds[18] = CRGB::Red;
    FastLED.show();
    delayMicroseconds(wait);

    for (int i = 0; i < 24; i++) {
      leds[i] = CRGB ::Black;
    }
    FastLED.show();
    delayMicroseconds(wait2);
    hall = 1;
  }
}
