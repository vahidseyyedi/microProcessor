const int led = 13;
void setup() {
pinMode(led , OUTPUT);
Serial.begin(9600);
}

void loop() {
if(Serial.available()>0){
  String a = Serial.readString();
  if(a == "on")
  {
    digitalWrite(led , HIGH);
  }else if(a == "off")
  {
    digitalWrite(led , LOW);
  }
}
}
