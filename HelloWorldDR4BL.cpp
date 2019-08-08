#include <Arduino.h>

int leftPinINA = 12;
int leftPinINB = 11;
int rightPinINA = 9;
int rightPinINB = 8;

int BUTTON = 7;

bool robotReady = false;

void setup() {

	pinMode(leftPinINA, OUTPUT);
	pinMode(leftPinINB, OUTPUT);
	pinMode(rightPinINA, OUTPUT);
	pinMode(rightPinINB, OUTPUT);

	pinMode(BUTTON, INPUT_PULLUP);

	//pinMode(13, OUTPUT);
}

void loop() {

	if(digitalRead(BUTTON) == LOW){
		robotReady = true;
	}

	if(robotReady){
		analogWrite(leftPinINA, 127);
		analogWrite(rightPinINB, 127);
		delay(1000);
		analogWrite(leftPinINA, 0);
		analogWrite(rightPinINB, 0);

		robotReady = false;
		digitalWrite(13, 0);
		delay(1000);
		digitalWrite(13, 1);
		delay(1000);
	}

}

