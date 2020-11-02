//2a
//Using a flex sensor as a switch
//Everytime the flexx is bent to about 90 deg it switches on/off the led

//Input from Flex sensor
const int flexPin = A0;      

// to calculate resistance of the flex sensor
const float VCC = 5;      
const float R_DIV = 10000.0;  // resistor used to create a voltage divider
const float flatResistance = 12000.0; // resistance when flat
const float bendResistance = 50000.0;  // resistance at 90 deg

int flex_switch;

//to make the sensor a switch
int flex_state = LOW;      // the current state of the output pin
int flex_previous = HIGH;    // the previous reading from the input pin

int led_pin = 3;


// to prevent debouncing
long time = 0;         
long debounce = 200; 


void setup() {
  Serial.begin(9600);
  pinMode(flexPin, INPUT);
  pinMode(led_pin, OUTPUT);
}

void loop() {
  
  // Read the ADC, and calculate voltage and resistance from it
  int ADCflex = analogRead(flexPin);
  float Vflex = ADCflex * VCC / 1023.0;
  float Rflex = R_DIV * (VCC / Vflex - 1.0);
  Serial.println("Resistance: " + String(Rflex) + " ohms");

  // Use the calculated resistance to estimate the sensor's bend angle:
  float angle = map(Rflex, flatResistance, bendResistance, 0, 100.0);

  //set flex switch outpu
  if (angle > 90)
    flex_switch = HIGH;
  else
    flex_switch = LOW;

  if(flex_switch ==HIGH && flex_previous ==LOW && millis() -time >debounce){
    if(flex_state ==HIGH)
      flex_state = LOW;
    else
      flex_state = HIGH;
      
    time = millis();
  }

  digitalWrite(led_pin, flex_state);

  flex_previous = flex_switch;
  
  Serial.println("Bend: " + String(angle) + " degrees");
  Serial.println();

  delay(100);
}
