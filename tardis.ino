#include "SoftwareSerial.h"
#include <Wtv020sd16p.h>

unsigned long previousMillis = 0;
const long interval = 30;



int fadeValue = 0;
int randNumber;
int fadeIncrement = 1;
int resetPin = 6;  // The pin number of the reset pin.
int clockPin = 5;  // The pin number of the clock pin.
int dataPin = 4;  // The pin number of the data pin.
int busyPin = 3;  // The pin number of the busy pin.
int ledPin = 9;
unsigned long play = 0;
unsigned long play2 = 0;

Wtv020sd16p wtv020sd16p(resetPin,clockPin,dataPin,busyPin);

void setup() {
//Initializes the module.
Serial.begin(115200); // set up Serial library at 115200 bps
Serial.println("Serial init complete");
//wtv020sd16p.reset();
  // set up the randomizer
  //randomSeed(analogRead(0));
  // choose a random number between 0 and 10
  randNumber = random(17);

}

void loop() {


	Serial.println("Tardis Landing...");
	wtv020sd16p.reset();
	delay(200);
	//int play;
	wtv020sd16p.asyncPlayVoice(1);
    while (play < 40450){
       	play = play + 1;
    	Serial.println(String(play));
    	fadelight();
    }
    analogWrite(ledPin, 0);
    fadeValue = 0;
    wtv020sd16p.stopVoice();
/*
    Serial.println("Tardis Starting...");
    //wtv020sd16p.stopVoice();
    delay(5000);
    //wtv020sd16p.reset();
    delay(200);
    wtv020sd16p.asyncPlayVoice(3);
    while (play2 < 40500){
           	play2 = play2 + 1;
        	Serial.println(String(play2));
        	fadelight();
    }
    analogWrite(ledPin, 0);
    fadeValue = 0;
*/
//delay(5000);
    	//	wtv020sd16p.asyncPlayVoice(1);

   // Serial.println("Play 1");
    //wtv020sd16p.playVoice(1);
   // delay(23000);
   // Serial.println("Play 2");
    //wtv020sd16p.playVoice(2);
    //delay(23000);
    //wtv020sd16p.stopVoice();

    // check to see if enough time in millis has passed
}
    void fadelight() {
    unsigned long currentMillis = millis();
    if(currentMillis - previousMillis >= interval) {
        previousMillis = currentMillis;

         // if the value gets to 100 then we need to reverse and fade it out
         if (fadeValue == 150) {
        	 Serial.println("-1");
          fadeIncrement = -10;
          }

         // if the value drops to 0 then make it start getting brighter
         if (fadeValue == 0) {
          fadeIncrement = 5;
          Serial.println("1");

         }

        // increment the fade value
          fadeValue = fadeValue + fadeIncrement;
          Serial.println("fadeVal: "+String(fadeValue));

    }

      // set the LED brightness to the new fade value

      analogWrite(ledPin, fadeValue);
    }
