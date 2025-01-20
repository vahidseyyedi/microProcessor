int led = 2;
void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int IR;
  IR = digitalRead(A0);
  if (IR == 0) {
    Serial.print("object detected :");
    Serial.println(IR);
    digitalWrite(led, HIGH);
  } else {
    Serial.print("not detected :");
    Serial.println(IR);
    digitalWrite(led, LOW);
  }
}
