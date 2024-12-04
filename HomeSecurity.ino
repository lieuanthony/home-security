int led = 13;       // the pin that the LED is attached to
int sensor = 2;     // the pin that the sensor is attached to
int state = LOW;    // by default, no motion detected
int val = 0;        // variable to store the sensor status (value)

void setup() {
  pinMode(led, OUTPUT);     // initialize the LED as output
  pinMode(sensor, INPUT);   // initialize the sensor as input
  Serial.begin(9600);       // initalize serial
}

void loop() {
  val = digitalRead(sensor);    // read sensor value
  if (val == HIGH) {            // check if the sensor is HIGH
    digitalWrite(led, HIGH);    // turn LED on
    delay(500);                 // delay 500 milliseconds

    if (state == LOW) {
      Serial.println("Motion detected!");
      state = HIGH;             // update variable state to HIGH
    }
  }

  else {
    digitalWrite(led, LOW);     // turn LED off
    delay(500);                 // delay 500 milliseconds

    if (state == HIGH) {
      Serial.println("Motion stopped!");
      state = LOW;              // update variable state to LOW
    }
  }
}