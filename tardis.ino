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
unsigned long play3 = 0;

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

	play = 0;
	play2 = 0;
	play3 = 0;


	Serial.println("Tardis Landing...");
	wtv020sd16p.reset();
	delay(200);
	//int play;
	//wtv020sd16p.asyncPlayVoice(1);
	wtv020sd16p.playVoice(1);
    while (play < 868){
       	play = play + 1;
    	//Serial.println(String(play));
    	fadelight();
    	delay(30);
    }
    analogWrite(ledPin, 0);
    fadeValue = 0;
    wtv020sd16p.stopVoice();



    Serial.println("Tardis Starting...");
    wtv020sd16p.stopVoice();
    delay(5000);
    wtv020sd16p.reset();
    Serial.println("Sachen tut");
    delay(200);
    wtv020sd16p.playVoice(2);
    while (play2 < 933){
           	play2 = play2 + 1;
        	//Serial.println(String(play2));
        	fadelight();
        	delay(30);
    }
    analogWrite(ledPin, 0);
    fadeValue = 0;


    Serial.println("Tardis Humming...");
        wtv020sd16p.stopVoice();
        delay(5000);
        wtv020sd16p.reset();
        Serial.println("Sachen tut2");
        delay(200);
        wtv020sd16p.playVoice(3);
        while (play3 < 600){
               	play3 = play3 + 1;
            	//Serial.println(String(play2));
            	fadelight();
            	delay(30);
        }
        analogWrite(ledPin, 0);
        fadeValue = 0;


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
