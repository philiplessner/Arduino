const int proximitySensorPin = 5;
const int lightSensorPin = 26;
const int LEDPIN = 15;
const int lightLevelThreshold = 300;
const int ledOnTime = 10000;
int proximitySensorState = 0;
int lightLevel = 0;

void setup() {
    pinMode(proximitySensorPin, INPUT);
    pinMode(LEDPIN, OUTPUT);
}

void loop() {
    proximitySensorState = digitalRead(proximitySensorPin);
    lightLevel = analogRead(lightSensorPin);
    if (proximitySensorState && lightLevel < lightLevelThreshold) {
        digitalWrite(LEDPIN, HIGH);
        delay(ledOnTime);
    }
    else {
        digitalWrite(LEDPIN, LOW);
        delay(250);
    }
}
