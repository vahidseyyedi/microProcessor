void setup() {
Serial.begin(9600);
}

void loop() {
for(int i = 0 ; i <360  ; i++){
  float y1  = sin(PI/180);
  float y2  = cos(PI/180);
  Serial.print(y1);
  Serial.print(" ");
  Serial.println(y2);
  delay(10);
}
}
