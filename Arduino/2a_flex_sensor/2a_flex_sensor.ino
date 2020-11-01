const int flexPin = A0;      // Pin connected to voltage divider output

// Change these constants according to your project's design
const float VCC = 5;      // voltage at Ardunio 5V line
const float R_DIV = 10000.0;  // resistor used to create a voltage divider
const float flatResistance = 12000.0; // resistance when flat
const float bendResistance = 40000.0;  // resistance at 90 deg

int led_pin = 3;

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
  float angle = map(Rflex, flatResistance, bendResistance, 0, 90.0);
  if (Rflex > 30000)
    digitalWrite(led_pin, HIGH);
  else
    digitalWrite(led_pin, LOW);
  Serial.println("Bend: " + String(angle) + " degrees");
  Serial.println();

  delay(500);
}
