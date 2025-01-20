## گزارش کار پروژه ماشین حساب با صفحه کلید ماتریسی 4x4 با آردوینو

**مقدمه:**

این گزارش، مراحل ساخت و عملکرد یک ماشین حساب ساده با استفاده از صفحه کلید ماتریسی 4x4 و برد آردوینو را شرح می‌دهد. این ماشین حساب قادر به انجام عملیات جمع، تفریق، ضرب و تقسیم اعداد است. خروجی ماشین حساب بر روی سریال مانیتور نمایش داده می‌شود.

**قطعات مورد نیاز:**

*   برد آردوینو (مانند Arduino Uno)
*   صفحه کلید ماتریسی 4x4
*   سیم‌های جامپر
*   کامپیوتر با نرم‌افزار Arduino IDE

**شرح پروژه:**

این پروژه از یک صفحه کلید ماتریسی 4x4 برای دریافت اعداد و عملگرها از کاربر استفاده می‌کند. کتابخانه `Keypad.h` برای خواندن ورودی از صفحه کلید به کار گرفته شده است. برنامه نوشته شده، اعداد و عملگرهای فشرده شده را پردازش کرده و نتیجه نهایی را بر روی سریال مانیتور نمایش می‌دهد.

**شرح کد:**

```cpp
/* Code with comments omitted for brevity */

#include <Keypad.h>

const byte ROWS = 4; // تعداد سطرهای صفحه کلید
const byte COLS = 4; // تعداد ستون‌های صفحه کلید

float firstNumber = 0;
float secondNumber = 0;
float result = 0;
bool section = false;
int type = 0;

// تعریف چیدمان کلیدها
char hexaKeys[ROWS][COLS] = {...};

// تعریف پایه‌های اتصال صفحه کلید
byte colPins[ROWS] = {...};
byte rowPins[COLS] = {...};

// ایجاد شیء برای برقراری ارتباط با صفحه کلید
Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(9600); // راه‌اندازی ارتباط سریال
}

void loop() {
  // خواندن کلید فشرده شده
  int button = int(customKeypad.getKey()) - 48;

  // بررسی مقدار کلید فشرده شده
  if (0 <= button && button <= 10) {
    // دریافت رقم
    Serial.print(button);
    if (!section) {
      firstNumber = firstNumber * 10 + button;
    } else {
      secondNumber = secondNumber * 10 + button;
    }
  } else {
    switch (button) {
      // تعیین نوع عملیات بر اساس کلیدهای A تا D
      case 17: // A
        section = true;
        type = 1;
        Serial.print('+');
        break;
      case 18: // B
        section = true;
        type = 2;
        Serial.print('-');
        break;
      case 19: // C
        section = true;
        type = 3;
        Serial.print('*');
        break;
      case 20: // D
        section = true;
        type = 4;
        Serial.print('/');
        break;
      case -6: // * (clear)
        section = false;
        type = 0;
        Serial.println();
        break;
      case -13: // # (equals)
        Serial.print(" = ");
        switch (type) {
          case 1:
            result = firstNumber + secondNumber;
            break;
          case 2:
            result = firstNumber - secondNumber;
            break;
          case 3:
            result = firstNumber * secondNumber;
            break;
          case 4:
            result = firstNumber / secondNumber;
            break;
        }
        type = 0;
        Serial.println(result);
        firstNumber = 0;
        secondNumber = 0;
        section = false;
        break;
    }
  }
}
```

*   تعریف کتابخانه `Keypad.h` برای کار با صفحه کلید.
*   تعریف پین‌های اتصال صفحه کلید به آردوینو.
*   ایجاد شیء از کلاس `Keypad` برای برقراری ارتباط با صفحه کلید.
*   تعیین چیدمان کلیدها در آرایه `hexaKeys`.
*   تابع `setup` برای راه‌اندازی ارتباط سریال.
*   تابع `loop` که به طور مداوم اجرا می‌شود و وظیفه خواندن ورودی از صفحه کلید و انجام محاسبات را بر عهده دارد.

**نحوه عملکرد کد:**

1.  در هر بار اجرای حلقه `loop`، تابع `customKeypad.getKey()` فراخوانی می‌شود تا کلید فشرده شده را بخواند.
2.  اگر کلیدی فشرده شده باشد، مقدار آن به کد اسکی (ASCII) برگردانده می‌شود. برای تبدیل کد اسکی رقم به مقدار عددی آن، عدد 48 از آن کم می‌شود (کد اسکی '0' برابر 48 است).
3.  اگر مقدار `button` بین 0 و 9 باشد، به این معنی است که یک رقم فشرده شده است. در این حالت:
    *   اگر `section` برابر `false` باشد، رقم به عنوان رقم عدد اول در نظر گرفته شده و به `firstNumber` اضافه می‌شود.
    *   اگر `section` برابر `true` باشد، رقم به عنوان رقم عدد دوم در نظر گرفته شده و به `secondNumber` اضافه می‌شود.
4.  اگر مقدار `button` مربوط به یکی از عملگرها (A, B, C, D, \*, #) باشد، وارد بخش `switch` می‌شود.
5.  در بخش `switch`، بر اساس کلید فشرده شده، عملیات مربوطه انجام می‌شود:
    *   کلید A (+): `section` برابر `true` شده و `type` برابر 1 (جمع) تنظیم می‌شود.
    *   کلید B (-): `section` برابر `true` شده و `type` برابر 2 (تفریق) تنظیم می‌شود.
    *   کلید C (\*): `section` برابر `true` شده و `type` برابر 3 (ضرب) تنظیم می‌شود.
    *   کلید D (/): `section` برابر `true` شده و `type` برابر 4 (تقسیم) تنظیم می‌شود.
    *   کلید \* (پاک کردن): `section` برابر `false` و `type` برابر 0 تنظیم شده و اعداد و عملگرها پاک می‌شوند.
    *   کلید # (مساوی): عملیات محاسبه بر اساس مقدار `type` انجام شده و نتیجه در `result` ذخیره می‌شود. سپس نتیجه در سریال مانیتور نمایش داده شده و متغیرهای `firstNumber`، `secondNumber` و `section` ریست می‌شوند.

**نحوه اتصال قطعات:**

*   پایه‌های سطرهای صفحه کلید (rowPins) به پایه‌های دیجیتال 9، 8، 7 و 6 آردوینو متصل می‌شوند.
*   پایه‌های ستون‌های صفحه کلید (colPins) به پایه‌های دیجیتال 5، 4، 3 و 2 آردوینو متصل می‌شوند.

**تصاویر:**
![](https://github.com/vahidseyyedi/microProcessor/blob/main/07%20Laboratory/L_Report_08/src/Untitled%20Sketch%202_bb.jpg)

**نتایج و آزمایش:**

پس از آپلود کد بر روی برد آردوینو و باز کردن سریال مانیتور، می‌توانید با فشردن اعداد و عملگرها روی صفحه کلید، محاسبات را انجام داده و نتیجه را در سریال مانیتور مشاهده کنید.

