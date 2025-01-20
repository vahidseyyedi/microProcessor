## گزارش کار: ارتباط I2C بین دو برد آردوینو

**چکیده:**

این گزارش به بررسی نحوه برقراری ارتباط I2C بین دو برد آردوینو می‌پردازد. کد ارائه شده، یک سناریوی ارسال و دریافت داده‌ها بین دو برد را نشان می‌دهد. در این سناریو، برد آردوینو Master یک مقدار آنالوگ خوانده شده را به برد آردوینو Slave ارسال می‌کند و سپس یک مقدار دریافتی از Slave را با PWM بر روی پینی کنترل می‌کند.

**۱. مقدمه:**

 I2C (رابطه سریال دوطرفه) یک پروتکل ارتباطی است که به اتصال چندین دستگاه به یک باس مشترک امکان می‌دهد. این پروتکل برای برقراری ارتباط بین بردهای آردوینو و سایر دستگاه‌ها نیز کاربرد دارد. این گزارش نحوه پیکربندی و استفاده از I2C برای ارسال و دریافت داده‌ها بین دو برد آردوینو را شرح می‌دهد.

**۲. مواد و تجهیزات:**

*   دو برد آردوینو Uno (یا بردهای سازگار)
*   سیم‌های Dupont
*   کابل USB A-B
*   کامپیوتر با نرم‌افزار Arduino IDE نصب شده

**۳. مراحل انجام کار:**

1.  بردهای آردوینو را با استفاده از سیم‌های Dupont طبق شماتیک زیر به هم متصل کنید:
    *   پین SCL (Serial Clock) یک برد به پین SCL برد دیگر
    *   پین SDA (Serial Data) یک برد به پین SDA برد دیگر
2.  کد زیر را در برد آردوینو Master آپلود کنید:

```c++
#include <Wire.h>

int value = 0;

void setup() {
  Wire.begin(); // Master
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  int y = analogRead(A1);
  value = map(y, 0, 1023, 0, 255);
  Wire.beginTransmission(8); // Slave address (can be changed)
  Wire.write("Master value:");
  Wire.write(value);
  Wire.endTransmission();
  Wire.requestFrom(8, 1);
  while (Wire.available()) {
    int c = Wire.read();
    analogWrite(13, c);
    Serial.print("Slave value:");
    Serial.println(c);
  }
  delay(100);
}
```

3.  کد زیر را در برد آردوینو Slave آپلود کنید:

```c++
#include <Wire.h>

int x;
int value = 0;

void setup() {
  Wire.begin(8); // Slave address (set the same as master)
  Wire.onRequest(requestEvent);
  Wire.onReceive(receiveEvent);
  Serial.begin(9600);
  pinMode(9, OUTPUT);
}

void loop() {
  delay(100);
  analogWrite(9, x);
  int t = analogRead(A0);
  value = map(t, 0, 1023, 0, 255);
}

void receiveEvent() {
  while (Wire.available() > 1) { // Check for multiple bytes
    char c = Wire.read();
    Serial.print(c);
  }
  x = Wire.read();
  Serial.println(x);
}

void requestEvent() {
  Wire.write(value);
}
```

4.  بردهای آردوینو را به کامپیوتر وصل کنید.
5.  کدها را در هر برد جداگانه آپلود کنید.
6.  مانیتور سریال هر دو برد را باز کنید (Tools > Serial Monitor).
7.  برد Master یک مقدار آنالوگ را از پین A1 می‌خواند، آن را به Slave ارسال می‌کند، و سپس مقداری را که از Slave دریافت می‌کند با PWM کنترل می‌کند.

**۴. نتایج:**

*   برد Master مقدار خوانده شده از پین آنالوگ را همراه با متن "Master value:" در مانیتور سریال خود چاپ می‌کند.
*   برد Slave مقدار دریافتی را در مانیتور سریال خود چاپ می‌کند.
*   برد Master مقدار دریافتی از Slave را با PWM بر روی پین خروجی کنترل می‌کند.

**تصاویر:**

![](https://github.com/vahidseyyedi/microProcessor/blob/main/07%20Laboratory/L_Report_04/src/map.jpg)
![](https://github.com/vahidseyyedi/microProcessor/blob/main/07%20Laboratory/L_Report_04/src/video_2025-01-18_18-44-58%20(1).gif)


**۵. بحث:**

*   برد Master با فراخوانی `Wire.begin()` به عنوان Master I2C راه‌اندازی می‌شود.
*   برد Slave با فراخوان
