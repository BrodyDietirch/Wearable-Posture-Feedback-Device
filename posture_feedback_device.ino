#include <Adafruit_ADXL343.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

Adafruit_ADXL343 accel = Adafruit_ADXL343(12345);

const int buttonPin = 2;   
const int buzzerPin = 8;

float nX = 0;
bool calibrated = false;

void setup() {
  Serial.begin(115200);
  delay(2000);

  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(buzzerPin, OUTPUT);

  bool ready = false;
  while (!ready) {
    if (accel.begin()) {
      ready = true;
    } else {
      Serial.println("ADXL343 NOT detected, waiting...");
      delay(500);
    }
  }

  Serial.println("ADXL343 detected.");
  accel.setRange(ADXL343_RANGE_2_G);

  Serial.println("Stand straight and press the button to calibrate.");

  tone(buzzerPin, 2000);
  delay(200);
  noTone(buzzerPin);
}

void loop() {
  sensors_event_t e;
  accel.getEvent(&e);

  // calibration button (saves upright X value)
  static unsigned long lastPress = 0;
  if (digitalRead(buttonPin) == LOW && millis() - lastPress > 300) {
    nX = e.acceleration.x;
    calibrated = true;
    Serial.println("Calibrated!");
    lastPress = millis();
  }

  Serial.print("X: ");
  Serial.print(e.acceleration.x, 2);
  Serial.print("  Y: ");
  Serial.print(e.acceleration.y, 2);
  Serial.print("  Z: ");
  Serial.print(e.acceleration.z, 2);

  if (calibrated) {
    float dX = fabs(e.acceleration.x - nX);
    bool slouch = (dX > 2.0);   // only using X now

    Serial.print("   ->  ");
    Serial.println(slouch ? "SLOUCHING!" : "Good posture");

    if (slouch) {
      tone(buzzerPin, 2000);
    } else {
      noTone(buzzerPin);
    }
  } else {
    Serial.println("   (not calibrated yet)");
    noTone(buzzerPin);
  }

  delay(300);
}
