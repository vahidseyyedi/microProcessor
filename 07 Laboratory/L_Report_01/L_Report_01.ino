float reading;
float voltage;
void setup() {
Serial.begin(9600);
}
void loop() {
reading = analogRead(A0);
voltage = reading * ((5/ 1024.0)*100);
Serial.print(voltage);
Serial.println(" C ");
delay(1000); 
}
