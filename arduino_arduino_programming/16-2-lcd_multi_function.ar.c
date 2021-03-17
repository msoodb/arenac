#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

float pressLength_milliSeconds = 0;
int optionOne_milliSeconds = 1;
int optionTwo_milliSeconds = 2000; 

int buttonPin = 6;
int ledPin_Option_1 = 13;
int ledPin_Option_2 = 10;

int mode = 0; // 0 Off, 5 Standby, 10 On
int functionality = 0; // 0 Temperature, 10 Distance, 20 Gas

// It's the pin number of the sensor's output:
const int pingPin = 7;
const int lcdPin = 9;


void setup()
{    	
  	lcd.begin(16, 2);
  
  	pinMode(buttonPin, INPUT_PULLUP); 
  
  	//set the LEDs pins as outputs
  	pinMode(ledPin_Option_1, OUTPUT);
  	pinMode(ledPin_Option_2, OUTPUT); 
  	digitalWrite(ledPin_Option_1, HIGH);
  
  	pinMode(lcdPin, OUTPUT);
  	digitalWrite(lcdPin, LOW);
}

void loop()
{ 	
	while (digitalRead(buttonPin) == LOW ){ 
		delay(100);
		pressLength_milliSeconds = pressLength_milliSeconds + 100;
    
		if (pressLength_milliSeconds > optionTwo_milliSeconds){
			break;
		}
	}
  	
	if (pressLength_milliSeconds > 0){
		switch (mode) {
		case 0:
			if ( pressLength_milliSeconds > optionTwo_milliSeconds){
				digitalWrite(lcdPin, HIGH);
				digitalWrite(ledPin_Option_2, HIGH);
				lcd.setCursor(0, 0);
				lcd.print("Power on ...");
				delay(1000);
				lcd.clear();
				mode = 10;
			}
			break;
		case 10:
			if (pressLength_milliSeconds > optionTwo_milliSeconds){
				digitalWrite(lcdPin, LOW);
				digitalWrite(ledPin_Option_2, LOW);
				lcd.setCursor(0, 0);
				lcd.print("Power off ...");
				delay(100);
				lcd.clear();
				mode = 0;
			} else if (pressLength_milliSeconds > optionOne_milliSeconds){
				lcd.setCursor(0, 0);
				lcd.print("Function Change");
				nextFunction();
				lcd.clear();
				delay(100);
			} 
			break;
		default:
			break;
		}
	}
  
	pressLength_milliSeconds = 0;
  
	if ( mode == 10){
		switch (functionality) {
		case 0:
			lcd.setCursor(0, 0);

			// Read analog input A0
			int tmpSensorInput;
			tmpSensorInput = analogRead(A0);

			//find percentage of input reading
			double tmp;
			tmp = (double)tmpSensorInput / 1024; 

			//multiply by 5V to get voltage
			tmp = tmp * 5;

			//Subtract the offset and normalize
			tmp = tmp - 0.5; 
			tmp = tmp * 100; 	

			// print tmp
			lcd.print(tmp);
			lcd.print("  ");
			lcd.print((char)223);
			lcd.print("C  ");
			break;
		case 10:
			lcd.setCursor(0, 0);

			// establish variables for duration of the ping, and the distance result
			// in inches and centimeters:
			long duration, inches, cm;

			// The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
			// Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
			pinMode(pingPin, OUTPUT);
			digitalWrite(pingPin, LOW);
			delayMicroseconds(2);
			digitalWrite(pingPin, HIGH);
			delayMicroseconds(5);
			digitalWrite(pingPin, LOW);

			// The same pin is used to read the signal from the PING))): a HIGH pulse
			// whose duration is the time (in microseconds) from the sending of the ping
			// to the reception of its echo off of an object.
			pinMode(pingPin, INPUT);
			duration = pulseIn(pingPin, HIGH);

			// convert the time into a distance
			inches = microsecondsToInches(duration);
			cm = microsecondsToCentimeters(duration);

			/* Serial.print(inches);
			   Serial.print("in, ");
			   Serial.print(cm);
			   Serial.print("cm");
			   Serial.println(); */

			delay(100); 	

			// print dist
			lcd.print(cm);
			lcd.print(" cm     ");
			break;
		default:
			break;
		}
	}
}

int nextFunction(){
	functionality += 10;
	if (functionality > 30) functionality = 0;
}

long microsecondsToInches(long microseconds) {
	// According to Parallax's datasheet for the PING))), there are 73.746
	// microseconds per inch (i.e. sound travels at 1130 feet per second).
	// This gives the distance travelled by the ping, outbound and return,
	// so we divide by 2 to get the distance of the obstacle.
	// See: http://www.parallax.com/dl/docs/prod/acc/28015-PING-v1.3.pdf
	return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
	// The speed of sound is 340 m/s or 29 microseconds per centimeter.
	// The ping travels out and back, so to find the distance of the object we
	// take half of the distance travelled.
	return microseconds / 29 / 2;
}
