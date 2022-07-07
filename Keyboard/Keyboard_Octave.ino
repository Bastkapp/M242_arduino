#define C_PIN 2
#define D_PIN 3
#define E_PIN 4
#define F_PIN 5
#define G_PIN 6
#define A_PIN 7
#define B_PIN 8
#define BUZZER_PIN A0

void setup() {
  // Setup Pins
  pinMode(A_PIN, INPUT);
  pinMode(B_PIN, INPUT);
  pinMode(C_PIN, INPUT);
  pinMode(D_PIN, INPUT);
  pinMode(E_PIN, INPUT);
  pinMode(F_PIN, INPUT);
  pinMode(G_PIN, INPUT);
  
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  // Play sounds if the speciffic Button is pressed
  if (digitalRead(C_PIN) == HIGH) {
    playSound(48);
  }
  if (digitalRead(D_PIN) == HIGH) {
    playSound(50);
  }
  if (digitalRead(E_PIN) == HIGH) {
    playSound(52);
  }
  if (digitalRead(F_PIN) == HIGH) {
    playSound(53);
  }
  if (digitalRead(G_PIN) == HIGH) {
    playSound(55);
  }
  if (digitalRead(A_PIN) == HIGH) {
    playSound(57);
  }
  if (digitalRead(B_PIN) == HIGH) {
    playSound(59);
  }
  
  // Delay for performance
  delay(10);
}

// Plays a specific tune with the Buzzer
void playSound(int tune) {
  tone(A0, 440 * pow(2.0, (constrain(int((tune)), 35, 127) - 57) / 12.0), 100);
}
