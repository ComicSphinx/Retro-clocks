/* @Author: Daniil Maslov */ 

#define EMPTY_CHAR ' '

typedef struct
{
    short hourFirstNumber;
    short hourSecondNumber;
    short minuteFirstNumber;
    short minuteSecondNumber;
} Time;

typedef struct
{
    short hour;
    short minute;
} HoursMinutes;

typedef struct
{
    COORD hourFirstNumberAngle;
    COORD hourSecondNumberAngle;
    COORD minutesSecondNumberAngle;
    COORD minutesFirstNumberAngle;
    
} Angles;


void cycleDrawTime();
bool checkTimeIsChanged();
void clearTime();
void showTime();
HoursMinutes getTime();
ConsoleSize getSizeOfConsole();
Time computeTimeNumbers();
Angles getAngles();
void drawNumber(short number, COORD angle);
short computeFirstNumber(short minute);
short computeSecondNumber(short minute, short firstNumber);


void cycleDrawTime()
{
    while (true)
    {   
        if (checkTimeIsChanged())
        {
            clearTime();
            showTime();
        }
    }
}

bool checkTimeIsChanged()
{
    static HoursMinutes oldTime;
    static HoursMinutes currentTime;

    currentTime = getTime();

    if (currentTime.hour > oldTime.hour || currentTime.minute > oldTime.minute || 
        currentTime.hour < oldTime.hour)
    {
        oldTime.hour = currentTime.hour;
        oldTime.minute = currentTime.minute;
        return true;
    }
    else
    {
        return false;
    }
}

void clearTime()
{
    long unsigned int cWrittenChars;
    ConsoleSize consoleSize = getSizeOfConsole();
    short height = consoleSize.right - 3;
    short weight = consoleSize.bottom - 2;
    
    COORD startPosition;
    startPosition.X = 1;
    startPosition.Y = 1;

    for (int j = 0; j < weight; ++j)
    {
        FillConsoleOutputCharacter(HStdOut, (TCHAR)EMPTY_CHAR, height, startPosition, &cWrittenChars);
        ++startPosition.Y;
    }
}

void showTime()
{
    Time time = computeTimeNumbers();
    Angles angles = getAngles();

    drawNumber(time.hourFirstNumber, angles.hourFirstNumberAngle);
    drawNumber(time.hourSecondNumber, angles.hourSecondNumberAngle);
    drawNumber(time.minuteFirstNumber, angles.minutesFirstNumberAngle);
    drawNumber(time.minuteSecondNumber, angles.minutesSecondNumberAngle);
}

HoursMinutes getTime()
{
    SYSTEMTIME st;
    GetLocalTime(&st);

    HoursMinutes hoursMinutes;
    hoursMinutes.hour = st.wHour;
    hoursMinutes.minute = st.wMinute;
    return hoursMinutes;
}

ConsoleSize getSizeOfConsole()
{
    ConsoleSize consoleSize;
    consoleSize.left = CsbInfo.srWindow.Left;
    consoleSize.right = CsbInfo.srWindow.Right;
    consoleSize.top = CsbInfo.srWindow.Top;
    consoleSize.bottom = CsbInfo.srWindow.Bottom;

    return consoleSize;
}

Time computeTimeNumbers()
{
    HoursMinutes hoursMinutes = getTime();
    Time time;
    time.hourFirstNumber = computeFirstNumber(hoursMinutes.hour);
    time.hourSecondNumber = computeSecondNumber(time.hourFirstNumber, hoursMinutes.hour);
    time.minuteFirstNumber = computeFirstNumber(hoursMinutes.minute);
    time.minuteSecondNumber = computeSecondNumber(time.minuteFirstNumber, hoursMinutes.minute);

    return time;
}

Angles getAngles()
{
    Angles angles;
    ConsoleSize consoleSize = getSizeOfConsole();

    angles.hourFirstNumberAngle.X = ((consoleSize.right / 2) / 2);
    short x = (angles.hourFirstNumberAngle.X / 2) / 2;
    angles.hourFirstNumberAngle.X += x;
    angles.hourFirstNumberAngle.Y = (consoleSize.bottom / 2) - 7;

    angles.hourSecondNumberAngle.X = angles.hourFirstNumberAngle.X + 10;
    angles.hourSecondNumberAngle.Y = angles.hourFirstNumberAngle.Y;

    angles.minutesFirstNumberAngle.X = 18 + angles.hourSecondNumberAngle.X;
    angles.minutesFirstNumberAngle.Y = angles.hourFirstNumberAngle.Y;

    angles.minutesSecondNumberAngle.X = 12 + angles.minutesFirstNumberAngle.X;
    angles.minutesSecondNumberAngle.Y = angles.hourFirstNumberAngle.Y;

    return angles;
}

void drawNumber(short number, COORD angle)
{
    if (number == 0)
        drawZero(angle);
    else if (number == 1)
        drawOne(angle);
    else if (number == 2)
        drawTwo(angle);
    else if (number == 3)
        drawThree(angle);
    else if (number == 4)
        drawFour(angle);
    else if (number == 5)
        drawFive(angle);
    else if (number == 6)
        drawSix(angle);
    else if (number == 7)
        drawSeven(angle);
    else if (number == 8)
        drawEight(angle);
    else if (number == 9)
        drawNine(angle);
}

short computeFirstNumber(short number)
{
    number = number / 10;
    return number;
}

short computeSecondNumber(short firstNumber, short secondNumber)
{
    firstNumber *= 10;
    secondNumber -= firstNumber;
    return secondNumber;
}