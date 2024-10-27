int ledPins[] = { 6, 7, 8, 9, 10 };
int but1 = A0;
void setup() {
  pinMode(but1, INPUT);
  for (int i = 0; i < 8; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  int pinState1 = digitalRead(but1);
  if (pinState1 == HIGH) {
    state3();
  }
}

void state3() {
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 5; j++) {
      digitalWrite(ledPins[j], HIGH);
      digitalWrite(ledPins[j + 1], HIGH);
      delay(100);
      digitalWrite(ledPins[j], LOW);
      digitalWrite(ledPins[j + 1], LOW);
      delay(100);
    }
  }
}
