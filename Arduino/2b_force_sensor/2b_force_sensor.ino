//2b
//Using a Force sensor as a switch
//Everytime the FSR is pressed it switches on/off the led

//Input from Force sensor
const int forcePin = A1;      


int force_switch;

//to make the sensor a switch
int force_state = LOW;      // the current state of the output pin
int force_previous = HIGH;    // the previous reading from the input pin

int led_pin = 3;


// to prevent debouncing
long time = 0;         
long debounce = 200; 


void setup() {
  Serial.begin(9600);
  pinMode(led_pin, OUTPUT);
}

void loop() {
  
  // Read the A0 to get FSR reading
  int force_reading = analogRead(forcePin);
  Serial.println("Force: " + String(force_reading) );

  //Control outour for a gentle press
  if (force_reading > 360)
    force_switch = HIGH;
  else
    force_switch = LOW;

  if(force_switch ==HIGH && force_previous ==LOW && millis() -time >debounce){
    if(force_state ==HIGH)
      force_state = LOW;
    else
      force_state = HIGH;
      
    time = millis();
  }

  digitalWrite(led_pin, force_state);

  force_previous = force_switch;

  delay(100);
}
