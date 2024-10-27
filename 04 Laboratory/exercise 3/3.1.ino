int led = 9;
float val = 0 void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  val = analogRead(A0);
  val = val * 5.0 / 1023;
  analogWrite(led, val / 4);
  Serial.print("voltage:");
  Serial.print(newval);
  Serial.println(" ");
}
