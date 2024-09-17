//here we must define the pins for the button and board LED
#define BUTTON_PIN   // GPIO pin for the push button
#define BUILTIN_LED   // GPIO pin for the built-in LED

// GPIO pins for the external LEDs
//This is an array that defines the LED pins
const int ledPins[?] = {?,?}; 

//this is setting up variables for later use
int currentDay = ;  // Tracks the current state
bool lastButtonState = ;  // Tracks the last state of the button
bool currentButtonState = ;  // Tracks the current state of the button
unsigned long lastDebounceTime = 0;  // Last time the output pin was toggled
unsigned long debounceDelay = 50;  // Debounce time in milliseconds

// this code sets up the LED's, button and buzzer.
void setup() {
  // Initialize serial communication for debugging


  // This code loops through all 7 days and sets the external LED pins as outputs


  // Set the button and built-in LED pins

}

void loop() {
// here we need to accomplish the following tasks: check if button is pressed, update the led, blink the main LED and later start the buzzer. 
  }

// Function to blink the built-in LED to indicate the current state
void blinkBuiltInLED(int times) {
//here we must use a loop to blink the LED a certain number of times.
}
