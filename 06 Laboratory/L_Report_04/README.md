## گزارش کار پروژه پخش ملودی با استفاده از آردوینو و تابع `tone()`

**مقدمه:**

این گزارش، مستندات مربوط به پروژه پخش یک ملودی ساده با استفاده از برد آردوینو و تابع `tone()` را ارائه می‌دهد. هدف این پروژه، آشنایی با نحوه تولید صدا با آردوینو و استفاده از آرایه‌ها برای ذخیره و پخش نت‌های موسیقی است.

**شرح پروژه:**

در این پروژه، یک ملودی کوتاه در قالب دو آرایه ذخیره شده است: `melody` که شامل فرکانس نت‌ها و `noteDurations` که شامل مدت زمان پخش هر نت است. در تابع `setup()`، یک حلقه `for` بر روی این آرایه‌ها پیمایش می‌کند و با استفاده از تابع `tone()`، هر نت را با مدت زمان مشخص پخش می‌کند.

**کد برنامه:**

کد برنامه به زبان C++ برای آردوینو به شرح زیر است:

```cpp
#include "pitches.h"

// notes in the melody:
int melody[] = {
NOTE_C4, NOTE_G3,NOTE_G3, NOTE_GS3, NOTE_G3,0, NOTE_B3, NOTE_C4};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
4, 8, 8, 4,4,4,4,4 
};

void setup() {
  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 8; thisNote++) {
    // to calculate the note duration, take one second
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000/noteDurations[thisNote];
    tone(8, melody[thisNote],noteDuration);
    //pause for the note's duration plus 30 ms:
    delay(noteDuration +30);
  }
}

void loop() {
  // no need to repeat the melody.
}
```

**توضیح کد:**

*   `#include "pitches.h"`: این خط، فایل `pitches.h` را که شامل تعریف فرکانس نت‌های موسیقی است، به پروژه اضافه می‌کند. این فایل معمولا به صورت جداگانه در پروژه‌های آردوینو برای تولید صدا استفاده می‌شود.
*   `int melody[]`: این آرایه، فرکانس نت‌های ملودی را ذخیره می‌کند. مقادیر آن از فایل `pitches.h` گرفته شده‌اند. `0` در این آرایه نشان دهنده سکوت است.
*   `int noteDurations[]`: این آرایه، مدت زمان پخش هر نت را مشخص می‌کند. مقادیر آن به صورت زیر تفسیر می‌شوند:
    *   4: نت چهارم (Quarter note)
    *   8: نت هشتم (Eighth note)
    *   و غیره.
*   `void setup()`: این تابع در ابتدای اجرای برنامه فراخوانی می‌شود.
    *   حلقه `for`: این حلقه بر روی آرایه‌های `melody` و `noteDurations` پیمایش می‌کند.
    *   `int noteDuration = 1000/noteDurations[thisNote];`: مدت زمان پخش هر نت را بر حسب میلی‌ثانیه محاسبه می‌کند. به عنوان مثال، برای یک نت چهارم (4)، مدت زمان 1000/4 = 250 میلی‌ثانیه خواهد بود.
    *   `tone(8, melody[thisNote],noteDuration);`: تابع `tone()` نت مورد نظر را با فرکانس مشخص شده در `melody[thisNote]` و به مدت `noteDuration` پخش می‌کند. پین 8 به عنوان پین خروجی صدا انتخاب شده است.
    *   `delay(noteDuration +30);`: بعد از پخش هر نت، یک تاخیر به اندازه مدت زمان نت به اضافه 30 میلی‌ثانیه اعمال می‌شود. این تاخیر کوتاه از چسبیدن نت‌ها به یکدیگر جلوگیری می‌کند و باعث وضوح بیشتر صدا می‌شود.
*   `void loop()`: این تابع خالی است زیرا ملودی فقط یک بار در تابع `setup()` پخش می‌شود.

**اتصالات سخت افزاری:**

اتصالات سخت افزاری به صورت زیر است:

*   یک بازر یا اسپیکر کوچک به پین 8 آردوینو متصل می‌شود.
*   پین منفی بازر یا اسپیکر به زمین (GND) آردوینو متصل می‌شود.

**نتایج:**

با اجرای این برنامه، ملودی ذخیره شده در آرایه‌ها از طریق بازر یا اسپیکر پخش می‌شود.

**تصاویر:**
![](https://github.com/vahidseyyedi/microProcessor/blob/main/06%20Laboratory/L_Report_04/src/Untitled%20Sketch%202_bb.jpg)
![](https://github.com/vahidseyyedi/microProcessor/blob/main/06%20Laboratory/L_Report_04/src/video_2025-01-18_18-44-58%20(1).gif)


**نتیجه گیری:**

این پروژه نشان می‌دهد که چگونه می‌توان با استفاده از آردوینو و تابع `tone()`، صدا تولید کرد و ملودی‌های ساده پخش کرد. این روش در پروژه‌های مختلفی مانند آلارم‌ها، اسباب‌بازی‌های موزیکال و غیره کاربرد دارد.

