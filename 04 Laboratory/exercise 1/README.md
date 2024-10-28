# پروژه نمایشگر الگوهای LED با کنترل دکمه
![](https://github.com/vahidseyyedi/microProcessor/blob/main/04%20Laboratory/exercise%201/src/Slide1.JPG)
## شرح پروژه
این پروژه آردوینو، نمایش الگوهای LED با کنترل دکمه را به سادگی پیاده سازی می کند. کد از یک آرایه دو بعدی برای ذخیره الگوهای LED استفاده می کند و با پیمایش این آرایه، وضعیت LED ها را کنترل می کند.

## سخت افزار مورد نیاز
برد آردوینو
5 عدد LED
1 عدد دکمه
مقاومت (برای محدود کردن جریان LED)

## شماتیک مدار
![](https://github.com/vahidseyyedi/microProcessor/blob/main/04%20Laboratory/exercise%201/src/map%201.jpg)
![](https://github.com/vahidseyyedi/microProcessor/blob/main/04%20Laboratory/exercise%201/src/1.3.gif)
![](https://github.com/vahidseyyedi/microProcessor/blob/main/04%20Laboratory/exercise%201/src/1.1.jpg)


## توضیح کد

* ledPins[]: آرایه ای برای ذخیره شماره پین های LED ها.
* but1: شماره پین دکمه.
* ledPattern[][]: آرایه دو بعدی برای ذخیره الگوهای LED. هر سطر نشان دهنده یک الگو و هر ستون نشان دهنده یک LED است.
* تابع setup:
پین دکمه را به عنوان ورودی پیکربندی می کند.
پین های LED را به عنوان خروجی پیکربندی می کند.

* تابع loop:
وضعیت دکمه را می خواند.
اگر دکمه فشرده شود (HIGH)، تابع state3() فراخوانی می شود.

* تابع state3():
وضعیت اولیه: LED اول را روشن می کند.
پیمایش الگوها:
آرایه ledPattern را پیمایش می کند.
برای هر الگو:
اگر عنصر جاری 1 است، LED مربوطه و LED بعدی را روشن می کند.
اگر عنصر جاری 0 است، LED های مربوطه را خاموش می کند.
بین هر تغییر وضعیت، 100 میلی ثانیه تاخیر ایجاد می کند.
وضعیت نهایی: آخرین LED را خاموش می کند.

## فایل 1.1
* تابع state3:
یک الگوی خاص را بر روی LEDها نمایش می‌دهد. این الگو شامل روشن و خاموش کردن متناوب دو LED مجاور است.
* نقاط قوت:
سادگی پیاده‌سازی
قابل توسعه برای الگوهای پیچیده‌تر
* نقاط ضعف:
الگوهای محدود
عدم وجود مکانیسم برای تغییر سرعت نمایش الگوها