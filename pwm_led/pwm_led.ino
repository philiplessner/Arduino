int ledPin = 15;

void setup() {
  // put your setup code here, to run once:
  Serial1.begin(115200);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  // if there is any serial available, read it:
  while (Serial1.available() > 0) {
    int level = Serial1.parseInt();
    if(Serial1.read() == '\n') { //Look for newline
      analogWrite(ledPin, level);
      Serial1.println(level, HEX); 
    }
  }
 
}
