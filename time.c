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
void showTime();
bool checkTimeIsChanged();
void clearTime();
void drawNumber(short number, COORD angle);
HoursMinutes getTime();
Angles getAngles();
Time computeTimeNumbers();
short computeFirstHourNumber(short hour);
short computeSecondHourNumber(short hour, short firstNumber);
short computeFirstMinuteNumber(short minute);
short computeSecondMinuteNumber(short minute, short firstNumber);


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
        currentTime.hour < oldTime.hour || currentTime.minute < oldTime.minute)
    {
        oldTime.hour = currentTime.hour;
        oldTime.minute = currentTime.minute;
        return true;
    }
    else
    {
        oldTime.hour = currentTime.hour;
        oldTime.minute = currentTime.minute;
        return false;
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

HoursMinutes getTime()
{
    SYSTEMTIME st;
    GetLocalTime(&st);

    HoursMinutes hoursMinutes;

    hoursMinutes.hour = st.wHour;
    hoursMinutes.minute = st.wMinute;

    return hoursMinutes;
}

Angles getAngles()
{
    Angles angles;

    angles.hourFirstNumberAngle.X = 2;
    angles.hourFirstNumberAngle.Y = 2;
    
    angles.hourSecondNumberAngle.X = 12;
    angles.hourSecondNumberAngle.Y = 2;

    angles.minutesFirstNumberAngle.X = 30;
    angles.minutesFirstNumberAngle.Y = 2;

    angles.minutesSecondNumberAngle.X = 42;
    angles.minutesSecondNumberAngle.Y = 2;

    return angles;
}

Time computeTimeNumbers()
{
    HoursMinutes hoursMinutes = getTime();
    Time time;

    time.hourFirstNumber = computeFirstHourNumber(hoursMinutes.hour);
    time.hourSecondNumber = computeSecondHourNumber(hoursMinutes.hour, time.hourFirstNumber);
    time.minuteFirstNumber = computeFirstMinuteNumber(hoursMinutes.minute);
    time.minuteSecondNumber = computeSecondHourNumber(hoursMinutes.minute, time.minuteFirstNumber);

    return time;
}

short computeFirstHourNumber(short hour)
{
    static short number = 20;

    if (hour < number)
        return 1;
    else if (number >= 20)
        return 2;
}

short computeSecondHourNumber(short hour, short firstNumber)
{
    firstNumber *= 10;
    hour -= firstNumber;
    return hour;
}

short computeFirstMinuteNumber(short minute)
{
    if (minute >= 50)
        return 5;
    else if (minute >= 40)
        return 4;
    else if (minute >= 30)
        return 3;
    else if (minute >= 20)
        return 2;
    else if (minute >= 10)
        return 1;   
    else if (minute >= 0)
        return 0;
}

short computeSecondMinuteNumber(short minute, short firstNumber)
{
    firstNumber *= 10;
    minute -= firstNumber;
    return minute;
}