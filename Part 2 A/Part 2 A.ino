/*
  Reference material: 
  ReadAnalogVoltage
  https://www.arduino.cc/en/Tutorial/BuiltInExamples/ReadAnalogVoltage
*/

 /* Blink parameters: 
    A "Very slow" blink rate will change between ON and OFF every 1 second
    A "Very fast" blink rate will change every 100 ms
*/
int slowBlink = 1000;
int fastBlink = 100; 

// Variables used to read from the pot and set the blink speed
int blinkRate, potValue; 

// Potentiometer is connected to A0, the LED to pin 13
int POT_PIN = 14;
int LED_PIN = 13;

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {

  // Read the current value at pin A0 (14)
  potValue = analogRead(POT_PIN);

  // Map the current potentiometer reading (0 to 1023) to a blink speed ("slow" to "fast" as declared above)
  blinkRate = map(potValue, 0, 1023, slowBlink, fastBlink);
  
  // Blink the LED at the appropriate delay speed
  digitalWrite(LED_PIN, HIGH);
  delay(blinkRate);
  digitalWrite(LED_PIN, LOW);
  delay(blinkRate);

}