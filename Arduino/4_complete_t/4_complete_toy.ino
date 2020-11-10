//4
//2 sensor led switch

//Input from Force sensor
const int flexPin = A0;   
const int forcePin = A1;      




// to calculate resistance of the flex sensor
const float VCC = 5;      
const float R_DIV = 10000.0;  // resistor used to create a voltage divider
const float flatResistance = 12000.0; // resistance when flat
const float bendResistance = 40000.0;  // resistance at 90 deg

int flex_switch;
int force_switch;



//to make the sensor a switch
int flex_state = LOW;      // the current state of the output pin
int flex_previous = HIGH;    // the previous reading from the input pin

//to make the sensor a switch
int force_state = LOW;      // the current state of the output pin
int force_previous = HIGH;    // the previous reading from the input pin

//to make the sensor a switch
int state = LOW;      // the current state of the output pin
int previous = HIGH;    // the previous reading from the input pin

int led_pin = 3;


// to prevent debouncing
long time = 0;         
long debounce = 200; 


void setup() {
  Serial.begin(9600);
  pinMode(led_pin, OUTPUT);
}

void loop() {



    // Read the ADC, and calculate voltage and resistance from it
  int ADCflex = analogRead(flexPin);
  float Vflex = ADCflex * VCC / 1023.0;
  float Rflex = R_DIV * (VCC / Vflex - 1.0);
  Serial.println("Resistance: " + String(Rflex) + " ohms");

  // Use the calculated resistance to estimate the sensor's bend angle:
  float angle = map(Rflex, flatResistance, bendResistance, 0, 90.0);

  //set flex switch outpu
  if (angle > 80)
    flex_switch = HIGH;
  else
    flex_switch = LOW;






  
  
  // Read the A1 to get FSR reading
  int force_reading = analogRead(forcePin);
//  Serial.println("Force: " + String(force_reading) );

  //Control outour for a gentle press
  if (force_reading > 360)
    force_switch = HIGH;
  else
    force_switch = LOW;


    

    if((force_switch ==HIGH || flex_switch == HIGH)  && previous ==LOW && millis() -time >debounce){
      if(state==HIGH)
        state = LOW;
      else
        state = HIGH;
      
      time = millis();
  }

  digitalWrite(led_pin, state);

  previous = force_state||flex_switch;

  delay(100);
}
