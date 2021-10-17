const int PROX = 5;
int pinState = 0;

void setup() {
    pinMode(PROX, INPUT);
    pinMode(LED_BUILTIN, OUTPUT);
    Serial1.begin(115200);
}

void loop() {
    pinState = digitalRead(PROX);
    if (pinState) {
        Serial1.println("Detected");
        digitalWrite(LED_BUILTIN, HIGH);
        delay(2000);
    }
    else {
        Serial1.println("Not Detected");
        digitalWrite(LED_BUILTIN, LOW);
        delay(250);
    }
}
