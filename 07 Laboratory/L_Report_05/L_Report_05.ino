#include <SoftwareSerial.h>
SoftwareSerial Bluetooth(10 , 11);
void setup() {
  Bluetooth.begin(9600);
}

void loop() {
Bluetooth.println("Hello World");
delay(2000);
}
