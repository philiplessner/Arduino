const int PROX = 5;
const int lightPin = 26;
const int LEDPIN = 15;
int pinState = 0;
int lightLevel = 0;

void setup() {
    pinMode(PROX, INPUT);
    pinMode(LEDPIN, OUTPUT);
}

void loop() {
    pinState = digitalRead(PROX);
    lightLevel = analogRead(lightPin);
    if (pinState && lightLevel < 1000) {
        digitalWrite(LEDPIN, HIGH);
        delay(4000);
    }
    else {
        digitalWrite(LEDPIN, LOW);
        delay(250);
    }
}
