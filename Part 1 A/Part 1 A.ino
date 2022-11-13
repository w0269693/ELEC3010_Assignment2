// Pins 4 through 13 are used to control the 10 LEDs
const int LOWER_PIN = 4;
const int UPPER_PIN = 13;

// Time delay between ON and OFF states for each blink event is 50ms
const int BLINK_DELAY = 50;

void setup() {
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
}

// Turn LED at the pin location passed ON and OFF with a short delay
void cylonScan(int pinNumber) {
  digitalWrite(pinNumber, HIGH);
  delay(BLINK_DELAY);
  digitalWrite(pinNumber, LOW);
  delay(BLINK_DELAY);
}

void loop() {

  int i;

  // Blink the LEDs in sequence from lower to upper bounds
  for (i = LOWER_PIN; i <= UPPER_PIN; i++) {
    cylonScan(i);
  }

  // Blink the LEDs in sequence from upper to lower bounds
  for (i = UPPER_PIN; i >= LOWER_PIN; i--) {
    cylonScan(i);
  }
}