int LED = 13;
int sensor;
void setup() {
Serial.begin(9600);
pinMode(LED,OUTPUT);
}

void loop() {
sensor = analogRead(A0);
Serial.print("hello");

Serial.println(sensor);
delay(300);
if(sensor >800){
  digitalWrite(LED, LOW);
}else{
    digitalWrite(LED, HIGH);

}
}
