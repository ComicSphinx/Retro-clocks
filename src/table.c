/* @Author: Daniil Maslov */

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
COORD AngleRightTop;
HANDLE HStdOut;
CONSOLE_SCREEN_BUFFER_INFO CsbInfo;

void computeAngleValues();
void drawTable();
ConsoleSize getSizeOfConsole();
void drawRow(short length, COORD startPosition);
void drawColumn(short numberOfIterations, COORD startPosition);

void drawTable()
{
    computeAngleValues();
    ConsoleSize consoleSize = getSizeOfConsole();

    drawRow(consoleSize.right, AngleLeftTop);
    drawRow(consoleSize.right, AngleLeftBottom);
    drawColumn((++consoleSize.bottom), AngleLeftTop);
    drawColumn((++consoleSize.bottom), AngleRightTop);
}

void computeAngleValues()
{
    ConsoleSize consoleSize = getSizeOfConsole();
    
    AngleLeftTop.X = 0;
    AngleLeftTop.Y = 0;
    AngleLeftBottom.X = consoleSize.left;
    AngleLeftBottom.Y = consoleSize.bottom;
    AngleRightTop.X = consoleSize.right;
    AngleRightTop.Y = 0;
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

void drawColumn(short numberOfIterations, COORD startPosition)
{
    long unsigned int cWrittenChars;

    for (int i = 0; i < numberOfIterations; ++i)
    {
        startPosition.Y = i;
        FillConsoleOutputCharacter(HStdOut, (TCHAR)CHAR_COLUMN, 1, startPosition, &cWrittenChars);
    }
}