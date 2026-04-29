#include <Arduino.h>

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println("System läuft");
  delay(1000);
};