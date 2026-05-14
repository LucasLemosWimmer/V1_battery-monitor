#include <Arduino.h>

const int RELAY_PINS[8] = {7, 8, 9, 10, 11, 12, 13, A0};  // Acht Relais-Eingänge gleichzeitig schalten

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 8; i++) {
    pinMode(RELAY_PINS[i], OUTPUT);
    digitalWrite(RELAY_PINS[i], HIGH);  // Alle Relais initial AUS setzen (active-low assumed)
  }
}

void loop() {
  for (int i = 0; i < 8; i++) {
    digitalWrite(RELAY_PINS[i], LOW);  // Alle Relais einschalten
  }
  Serial.println("Relais AN - NO geschlossen");
  delay(5000);

  for (int i = 0; i < 8; i++) {
    digitalWrite(RELAY_PINS[i], HIGH);  // Alle Relais ausschalten
  }
  Serial.println("Relais AUS - NO offen");
  delay(5000);
}  