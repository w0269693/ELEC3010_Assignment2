int pushButton = 2; // Button is connected to pin 2
int pressCounter = 0; // Used to track the number of total button presses
int reading1, reading2; // Used for debounce routine
bool pressEventLogged = false; // Used to register and report each button press only once

void setup() {
  Serial.begin(9600);
  pinMode(pushButton, INPUT);
}

void loop() {
  
  // Debounce routine copied from the assignment document
  reading1 = digitalRead(pushButton);
  delay(10);
  reading2 = digitalRead(pushButton);

  // If the button has been pressed or released by a human
  if (reading1 == reading2) {
    // If the button is currently pressed and the event has not been logged
    if(reading2 == 1 && !pressEventLogged){
      // Increment the counter, report the event, and flag it as logged
      pressCounter++;
      Serial.print("You\'ve pressed the button "); Serial.print(pressCounter); Serial.println(" times");
      pressEventLogged = true;
    }
    // Otherwise, if the button has been (or is currently) NOT pressed, ensure the event logger is set to false
    else if(reading2 == 0){
      pressEventLogged = false;
    }
  }

}