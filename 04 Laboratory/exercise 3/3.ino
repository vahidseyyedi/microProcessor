int led = 9;
float val = 0 void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  val = analogRead(A0);
  analogWrite(led, val / 4);
  Serial.println(val);
}
