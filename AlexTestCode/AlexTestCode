#define BUTTON_PIN 0  // GPIO pin for the push button
#define BUILTIN_LED 2  // GPIO pin for the built-in LED

// GPIO pins for the external LEDs
const int ledPins[7] = {4, 5, 13, 14, 16, 17, 18}; 

//this is setting up variables for later use
int currentDay = 0;  // Tracks the current state
bool lastButtonState = LOW;  // Tracks the last state of the button
bool currentButtonState = LOW;  // Tracks the current state of the button
unsigned long lastDebounceTime = 0;  // Last time the output pin was toggled
unsigned long debounceDelay = 50;  // Debounce time in milliseconds

// this code sets up the LED's, button and buzzer.
void setup() {
  Serial.begin(115200);  // Initialize serial communication for debugging
  Serial.println("ESP32 State Cycling Program Start");

  // This code loops through all 7 days and sets the external LED pins as outputs
  for (int i = 0; i < 7; i++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW); // Turn all external LEDs off
  }

  // Set the button and built-in LED pins
  pinMode(BUTTON_PIN, INPUT_PULLDOWN);  // Use internal pull-down resistor
  pinMode(BUILTIN_LED, OUTPUT);
  digitalWrite(BUILTIN_LED, LOW);  // Ensure the built-in LED is off initially
}

void loop() {
  //start reading if the button is pressed
  int reading = digitalRead(BUTTON_PIN);


  // If the button state has changed, due to pressing:
  if (reading != lastButtonState) {
    lastDebounceTime = millis();  // Reset the debouncing timer
  }

  // This code checks to make sure the button has stabilized and is not being pressed too fast.
  if ((millis() - lastDebounceTime) > debounceDelay) {
    // If the button state has stabilized
    if (reading != currentButtonState) {
      //this will change the button state
      currentButtonState = reading;

      // If the button is pressed, change the LED state
      if (currentButtonState == HIGH) {
        Serial.println("Button pressed");

        // Turn off the current external LED
        digitalWrite(ledPins[currentDay], LOW);

        // Increment to the next state this will not go past 6
        currentDay = (currentDay + 1) % 7;  // Cycle through 0 to 6

        // Turn on the new external LED
        digitalWrite(ledPins[currentDay], HIGH);

        // Blink the built-in LED to indicate the current state
        blinkBuiltInLED(currentDay + 1);  // +1 because states start at 0

        // Debugging: Print the current state
        Serial.print("Current State: ");
        Serial.println(currentDay + 1);
      }
    }
  }

  // Save the current state for the next loop
  lastButtonState = reading;
}

// Function to blink the built-in LED to indicate the current state
void blinkBuiltInLED(int times) {
  for (int i = 0; i < times; i++) {
    digitalWrite(BUILTIN_LED, HIGH);  // Turn the built-in LED on
    delay(200);  // Wait for 200 milliseconds
    digitalWrite(BUILTIN_LED, LOW);   // Turn the built-in LED off
    delay(200);  // Wait for 200 milliseconds
  }
}
