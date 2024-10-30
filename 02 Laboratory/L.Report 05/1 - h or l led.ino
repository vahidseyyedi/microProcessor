const int led = 13;
void setup() {
pinMode(led , OUTPUT);
Serial.begin(9600);
}

void loop() {
if(Serial.available()>0){
  char a = Serial.read();
  if(a == 'H' || a == 'h'){
    digitalWrite(led , HIGH);
  }else if(a == 'L' || a == 'l'){
    digitalWrite(led , HIGH);
  }
}
}
