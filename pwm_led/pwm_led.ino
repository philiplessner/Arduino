int ledPin = 15;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  // if there is any serial available, read it:
  while (Serial.available() > 0) {
    int level = Serial.parseInt();
    if(Serial.read() == '\n') { //Look for newline
      analogWrite(ledPin, level);
      Serial.println(level, HEX); 
    }
  }
 
}
