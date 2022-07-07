#define MOVEMENT_SENSOR 2
#define LIGHT_SENSOR A0
#define LOW_LIGHT 300
#define HIGH_LIGHT 600

const byte lowLightPin[] = {13};
const byte highLightPin[] = {8, 12};

void setup() {
	for (int i = 0; i < sizeof(lowLightPin); i++) {
    	pinMode(lowLightPin[i], OUTPUT);
    }
	for (int i = 0; i < sizeof(highLightPin); i++) {
    	pinMode(highLightPin[i], OUTPUT);
    }
	pinMode(MOVEMENT_SENSOR, INPUT);
	pinMode(LIGHT_SENSOR, INPUT);
  
	Serial.begin(9600);
}

void controlLowLight(bool trigger) {
  	if (trigger) {
      	for (int i = 0; i < sizeof(lowLightPin); i++) {
    		digitalWrite(lowLightPin[i], HIGH);
        }
		delay(100);
      	return;
    }
    for (int i = 0; i < sizeof(lowLightPin); i++) {
     	digitalWrite(lowLightPin[i], LOW);
    }
    delay(300);
}

void controlHighLight(bool trigger) {
	if (trigger) {
      	for (int i = 0; i < sizeof(highLightPin); i++) {
    		digitalWrite(highLightPin[i], HIGH);
        }
		delay(100);
      	return;
	}
	for (int i = 0; i < sizeof(highLightPin); i++) {
    	digitalWrite(highLightPin[i], LOW);
    }
	delay(300);
}

void deactivateAllLights() {
  	for (int i = 0; i < sizeof(highLightPin); i++) {
		digitalWrite(highLightPin[i], LOW);
    }
  	for (int i = 0; i < sizeof(lowLightPin); i++) {
		digitalWrite(lowLightPin[i], LOW);
    }
}

void controlLights(int lightState, bool trigger) {
	if (lightState < LOW_LIGHT) {
		controlLowLight(trigger);
      	return;
	}
  	if(lightState > LOW_LIGHT && lightState < HIGH_LIGHT) {
		controlHighLight(trigger);
      	return;
    }
	deactivateAllLights();
	delay(500);
}

void loop(){
	bool movementTrigger = (digitalRead(MOVEMENT_SENSOR) == HIGH);
	int lightState = analogRead(LIGHT_SENSOR);
  
  	controlLights(lightState, movementTrigger);
}