# Home Security Project

This Arduino-based **Home Security System** is a simple project designed to detect motion and alert you via an LED indicator. It uses an Arduino Uno, a motion sensor, and an LED to provide a basic security feature that can be easily expanded.

---

## Features
- Detects motion using a motion sensor (PIR sensor).
- Lights up an LED when motion is detected.
- Provides serial feedback for monitoring motion status.
- Simple and easy to set up with minimal components.

---

## Components Required
- Arduino Uno
- PIR Motion Sensor
- LED (any color)
- Resistor (220Ω recommended for the LED)
- Breadboard
- Jumper Wires
- USB Cable (to upload code and power the Arduino)

---

## Circuit Diagram
Connect the components as follows:

1. **PIR Motion Sensor:**
   - VCC to Arduino 5V
   - GND to Arduino GND
   - OUT to Arduino Digital Pin 2

2. **LED:**
   - Positive (longer leg) to Arduino Digital Pin 13 (with a 220Ω resistor in series)
   - Negative (shorter leg) to Arduino GND

---

## Code

```cpp
int led = 13;       // the pin that the LED is attached to
int sensor = 2;     // the pin that the sensor is attached to
int state = LOW;    // by default, no motion detected
int val = 0;        // variable to store the sensor status (value)

void setup() {
  pinMode(led, OUTPUT);     // initialize the LED as output
  pinMode(sensor, INPUT);   // initialize the sensor as input
  Serial.begin(9600);       // initialize serial communication
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
  } else {
    digitalWrite(led, LOW);     // turn LED off
    delay(500);                 // delay 500 milliseconds

    if (state == HIGH) {
      Serial.println("Motion stopped!");
      state = LOW;              // update variable state to LOW
    }
  }
}
```

---

## How It Works

1. The **PIR Motion Sensor** continuously monitors its surroundings for motion.
2. If motion is detected:
  - The sensor sends a HIGH signal to the Arduino.
  - The Arduino turns on the LED and prints "Motion detected!" to the serial monitor.
3. If no motion is detected:
  - The sensor sends a LOW signal.
  - The Arduino turns off the LED and prints "Motion stopped!" to the serial monitor.

---

## Usage 

1. Build the circuit as per the diagram.
2. Upload the provided code to the Arduino Uno.
3. Power the Arduino via USB or an external power source.
4. Open the serial monitor in the Arduino IDE to view motion status updates.

---

## Customization Ideas
- Replace the LED with a buzzer for an audible alarm.
- Use a relay module to trigger other devices like lights or alarms.
- Connect the system to a Wi-Fi module (e.g., ESP8266) for remote monitoring.

---

**Enjoy Building Your Home Security System! 🚨**
