#include <DHT.h>
#include <DHT_U.h>
#define DHTPIN 8
#define DHTTYPE DHT11
DHT dht(DHTPIN , DHTTYPE);

void setup() {
dht.begin();
Serial.begin(9600);
}

void loop() {
float temp = dht.readTemperature();
float humid = dht.readHumidity();
Serial.print("Temp:");
Serial.print(temp);
Serial.print("*C");
Serial.print("|");
Serial.print(humid);
Serial.print("%");
Serial.println(" ");
delay(1000);
}
