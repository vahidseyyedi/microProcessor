# روشن کردن تصادفی LEDها با فشار دکمه
## مقدمه
این پروژه یک نمایشگر ساده از LEDها را پیاده‌سازی می‌کند که با فشار دادن یک دکمه، یکی از LEDها به صورت تصادفی روشن می‌شود. این 

## سخت‌افزار مورد نیاز
برد آردوینو 
6 عدد LED
1 عدد دکمه
مقاومت (برای محدود کردن جریان LED)
سیم‌های جامپر

## شماتیک مدار
![](https://github.com/vahidseyyedi/microProcessor/blob/main/04%20Laboratory/exercise%202/src/map2.jpg)
![](https://github.com/vahidseyyedi/microProcessor/blob/main/04%20Laboratory/exercise%202/src/2.1.jpg)
![](https://github.com/vahidseyyedi/microProcessor/blob/main/04%20Laboratory/exercise%202/src/2.2.jpg)
![](https://github.com/vahidseyyedi/microProcessor/blob/main/04%20Laboratory/exercise%202/src/2.3.gif)

## توضیح کد
* pinLed[]: آرایه‌ای برای ذخیره شماره پین‌های متصل به LEDها.
* but: شماره پین متصل به دکمه.
* تابع setup:
ارتباط سریال را برای نمایش اطلاعات در مانیتور سریال آغاز می‌کند.
پین‌های LED را به عنوان خروجی تنظیم می‌کند.
پین دکمه را به عنوان ورودی تنظیم می‌کند.
تابع تولید اعداد تصادفی را با استفاده از مقدار آنالوگ ورودی صفر اولیه‌سازی می‌کند.
* تابع loop:
یک عدد تصادفی بین 1 تا 6 تولید می‌کند.
وضعیت دکمه را می‌خواند.
در صورت فشرده شدن دکمه، LED متناظر با عدد تصادفی را روشن می‌کند، عدد LED را در مانیتور سریال نمایش می‌دهد و به مدت 2 ثانیه منتظر می‌ماند سپس LED را خاموش می‌کند.
