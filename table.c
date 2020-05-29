/*
 * @Author: Daniil Maslov
 * @CreationDate: 22.05.2020
 * @LastUpdate: 22.05.2020
 */

#define CHAR_EMPTY ' '
#define CHAR_ROW '-'
#define CHAR_COLUMN '|'


typedef struct
{
    short left;
    short right;
    short top;
    short bottom;
} ConsoleSize;


COORD AngleLeftTop;
COORD AngleLeftBottom;
HANDLE HStdOut;
CONSOLE_SCREEN_BUFFER_INFO CsbInfo;

void computeAngleValues();
void drawTable();
ConsoleSize getSizeOfConsole();
void drawRow(short length, COORD startPosition);
void drawColumn(short length, COORD startPosition, short numberOfIterations);
void clearContentPlace(short length, short numberOfIterations);

void computeAngleValues()
{
    ConsoleSize consoleSize = getSizeOfConsole();
    
    AngleLeftTop.X = 0;
    AngleLeftTop.Y = 0;
    AngleLeftBottom.X = consoleSize.left;
    AngleLeftBottom.Y = consoleSize.bottom;
}

void drawTable()
{
    ConsoleSize consoleSize = getSizeOfConsole();

    drawRow(consoleSize.right, AngleLeftTop);
    drawRow(consoleSize.right, AngleLeftBottom);
    drawColumn(consoleSize.right, AngleLeftTop, (consoleSize.bottom - 1));
    
    short length = consoleSize.right - 2;
    short numberOfIterations = (consoleSize.bottom - 1);
    clearContentPlace(length, numberOfIterations);
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

void drawRow(short length, COORD startPosition)
{
    long unsigned int cWrittenChars;

    FillConsoleOutputCharacter(HStdOut, (TCHAR)CHAR_ROW, length, startPosition, &cWrittenChars);
}

void drawColumn(short length, COORD startPosition, short numberOfIterations)
{
    long unsigned int cWrittenChars;

    for (int i = 1; i <= numberOfIterations; ++i)
    {
        startPosition.Y = i;
        FillConsoleOutputCharacter(HStdOut, (TCHAR)CHAR_COLUMN, length, startPosition, &cWrittenChars);
    }
}

void clearContentPlace(short length, short numberOfIterations)
{
    long unsigned int cWrittenChars;
    COORD startPosition;
    startPosition.X = 1;
    startPosition.Y = 1;


    for (int j = 0; j < numberOfIterations; ++j)
    {
        FillConsoleOutputCharacter(HStdOut, (TCHAR)CHAR_EMPTY, length, startPosition, &cWrittenChars);
        ++startPosition.Y;
    }
}