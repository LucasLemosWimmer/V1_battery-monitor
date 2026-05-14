#include <Arduino.h>
#include <LiquidCrystal.h>

// LCD: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Relais an A0
const int RELAY_PIN = A0;

// Schaltintervall in ms
const unsigned long INTERVAL = 2000;

bool relayState = false;
unsigned long lastSwitch = 0;

void setup() {
  Serial.begin(9600);
  
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, HIGH);  // Relais initial AUS (active-low)
  
  // LCD initialisieren (16 Zeichen, 2 Zeilen)
  lcd.begin(16, 2);
  lcd.clear();
  
  // Erste Zeile: Titel
  lcd.setCursor(0, 0);
  lcd.print("Relais Status");
  
  // Zweite Zeile: initiales Status
  lcd.setCursor(0, 1);
  lcd.print("Relais: AUS");
  
  Serial.println("System gestartet - Relais und LCD initialisiert");
}

void loop() {
  unsigned long now = millis();
  
  // Prüfe ob Schaltintervall vergangen ist
  if (now - lastSwitch >= INTERVAL) {
    lastSwitch = now;
    relayState = !relayState;
    
    // Relais schalten (active-low: LOW=AN, HIGH=AUS)
    digitalWrite(RELAY_PIN, relayState ? LOW : HIGH);
    
    // LCD aktualisieren - zweite Zeile
    lcd.setCursor(0, 1);
    
    if (relayState) {
      lcd.print("Relais: AN      ");
      Serial.println("Relais AN - NO geschlossen");
    } else {
      lcd.print("Relais: AUS     ");
      Serial.println("Relais AUS - NO offen");
    }
  }
}