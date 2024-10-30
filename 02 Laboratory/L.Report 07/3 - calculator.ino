void setup() {
Serial.begin(9600);
}

void loop() {
float a , b , result;
char c;

Serial.println("number1:");
while(!Serial.available());
a = Serial.parseFloat();
Serial.println(a);

Serial.println("enter + - * /:");
while(!Serial.available());
c = Serial.read();
Serial.println(a);

Serial.println("number2:");
while(!Serial.available());
b = Serial.parseFloat();
Serial.println(a);

switch(c){
  case '+': result = a + b; 
            Serial.print("result:");
            Serial.println(result);
  break;
  case '-': result = a - b; 
            Serial.print("result:");
            Serial.println(result);
  break;
  case '*': result = a * b; 
            Serial.print("result:");
            Serial.println(result);
  break;
  case '/': if(b != 0){result = a / b; 
                      Serial.print("result:");
                      Serial.println(result);
                      }else{
                      Serial.println("error");
                      }
  break;
}
}
