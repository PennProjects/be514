
//1d Portemtiometer controlled servo


// define switch and led pins
int pot_pin = 0;
int pot_value = 0;



// the setup routine runs once when you press reset:
void setup() {
  
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
 

}

// the loop routine runs over and over again forever:
void loop() {

  //Read value fro Potentiometer
  pot_value = analogRead(pot_pin);
  Serial.println(pot_value);
  delay(1);

}
