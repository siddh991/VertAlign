// Created by: Siddarth Surana, Ryan Tang, Majd Masoud, Stanley Wong
// Posture Monitor - Photoresistor Input (Light Detection)
// HackPrinceton 2018 Hardware Hack

int sensorValue = 0;
int sensorPin = A0;
int ledPin = 13;
int speakerPin = 2;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(speakerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  sensorValue = analogRead(sensorPin);  // Whether or not laser points at photoresistor
  Serial.println(sensorValue, DEC);
  if (sensorValue < 600) {
    digitalWrite(speakerPin, HIGH);
    delay(50);
  } else {
    digitalWrite(speakerPin, LOW);
  }
}
