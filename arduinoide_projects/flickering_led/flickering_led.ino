const int ledPin = LED_BUILTIN;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);

  digitalWrite(ledPin, LOW);
  delay(3000);

  digitalWrite(ledPin, HIGH);
  delay(1000);

  for (int i = 0; i < 6; i++) {
    digitalWrite(ledPin, HIGH);
    delay(300);
    digitalWrite(ledPin, LOW);
    delay(300);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(ledPin, HIGH);
}
