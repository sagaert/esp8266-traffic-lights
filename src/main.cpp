#include <Arduino.h>

const int PUSH_BUTTON = D0;

const int CAR_LED_RED = D1;
const int CAR_LED_YELLOW = D2;
const int CAR_LED_GREEN = D3;

const int PED_LED_RED = D5;
const int PED_LED_GREEN = D6;

const int PED_LED_FEEDBACK = D7;

void setup() {
  Serial.begin(9600);
  
  pinMode(PUSH_BUTTON, INPUT);
  pinMode(CAR_LED_RED, OUTPUT);
  pinMode(CAR_LED_YELLOW, OUTPUT);
  pinMode(CAR_LED_GREEN, OUTPUT);
  pinMode(PED_LED_FEEDBACK, OUTPUT);
  pinMode(PED_LED_RED, OUTPUT);
  pinMode(PED_LED_GREEN, OUTPUT);

  digitalWrite(CAR_LED_RED, LOW);
  digitalWrite(CAR_LED_YELLOW, LOW);
  digitalWrite(CAR_LED_GREEN, HIGH);
  digitalWrite(PED_LED_FEEDBACK, LOW);
  digitalWrite(PED_LED_RED, HIGH);
  digitalWrite(PED_LED_GREEN, LOW);

}

void loop() {
  if(digitalRead(PUSH_BUTTON) == HIGH) {
    // Start program
    Serial.println("Pedestrian wants to cross the road");
    for(int i= 0; i < 5; i++) {
      digitalWrite(PED_LED_FEEDBACK, HIGH);
      delay(500);
      digitalWrite(PED_LED_FEEDBACK, LOW);
      delay(500);
    }
    Serial.println("Stopping the cars");
    digitalWrite(CAR_LED_GREEN, LOW);
    digitalWrite(CAR_LED_YELLOW, HIGH);
    for(int i= 0; i < 2; i++) {
      digitalWrite(PED_LED_FEEDBACK, HIGH);
      delay(500);
      digitalWrite(PED_LED_FEEDBACK, LOW);
      delay(500);
    }
    digitalWrite(CAR_LED_YELLOW, LOW);
    digitalWrite(CAR_LED_RED, HIGH);
    Serial.println("Cars stopped");
    for(int i= 0; i < 2; i++) {
      digitalWrite(PED_LED_FEEDBACK, HIGH);
      delay(500);
      digitalWrite(PED_LED_FEEDBACK, LOW);
      delay(500);
    }
    digitalWrite(PED_LED_RED, LOW);
    digitalWrite(PED_LED_GREEN, HIGH);
    Serial.println("Go pedestrian, GO !!!");
    delay(5000);
    Serial.println("Hope, you made it to the other side");
    digitalWrite(PED_LED_RED, HIGH);
    digitalWrite(PED_LED_GREEN, LOW);
    delay(3000);
    Serial.println("Hey, cars prepare to start");
    digitalWrite(CAR_LED_YELLOW, HIGH);
    delay(3000);
    Serial.println("Phu, the program is finished :-)");
    digitalWrite(CAR_LED_RED, LOW);
    digitalWrite(CAR_LED_YELLOW, LOW);
    digitalWrite(CAR_LED_GREEN, HIGH);
  }
}