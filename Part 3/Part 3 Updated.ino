/*
  Reference Tutorial:
  https://randomnerdtutorials.com/electronics-basics-how-do-rgb-leds-work/
*/

// Setup the required pin values
const int pot = A0;
const int button = 12;
const int blue = 3;
const int green = 5;
const int red = 6;

// Initialize the first color configuration: Start with red being the actively controlled LED 
// and set all LED brightness values to 255, which in the case of the RGB LED I'm using is OFF
int selectorState = 1;
int controlledColor = red;
int redBrightness = 255;
int greenBrightness = 255;
int blueBrightness = 255;

// Variables to control the button and pprogram flow
int buttonReading, buttonCheck;
bool pressEventLogged = false;

// Setup the pins
void setup() {
  Serial.begin(9600);

  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(button, INPUT);

}

void loop() {
  
  // Debounce routine copied from the assignment document
  buttonReading = digitalRead(button);
  delay(10);
  buttonCheck = digitalRead(button);

  // If the button has been pressed by a human
  if (buttonReading == buttonCheck){

    // Toggle which color is currently being controlled if the button press has not already been handled
    if(buttonCheck == 1 && !pressEventLogged){
      // 

      // Reset selectorState to 1 if it has reached a max value of 3
      (selectorState >= 3) ? selectorState = 1 : selectorState++; 

      switch(selectorState)
      {
        case 1:
          controlledColor = red;
          break;

        case 2:
          controlledColor = green;
          break;

        case 3:
          controlledColor = blue;
          break;    

        default:
          Serial.println("Color state index is out of bounds. Unable to determine controlled color");
      }
      // Flag the button press as handled
      pressEventLogged = true;

    }
    // If the button has been (or is currently) released, ensure the event logger remains false
    else if(buttonCheck == 0){
      pressEventLogged = false;
    }
  }
   
  // Handle the changing of color brightness by assigning the potentiometer value reading
  // (within a range of 0 to 255) to the appropriate color LED brightness 
  if(selectorState == 1){
    redBrightness = 255*(analogRead(pot)/1023.0);
  }
  else if (selectorState == 2){
    greenBrightness = 255*(analogRead(pot)/1023.0);
  }
  else if (selectorState == 3){
    blueBrightness = 255*(analogRead(pot)/1023.0);
  }
  else{
    Serial.println("Color state index is out of bounds. Unable to update LED brightness");
  }
  
  // Update the state of the LED color brightness
  analogWrite(red, redBrightness);
  analogWrite(green, greenBrightness);
  analogWrite(blue, blueBrightness);

}