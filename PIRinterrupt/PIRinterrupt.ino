const int pirPin = 5;
const int ledPin = 15;
const int lightSensorPin = 26;
const long interval = 1000;
const int lightLevelThreshold = 300;
unsigned long previousMillis = 0;
int lightLevel;

void setup() {
  // put your setup code here, to run once:
  Serial1.begin(115200);
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(pirPin), pir_interrupt, RISING);
  digitalWrite(ledPin, LOW);
}

void pir_interrupt() {
  noInterrupts();
  lightLevel = analogRead(lightSensorPin);
  if (lightLevel < lightLevelThreshold) {
      Serial1.println("Detected");
      previousMillis = millis();
      digitalWrite(ledPin, HIGH);
      unsigned long currentMillis = millis();
      while (currentMillis - previousMillis <= interval) {
        currentMillis = millis();
      }
      digitalWrite(ledPin, LOW);
      }
  interrupts();
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1); // this speeds up the simulation
}
