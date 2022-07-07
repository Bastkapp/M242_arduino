#include <LiquidCrystal.h>

LiquidCrystal lcd(9, 8, 5, 4, 3, 2);

#define TMP_PIN A1
#define HEATER_PIN 13
#define VENT_PIN 12

#define COLDLINE 15
#define HOTLINE 27


void setup() {
  Serial.begin(9600);
  pinMode(TMP_PIN, INPUT);
  pinMode(HEATER_PIN, OUTPUT);
  pinMode(VENT_PIN, OUTPUT);
}

float getTemperature(uint8_t tmpPin) {
  float temp = analogRead(tmpPin)*0.004882814;
  return (temp - 0.5) * 100.0;
}

void displayTemperature(float temperature) {
  lcd.begin(16, 2);
  lcd.print("Temperature");
  
  lcd.setCursor(0, 1);
  lcd.print("				");
  lcd.setCursor(0, 1);
  lcd.print(temperature);
  lcd.print(" C");
}

void activateHeat() {
  digitalWrite(HEATER_PIN, HIGH);
}

void activateVent() {
  digitalWrite(VENT_PIN, HIGH);
}

void deactivateHeat() {
  digitalWrite(HEATER_PIN, LOW);
}

void deactivateVent() {
  digitalWrite(VENT_PIN, LOW);
}

void loop() {
  float temperature = getTemperature(TMP_PIN);
  	
  displayTemperature(temperature);
    
  if (temperature <= COLDLINE) {
	activateHeat();
    activateVent();
  } else if (temperature >= HOTLINE) {
    deactivateHeat();
    activateVent();
  } else {
    deactivateHeat();
    deactivateVent();
  }
  
  delay(1000);
}
