/*
Reference Material:
  - PWM Fade 
    https://www.arduino.cc/en/Tutorial/BuiltInExamples/Fade
  - Using a light dependent resistor 
    https://create.arduino.cc/projecthub/electronicsfan123/interfacing-arduino-uno-with-ldr-8760ba
*/

const int LED = 11; // the PWM pin the LED is attached to
const int LDR = A0; // the pin the LDR is attached to
int brightness = 0; // how bright the LED is/will be
int fadeAmount = 5; // how many points to fade the LED by each itteration
int ldrStatus;  // used to read the current voltage at the point between the LDR and resistor

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT); // declare the LED pin an output
  pinMode(LDR, INPUT);  // declare the LDR pin an input
}

void loop() {

  // Take a reading from the LDR and report status to the Serial Monitor
  ldrStatus = analogRead(LDR);
  Serial.print("Current LDR reading: ");Serial.println(ldrStatus);
  Serial.print("Current brightness: ");Serial.println(brightness);Serial.println();
  
  // If the LDR reading falls below 10 (based on my circuit configuration and the room lighting)
  if(ldrStatus < 10){
    // Fade in if the LED isn't already at max setting
    if(brightness < 255){
      brightness = brightness + fadeAmount;
    }
    analogWrite(LED, brightness);
  }
  else{
    // Otherwise fade out unless the LED is already off
    if(brightness > 0){
      brightness = brightness - fadeAmount;
    }
    analogWrite(LED, brightness);
  }

  // Delay 850 ms so the entire fade process takes ~60 seconds in total
  delay(850);
}