// Created by: Siddarth Surana, Ryan Tang, Majd Masoud, Stanley Wong
// Posture Monitor - Tilt Switch Input
// HackPrinceton 2018 Hardware Hack

#include <dht.h>

dht DHT;

#define DHT11_PIN 13

int tiltPin = 7;      // pin number for tilt switch signal 
int tiltPin2 = 8;
int tiltPin3 = 9;
int speakerPin =  2;     // pin number of LED 
int tiltState = 0;
int tiltState2 = 0;
int tiltState3 = 0;
int loopnum = 0;
int chk = 0;
int before = 0;
int after = 0;
// 1 when bad, 0 when good
// variable for reading the tilt switch status

void setup() {   
  pinMode(tiltPin, INPUT);  // set the tilt switch pin as input
  pinMode(tiltPin2, INPUT);
  pinMode(tiltPin3, INPUT);
  pinMode(speakerPin, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  //get temp/hum
  chk = DHT.read11(DHT11_PIN);
  if ((loopnum % 5 == 0) && (DHT.temperature < 400) && (DHT.humidity < 100) && (DHT.humidity > 0)) {
    Serial.print("Current humidity = ");
    Serial.print(DHT.humidity);
    Serial.print("%  ");
    Serial.print("temperature = ");
    Serial.print(DHT.temperature); 
    Serial.println("C  ");
  }
 
  // get the tilt switch state
  tiltState = digitalRead(tiltPin);
  tiltState2 = digitalRead(tiltPin2);
  tiltState3 = digitalRead(tiltPin3);

  // check if tilt switch is tilted.
  if (tiltState == HIGH) {
    after = 1;
    pinMode(speakerPin, OUTPUT);
    if (before != after) {
      Serial.println("Bad posture area 1!");
      digitalWrite(speakerPin, LOW);
      digitalWrite(speakerPin, HIGH);
      delay(50);    
    }
    before = after;
  } else if (tiltState2 == HIGH) {
    after = 2;
    pinMode(speakerPin, OUTPUT);
    if (before != after) {
      Serial.println("Bad posture area 2!");
      digitalWrite(speakerPin, LOW);
      digitalWrite(speakerPin, HIGH);
      delay(50);
    }
    before = after;
  } else if (tiltState3 == HIGH) {
    after = 3;
    pinMode(speakerPin, OUTPUT); 
    if (before != after) {
      Serial.println("Bad posture area 3!");
      digitalWrite(speakerPin, LOW);
      digitalWrite(speakerPin, HIGH);
      delay(50);
    }
    before = after;   
  } else {
    after = 0;
    pinMode(speakerPin, INPUT);
    if (before != after) { 
      Serial.println("Good posture!");
    }
    before = after;
  }
  delay(750);
  ++loopnum;
}
