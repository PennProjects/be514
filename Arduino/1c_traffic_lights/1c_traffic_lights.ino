
//1c Traffic lights
//In this code the green light turnson for 3s then the yellow for 2s and then red for 4s
//When the green light turns on, "GO" ia printed 
//and when red light turns on, "STOP" is printed onto the serial monitor.

// define switch and led pins
int red_led = 8;
int yellow_led = 9;
int green_led = 10;

//Define the wait durations in ms for each color
int red_wait = 4000;
int yellow_wait = 2000;
int green_wait = 3000;


// the setup routine runs once when you press reset:
void setup() {
  
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
 
  // configure pin 8,9 and 10 as an output for the leds red, yellow and green respectively
  pinMode(red_led, OUTPUT);
  pinMode(yellow_led, OUTPUT);
  pinMode(green_led, OUTPUT);
  
}

// the loop routine runs over and over again forever:
void loop() {

  // Turn on green and wait for 3s
  digitalWrite(red_led, LOW);
  digitalWrite(yellow_led, LOW);
  digitalWrite(green_led, HIGH);
  Serial.println("Current State : GO");
  delay(green_wait);

  // Turn on yellow and wait for 2s
  digitalWrite(red_led, LOW);
  digitalWrite(yellow_led, HIGH);
  digitalWrite(green_led, LOW);
  delay(yellow_wait);


  // Turn on red and wait for 4s
  digitalWrite(red_led, HIGH);
  digitalWrite(yellow_led, LOW);
  digitalWrite(green_led, LOW);
  Serial.println("Current State : STOP");
  delay(red_wait);
}
