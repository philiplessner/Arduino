const int PROX = 5;
const int lightPin = 26;
int pinState = 0;
int lightLevel = 0;

void setup() {
    pinMode(PROX, INPUT);
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
    pinState = digitalRead(PROX);
    lightLevel = analogRead(lightPin);
    if (pinState && lightLevel < 1000) {
        digitalWrite(LED_BUILTIN, HIGH);
        delay(4000);
    }
    else {
        digitalWrite(LED_BUILTIN, LOW);
        delay(250);
    }
}
