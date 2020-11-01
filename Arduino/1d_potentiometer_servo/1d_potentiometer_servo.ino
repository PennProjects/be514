
//1d Portemtiometer controlled servo
//In this code the turn of the potentiometer is used to control the angle of a servo

#include <Servo.h>

// define potentiometer and servo pins
int pot_pin = 0;
int pot_value = 0;
int servo_pin = 9;

//Create Servo object
Servo servo_motor;


// the setup routine runs once when you press reset:
void setup() {
  
  //Set the servo control pin
  servo_motor.attach(servo_pin);

}

// the loop routine runs over and over again forever:
void loop() {

  //Read value from Potentiometer
  pot_value = analogRead(pot_pin);
  
  //map Pot value from 0-1023 to 0-180 deg
  pot_value = map(pot_value, 0,1023,0,180);

  //send the values to the servo
  servo_motor.write(pot_value);
  delay(10);

}
