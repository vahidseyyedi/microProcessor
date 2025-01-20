## گزارش کار پروژه نمایش اعداد با استفاده از کتابخانه SevSeg و نمایشگر هفت قسمتی

**مقدمه:**

این گزارش، مستندات مربوط به پروژه نمایش اعداد 0 تا 9 بر روی یک نمایشگر هفت قسمتی (Seven-Segment Display) با استفاده از کتابخانه SevSeg و برد آردوینو را ارائه می‌دهد. هدف این پروژه، آشنایی با نحوه استفاده از کتابخانه SevSeg برای ساده‌سازی کنترل نمایشگرهای هفت قسمتی است. این کتابخانه امکانات متعددی از جمله کنترل روشنایی، نمایش اعداد چند رقمی و مدیریت پین‌ها را فراهم می‌کند.

**شرح پروژه:**

در این پروژه، از کتابخانه SevSeg برای کنترل یک نمایشگر هفت قسمتی تک رقمی استفاده شده است. کد برنامه به گونه‌ای طراحی شده که اعداد 0 تا 9 را به ترتیب و با تاخیر 2 ثانیه نمایش دهد.

**کد برنامه:**

کد برنامه به زبان C++ برای آردوینو به شرح زیر است:

```cpp
#include "SevSeg.h"
SevSeg sevseg;

void setup()
{
    //Set to 1 for single digit display
    byte numDigits = 1;

    //defines common pins while using multi-digit display. Left empty as we have a single digit display
    byte digitPins[] = {};

    //Defines arduino pin connections in order: A, B, C, D, E, F, G, DP
    byte segmentPins[] = {1,2,3,4,5,6,7};
    bool resistorsOnSegments = true;

    //Initialize sevseg object. Uncomment second line if you use common cathode 7 segment
    sevseg.begin(COMMON_CATHODE, numDigits, digitPins, segmentPins, resistorsOnSegments);
    //sevseg.begin(COMMON_CATHODE, numDigits, digitPins, segmentPins, resistorsOnSegments);

    sevseg.setBrightness(90);
}

void loop()
{ 
    //Display numbers one by one with 2 seconds delay
    for(int i = 0; i < 10; i++)
    {
        sevseg.setNumber(i);
        sevseg.refreshDisplay(); 
        delay(2000);
    }
}
```

**توضیح کد:**

*   `#include "SevSeg.h"`: این خط، کتابخانه SevSeg را به پروژه اضافه می‌کند.
*   `SevSeg sevseg;`: یک شیء از کلاس SevSeg به نام `sevseg` ایجاد می‌کند.
*   `void setup()`: این تابع در ابتدای اجرای برنامه فراخوانی می‌شود و تنظیمات اولیه نمایشگر را انجام می‌دهد.
    *   `byte numDigits = 1;`: تعداد ارقام نمایشگر را 1 تعیین می‌کند.
    *   `byte digitPins[] = {};`: آرایه پین‌های مربوط به ارقام (در نمایشگرهای چند رقمی) را خالی می‌گذارد زیرا از یک نمایشگر تک رقمی استفاده می‌شود.
    *   `byte segmentPins[] = {1,2,3,4,5,6,7};`: پین‌های آردوینو متصل به قطعات نمایشگر (a تا g) را به ترتیب مشخص می‌کند. **این ترتیب بسیار مهم است و باید با نحوه اتصال فیزیکی نمایشگر مطابقت داشته باشد.**
    *   `bool resistorsOnSegments = true;`: مشخص می‌کند که آیا مقاومت‌های محدود کننده جریان بر روی قطعات نمایشگر قرار دارند یا خیر. این مورد معمولا `true` است. اگر از ماژول های آماده seven segment استفاده میکنید که مقاومت دارند این گزینه باید true باشد.
    *   `sevseg.begin(COMMON_CATHODE, numDigits, digitPins, segmentPins, resistorsOnSegments);`: شیء `sevseg` را با تنظیمات مشخص شده مقداردهی اولیه می‌کند. `COMMON_CATHODE` نوع نمایشگر را مشخص می‌کند (در صورت استفاده از نمایشگر Common Anode باید از `COMMON_ANODE` استفاده شود).
    *   `sevseg.setBrightness(90);`: روشنایی نمایشگر را روی 90 (از 0 تا 255) تنظیم می‌کند.
*   `void loop()`: این تابع به صورت مداوم اجرا می‌شود.
    *   `for(int i = 0; i < 10; i++)`: یک حلقه برای نمایش اعداد 0 تا 9 ایجاد می‌کند.
    *   `sevseg.setNumber(i);`: عدد `i` را برای نمایش روی نمایشگر تنظیم می‌کند.
    *   `sevseg.refreshDisplay();`: نمایشگر را به‌روزرسانی می‌کند. این تابع برای نمایش صحیح اعداد ضروری است.
    *   `delay(2000);`: برنامه 2 ثانیه مکث می‌کند.

**اتصالات سخت افزاری:**

اتصالات سخت افزاری به صورت زیر است:

*   هر یک از هفت قسمت نمایشگر (a تا g) به یک پین دیجیتال آردوینو (به ترتیب از پین 1 تا 7 مطابق با آرایه `segmentPins`) متصل می‌شود.
*   پین مشترک نمایشگر (Common Cathode) به زمین (GND) آردوینو متصل می‌شود.
*   **بسیار مهم:** هر قطعه از نمایشگر باید از طریق یک مقاومت محدود کننده جریان (معمولا 220 اهم) به پین آردوینو متصل شود، مگر اینکه از ماژول های آماده seven segment استفاده کنید. اگر `resistorsOnSegments` را true قرار داده اید و ماژول شما مقاومت ندارد، حتما باید مقاومت ها را قرار دهید.
** تصاویر: **

![](https://github.com/vahidseyyedi/microProcessor/blob/main/06%20Laboratory/L_Report_02/src/Untitled%20Sketch_bb.jpg)
![](https://github.com/vahidseyyedi/microProcessor/blob/main/06%20Laboratory/L_Report_02/src/photo_2024-11-10_23-00-08.jpg)


  **نتایج:**

با اجرای این برنامه، اعداد 0 تا 9 به ترتیب و با فاصله 2 ثانیه بر روی نمایشگر هفت قسمتی نمایش داده می‌شوند.

**تصاویر:**



**نتیجه گیری:**

این پروژه نشان می‌دهد که چگونه می‌توان با استفاده از کتابخانه SevSeg، کنترل نمایشگرهای هفت قسمتی را به طور قابل توجهی ساده‌تر کرد. این کتابخانه امکانات مفیدی مانند کنترل روشنایی و پشتیبانی از نمایشگرهای چند رقمی را فراهم می‌کند.

