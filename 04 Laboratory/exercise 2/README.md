## گزارش کار: روشن کردن تصادفی یک LED با فشار دادن کلید

### عنوان آزمایش:
روشن کردن تصادفی یکی از چندین LED با فشار دادن یک کلید

### هدف آزمایش:
هدف از این آزمایش، آشنایی با نحوه تولید اعداد تصادفی در آردوینو و استفاده از آن‌ها برای کنترل تصادفی چندین LED است. همچنین، این آزمایش به عنوان یک مثال از کاربرد آرایه‌ها و توابع تصادفی در پروژه‌های آردوینو محسوب می‌شود.

### وسایل مورد نیاز:
* برد آردوینو
* ۶ عدد LED
* ۶ عدد مقاومت (220 اهم یا بیشتر)
* یک عدد کلید فشاری
* بردبورد
* سیم‌های جامپر

### شرح آزمایش:

#### توضیحات آزمایش:
در این آزمایش، شش LED به شش پایه مختلف آردوینو متصل شده است. با فشار دادن کلید، یکی از LEDها به صورت تصادفی روشن می‌شود. شماره LED روشن شده نیز بر روی مانیتور سریال نمایش داده می‌شود.

#### کد نرم‌افزاری:

```c++
int pinLed[] = { 5, 6, 7, 8, 9, 10 };
int but = A0;

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 6; i++) {
    pinMode(pinLed[i], OUTPUT);
  }
  pinMode(but, INPUT);
  randomSeed(analogRead(0));
}

void loop() {
  int ran = random(1, 6);
  int pinState = digitalRead(but);
  if (pinState == HIGH) {
    digitalWrite(pinLed[ran], HIGH);
    Serial.println(ran + 1);
    delay(2000);
    digitalWrite(pinLed[ran], LOW);
  }
}
```

* **تفسیر کد:**
  * آرایه `pinLed` حاوی شماره پایه‌های متصل به LEDها است.
  * تابع `randomSeed(analogRead(0))` برای تولید اعداد تصادفی با استفاده از مقدار آنالوگ یک پین استفاده می‌شود.
  * با فشار دادن کلید، یک عدد تصادفی بین ۱ تا ۶ تولید می‌شود و LED مربوط به آن شماره روشن می‌شود.
  * شماره LED روشن شده بر روی مانیتور سریال نمایش داده می‌شود.

#### شماتیک مدار:
![](https://github.com/vahidseyyedi/microProcessor/blob/main/04%20Laboratory/exercise%202/src/map2.jpg)
![](https://github.com/vahidseyyedi/microProcessor/blob/main/04%20Laboratory/exercise%202/src/2.1.jpg)
![](https://github.com/vahidseyyedi/microProcessor/blob/main/04%20Laboratory/exercise%202/src/2.2.jpg)
![](https://github.com/vahidseyyedi/microProcessor/blob/main/04%20Laboratory/exercise%202/src/2.3.gif)

#### نتیجه‌گیری:
در این آزمایش، با موفقیت توانستیم یکی از LEDها را به صورت تصادفی با فشار دادن یک کلید روشن کنیم. این آزمایش نشان می‌دهد که چگونه می‌توان از توابع تصادفی برای ایجاد رفتارهای غیرقابل پیش‌بینی در پروژه‌های آردوینو استفاده کرد. این مفهوم می‌تواند در ساخت بازی‌های ساده، پروژه‌های هنری تعاملی و سایر کاربردهای مشابه مورد استفاده قرار گیرد.
