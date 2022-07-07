#define BUTTON_PIN 13
#define MAX_ATTEMPTS 5
#define BLINK_WAIT 75

int ledPins[] = {4, 5, 6, 7, 8, 9, 10, 11, 12};

int wait = 100;      
int score = 0;      
int wrong = 0;      

void setup () {
  for (int i = 0; i < sizeof(ledPins) / sizeof(ledPins[0]); i++) {
    pinMode(ledPins[i], OUTPUT);
  }

  pinMode(BUTTON_PIN, INPUT);
}

void wrongLED(int pressedPin) {
  blinkLED(ledPins[pressedPin], 2);
  digitalWrite(ledPins[pressedPin], LOW);        
  wrong++;             
  if (wrong == MAX_ATTEMPTS) {
    for (int i = 0; i < sizeof(ledPins) / sizeof(ledPins[0]); i++) {
      digitalWrite(ledPins[i], HIGH);    
      delay(250);
      wrong = 0;               
      score = 0;               
      wait = 100;              
    } 
  } 
}

int handleButtonPress(int i) {
  if (i == int((sizeof(ledPins) / sizeof(ledPins[0])) / 2)) {
    blinkLED(ledPins[i], 7);                 
    score++;
    wait = wait * 0.85;               
  } else {
    wrongLED(i);
    return 0;
  }
}

void loop () {
  while (digitalRead(BUTTON_PIN) == HIGH) {
    for (int i = 0; i < sizeof(ledPins) / sizeof(ledPins[0]); i++) {
      digitalWrite(ledPins[i], HIGH);
      delay(wait);

      if (digitalRead(BUTTON_PIN) == LOW) {
        i = handleButtonPress(i);
      }
      digitalWrite(ledPins[i], LOW);
    } 
  }
}

void blinkLED(int pin, int times) {
  for(int i = 0; i <= times; i++) {
    digitalWrite(pin, LOW);
    delay(BLINK_WAIT);
    digitalWrite(pin, HIGH);
    delay(BLINK_WAIT);
  }
}