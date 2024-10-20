  
# تمرین اول: دو چراغ 5 ثانیه روشن و 0.5 ثانیه خاموش

کنترل دو LED متصل به پین‌های 9 و 13 بر روی برد Arduino.
ایجاد یک الگوی چشمک‌زن ساده برای LEDها.
## وسایل و تجهیزات:
* برد Arduino Uno
* دو LED (قرمز یا سبز)
* دو مقاومت 220 اهم
* بردبورد
* سیم‌های اتصال
  
## روش کار:

* اتصال مدار:

اثصال مدار طبق شماتیک موجود

* بارگذاری کد:
  
کد Arduino را در محیط توسعه Arduino IDE وارد کنید.
کد را کامپایل و بارگذاری کنید.

## شماتیک مدار
![توضیح تصویر](https://github.com/vahidseyyedi/microProcessor/blob/main/02%20Laboratory/img/map%201.png)
![alt text](https://github.com/vahidseyyedi/microProcessor/blob/main/02%20Laboratory/img/l.e%201.gif)



## شرح خط به خط:

* int led1 = 9; و int led2 = 13;:
  
دو متغیر به نام‌های led1 و led2 از نوع عدد صحیح (int) تعریف می‌شوند.
این متغیرها برای ذخیره شماره پین‌های مربوط به LEDها استفاده می‌شوند. در این مثال، LED اول به پین 9 و LED دوم به پین 13 متصل شده است.

* void setup() { ... }:
  
این تابع یک بار در ابتدای برنامه اجرا می‌شود.
در این تابع، پین‌های مورد استفاده برای کنترل LEDها تنظیم می‌شوند.

* pinMode(led1, OUTPUT); و pinMode(led2, OUTPUT);:
  
این دستورات پین‌های led1 و led2 را به عنوان خروجی تنظیم می‌کنند. این بدان معنی است که ما می‌توانیم با استفاده از این پین‌ها، ولتاژ را کنترل کرده و در نتیجه LEDها را روشن یا خاموش کنیم.

* void loop() { ... }:
  
این تابع به صورت مداوم تکرار می‌شود تا زمانی که برد Arduino روشن باشد.
کد داخل این تابع کار اصلی برنامه را انجام می‌دهد.

* digitalWrite(led1, HIGH); و digitalWrite(led2, HIGH);:
  
این دستورات ولتاژ پین‌های led1 و led2 را به مقدار بالا (HIGH) تنظیم می‌کنند. در بیشتر موارد، این باعث روشن شدن LEDها می‌شود.

* delay(5000);:
  
این دستور باعث می‌شود که برنامه برای 5000 میلی‌ثانیه (5 ثانیه) مکث کند. در این مدت، LEDها روشن می‌مانند.

* digitalWrite(led1, LOW); و digitalWrite(led2, LOW);:
  
این دستورات ولتاژ پین‌های led1 و led2 را به مقدار پایین (LOW) تنظیم می‌کنند. این باعث خاموش شدن LEDها می‌شود.

* delay(500);:
  
این دستور باعث می‌شود که برنامه برای 500 میلی‌ثانیه (0.5 ثانیه) مکث کند. در این مدت، LEDها خاموش می‌مانند.


# تمرین 2 : دو چراغ 1 ثانیه روشن و 1 ثانیه خاموش

در این تمرین، به بررسی عملکرد یک برنامه ساده در محیط آردوینو پرداخته‌ایم. هدف اصلی این برنامه، کنترل دو چراغ LED متصل به پین‌های 9 و 13 برد آردوینو و ایجاد یک الگوی چشمک زن با فاصله زمانی یک ثانیه برای هر دو چراغ است.

## اجزای مورد استفاده
مانند تمرین اول

## شرح برنامه
* تعریف متغیرها:
led1 و led2: دو متغیر از نوع عدد صحیح برای تعیین شماره پین‌های متصل به LEDها تعریف شده‌اند.
* تابع setup():
در این تابع، پین‌های led1 و led2 به عنوان خروجی تنظیم می‌شوند. این به این معنی است که آردوینو می‌تواند به این پین‌ها ولتاژ اعمال کرده و LEDها را روشن یا خاموش کند.
* تابع loop():
این تابع به صورت بی‌نهایت تکرار می‌شود و منطق اصلی برنامه را تشکیل می‌دهد.
در هر تکرار، ابتدا هر دو LED روشن می‌شوند (HIGH).
سپس، برنامه به مدت یک ثانیه مکث می‌کند (delay(1000)).
در ادامه، هر دو LED خاموش می‌شوند (LOW).
و دوباره، برنامه به مدت یک ثانیه مکث می‌کند.

## شماتیک مدار
![alt text](https://github.com/vahidseyyedi/microProcessor/blob/main/02%20Laboratory/img/l.e%202.gif)
* شماتیک مدار همان شماتیک تمرین اول است.

# تمرین 3 : یک چراغ روشن و دیگری خاموش
در این تمرین، به بررسی عملکرد برنامه‌ای پرداخته‌ایم که باعث می‌شود یکی از دو چراغ LED متصل به برد آردوینو به طور دائم روشن و دیگری به طور دائم خاموش بماند. این تمرین ساده، مفهوم اولیه کنترل خروجی‌های دیجیتال در آردوینو را به خوبی نشان می‌دهد.

## اجزای مورد استفاده
مانند تمرین اول

## شرح برنامه
* تعریف متغیرها:
led1 و led2: دو متغیر از نوع عدد صحیح برای تعیین شماره پین‌های متصل به LEDها تعریف شده‌اند.
* تابع setup():
در این تابع، پین‌های led1 و led2 به عنوان خروجی تنظیم می‌شوند. این به این معنی است که آردوینو می‌تواند به این پین‌ها ولتاژ اعمال کرده و LEDها را روشن یا خاموش کند.
* تابع loop():
این تابع به صورت بی‌نهایت تکرار می‌شود و منطق اصلی برنامه را تشکیل می‌دهد.
در هر تکرار، LED متصل به پین led1 خاموش می‌شود (LOW) و LED متصل به پین led2 روشن می‌شود (HIGH). از آنجایی که این تابع به صورت مداوم اجرا می‌شود، این حالت تا زمانی که برنامه متوقف شود، حفظ خواهد شد.

## شماتیک مدار
![alt text](https://github.com/vahidseyyedi/microProcessor/blob/main/02%20Laboratory/img/l.e%203.gif)
* شماتیک مدار همان شماتیک تمرین اول است.

# تمرین 4 : کار با serial monitor و println()

در این تمرین، به بررسی عملکرد برنامه‌ای پرداخته‌ایم که از طریق پورت سریال با کامپیوتر ارتباط برقرار کرده و پیام "Hello World!" را به صورت مداوم روی Serial Monitor نمایش می‌دهد. این تمرین، مفهوم اولیه ارتباط سریال و استفاده از تابع println() را در محیط آردوینو به خوبی نشان می‌دهد.

## اجزای مورد استفاده
برد آردوینو: به عنوان مغز متفکر سیستم عمل کرده و برنامه را اجرا می‌کند.
کامپیوتر: برای نمایش اطلاعات ارسالی از طریق پورت سریال استفاده می‌شود.
کابل USB: برای اتصال برد آردوینو به کامپیوتر و برقراری ارتباط سریال به کار می‌رود.

## شرح برنامه
تابع setup():
Serial.begin(9600): این دستور ارتباط سریال را با نرخ باود 9600 بیت بر ثانیه آغاز می‌کند. نرخ باود، سرعت انتقال داده‌ها بین آردوینو و کامپیوتر را تعیین می‌کند.
تابع loop():
Serial.println("Hello World!"): این دستور پیام "Hello World!" را به همراه یک کاراکتر خط جدید (\n) به پورت سریال ارسال می‌کند. کاراکتر خط جدید باعث می‌شود که پیام جدید در خط بعدی Serial Monitor نمایش داده شود.
delay(1000): این دستور باعث می‌شود که برنامه به مدت یک ثانیه مکث کند و سپس دوباره دستور Serial.println() اجرا شود.

## نتایج و تحلیل
با اجرای این برنامه و باز کردن Serial Monitor در محیط برنامه‌نویسی آردوینو، پیام "Hello World!" به صورت مداوم با فاصله زمانی یک ثانیه در پنجره Serial Monitor نمایش داده می‌شود. این نشان می‌دهد که برنامه به درستی نوشته شده و توانسته است ارتباط سریال را برقرار کرده و داده‌ها را به کامپیوتر ارسال کند.

## شماتیک مدار
![alt text](https://github.com/vahidseyyedi/microProcessor/blob/main/02%20Laboratory/img/l.e%204.gif)

