void setup() {
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
}
void loop() {
  FullSpeedForward();
  delay(1000);
  FullSpeedBackward();
  delay(1000);
  ZeroTO100();
  delay(1000);
  zeroTo100Backward();
  delay(1000);
}
void FullSpeedForward() {
  digitalWrite(8, HIGH);
  digitalWrite(9, LOW);
  digitalWrite(10, HIGH);
  delay(1000);
}
void FullSpeedBackward() {
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  delay(1000);
}
void ZeroTO100() {
  for (int i = 0; i < 256; i++) {
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
    digitalWrite(10, i);
    delay(20);
  }
}

void zeroTo100Backward() {
  for (int i = 0; i < 256; i++) {
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
    digitalWrite(10, i);
    delay(20);
  }
}