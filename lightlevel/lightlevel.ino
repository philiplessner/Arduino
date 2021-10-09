const int lightPin = 26;
int lightLevel = 0;

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    Serial1.begin(115200);
}

void loop () {
    lightLevel = analogRead(lightPin);
    Serial1.println(lightLevel);
    if (lightLevel < 1000) {
        digitalWrite(LED_BUILTIN, HIGH);
    }
    else {
        digitalWrite(LED_BUILTIN, LOW);
    }
    delay(2000);
}
