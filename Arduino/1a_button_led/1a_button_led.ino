
//In this code a button is connected betweem Pin 2 and ground in pull-up mode
//And an LED is connected between pin 8 and ground
//When the button is pressed, the LED should light up

// define button and led pins
int pushButton = 2;
int led = 8;


// the setup routine runs once when you press reset:
void setup() {
  
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  
  //configure pin 2 as an input and enable the internal pull-up resistor
  pinMode(pushButton, INPUT_PULLUP);
  // configure pin 8 as an output for the LED
  pinMode(led, OUTPUT);
  
}

// the loop routine runs over and over again forever:
void loop() {
  //read the input pin:
  int buttonState = digitalRead(pushButton);
  //print out the state of the button:
  Serial.println(buttonState);

  //Use the state of the button to triger the LED
  //As we use pull up mode, the pin is high by default
  //So, Low = button off, high  = button on
  if (buttonState == HIGH) {
    digitalWrite(led, LOW);
  } else {
    digitalWrite(led, HIGH);
  }
}
