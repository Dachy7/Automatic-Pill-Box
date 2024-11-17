#include <Arduino.h>
//here we must define the pins for the button and board LED
#define BUTTON_PIN 0   // GPIO pin for the push button
#define BUZZER 2  // GPIO pin for the built-in LED

// GPIO pins for the external LEDs
//This is an array that defines the LED pins
const int ledPins[14] = { 32, 22, 33, 21, 25, 19, 26, 18, 27, 17, 12, 16, 13, 4}; 

//this is setting up variables for later use
int currentDay = 0;  // Tracks the current state
bool lastButtonState = HIGH;  // Tracks the last state of the button
bool currentButtonState;  // Tracks the current state of the button
int numLEDs=14;
int buzzDelay = 50;



  void beepBuzzer(int i){
    for(int j = 0; j < i; j++){
    digitalWrite(BUZZER,HIGH);
    delay(buzzDelay);
    digitalWrite(BUZZER,LOW);
    delay(buzzDelay);
    }
  }
// this code sets up the LED's, button and buzzer.
void setup() {

  while(currentDay < 14){
pinMode(ledPins[currentDay],OUTPUT);
currentDay = currentDay + 1;
  }


currentDay=0;

pinMode(BUZZER,OUTPUT);

pinMode(BUTTON_PIN,INPUT_PULLUP);

digitalWrite(ledPins[currentDay],HIGH);


}

void loop() {
currentButtonState = digitalRead(BUTTON_PIN); 

if(currentButtonState == LOW && lastButtonState == HIGH){
//Change LED
digitalWrite( ledPins[currentDay],LOW );

currentDay = currentDay + 1;
if(currentDay == 14){
  currentDay = 0;
}

digitalWrite(ledPins[currentDay],HIGH);

//Set off buzzer
beepBuzzer(5);


delay(200);
}
lastButtonState = currentButtonState;

  }





