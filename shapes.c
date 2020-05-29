/* @Author: Daniil Maslov */

#define SHORT_LINE_LENGTH 6
#define SHORT_LINE_LENGTH_MINUS_TWO 4
#define LONG_LINE_LENGTH 12
#define CHAR_NUMBERS 177
#define DOT 2

void drawZero(COORD startPosition);
void drawOne(COORD startPosition);
void drawTwo(COORD startPosition);
void drawThree(COORD startPosition);
void drawFour(COORD startPosition);
void drawFive(COORD startPosition);
void drawSix(COORD startPosition);
void drawSeven(COORD startPosition);
void drawEight(COORD startPosition);
void drawNine(COORD startPosition);
void drawShortVerticalLine(COORD startPosition);
void drawLongVerticalLine(COORD startPosition);
void drawShortHorizontalLine(COORD startPosition);
void drawAnyLengthHorizontalLine(COORD startPosition, short length);

void drawZero(COORD startPosition)
{
    drawShortHorizontalLine(startPosition);
    startPosition.Y += LONG_LINE_LENGTH;
    drawShortHorizontalLine(startPosition);
    
    startPosition.Y -= LONG_LINE_LENGTH;
    drawLongVerticalLine(startPosition);
    startPosition.X += SHORT_LINE_LENGTH_MINUS_TWO;
    drawLongVerticalLine(startPosition);
}

void drawOne(COORD startPosition)
{
    drawAnyLengthHorizontalLine(startPosition, 4);
    startPosition.X += 2;
    startPosition.Y += 1;
    drawLongVerticalLine(startPosition);   
}

void drawTwo(COORD startPosition)
{
    for (int j = 0; j < 3; ++j)
    {
        drawShortHorizontalLine(startPosition);
        startPosition.Y += SHORT_LINE_LENGTH;
    }
    for (int j = 0; j < 3; ++j)
        startPosition.Y -= SHORT_LINE_LENGTH;
    
    startPosition.X += SHORT_LINE_LENGTH_MINUS_TWO;
    drawShortVerticalLine(startPosition);
    startPosition.X -= SHORT_LINE_LENGTH_MINUS_TWO;
    startPosition.Y += SHORT_LINE_LENGTH;
    drawShortVerticalLine(startPosition);

}

void drawThree(COORD startPosition)
{
    for (int j = 0; j < 3; ++j)
    {
        drawShortHorizontalLine(startPosition);
        startPosition.Y += SHORT_LINE_LENGTH;
    }
    for (int j = 0; j < 3; ++j)
        startPosition.Y -= SHORT_LINE_LENGTH;

    startPosition.X += SHORT_LINE_LENGTH_MINUS_TWO;
    drawLongVerticalLine(startPosition);
}

void drawFour(COORD startPosition)
{
    drawShortVerticalLine(startPosition);
    startPosition.Y += SHORT_LINE_LENGTH;
    drawShortHorizontalLine(startPosition);

    startPosition.Y -= SHORT_LINE_LENGTH;
    startPosition.X += (SHORT_LINE_LENGTH - 2);
    drawShortVerticalLine(startPosition);
    startPosition.Y += (SHORT_LINE_LENGTH + 1);
    drawShortVerticalLine(startPosition);
}

void drawFive(COORD startPosition)
{
    for (int j = 0; j < 3; ++j)
    {
        drawShortHorizontalLine(startPosition);
        startPosition.Y += SHORT_LINE_LENGTH;
    }
    for (int j = 0; j < 3; ++j)
        startPosition.Y -= SHORT_LINE_LENGTH;
    
    drawShortVerticalLine(startPosition);
    startPosition.X += SHORT_LINE_LENGTH_MINUS_TWO;
    startPosition.Y += SHORT_LINE_LENGTH;
    drawShortVerticalLine(startPosition);
}

void drawSix(COORD startPosition)
{
    for (int j = 0; j < 3; ++j)
    {
        drawShortHorizontalLine(startPosition);
        startPosition.Y += SHORT_LINE_LENGTH;
    }
    for (int j = 0; j < 3; ++j)
        startPosition.Y -= SHORT_LINE_LENGTH;
    
    drawLongVerticalLine(startPosition);
    startPosition.Y += SHORT_LINE_LENGTH;
    startPosition.X += SHORT_LINE_LENGTH_MINUS_TWO;
    drawShortVerticalLine(startPosition);
}

void drawSeven(COORD startPosition)
{
    drawShortHorizontalLine(startPosition);
    startPosition.X += SHORT_LINE_LENGTH_MINUS_TWO;
    startPosition.Y += 1;
    drawLongVerticalLine(startPosition);

    startPosition.Y += 5;
    startPosition.X -= 2;
    drawShortHorizontalLine(startPosition);
}

void drawEight(COORD startPosition)
{
    for (int j = 0; j < 3; ++j)
    {
        drawShortHorizontalLine(startPosition);
        startPosition.Y += SHORT_LINE_LENGTH;
    }
    for (int j = 0; j < 3; ++j)
        startPosition.Y -= SHORT_LINE_LENGTH;
    
    drawLongVerticalLine(startPosition);
    startPosition.X += SHORT_LINE_LENGTH_MINUS_TWO;
    drawLongVerticalLine(startPosition);
}

void drawNine(COORD startPosition)
{
   for (int j = 0; j < 3; ++j)
    {
        drawShortHorizontalLine(startPosition);
        startPosition.Y += SHORT_LINE_LENGTH;
    }
    for (int j = 0; j < 3; ++j)
        startPosition.Y -= SHORT_LINE_LENGTH;

    drawShortVerticalLine(startPosition);
    startPosition.X += SHORT_LINE_LENGTH_MINUS_TWO;
    drawLongVerticalLine(startPosition);

}

void drawShortVerticalLine(COORD startPosition)
{
    long unsigned int cWrittenChars;

    for (int j = 0; j < SHORT_LINE_LENGTH; ++j)
    {
        FillConsoleOutputCharacter(HStdOut, (TCHAR)CHAR_NUMBERS, DOT, startPosition, &cWrittenChars);
        ++startPosition.Y;
    }
}

void drawLongVerticalLine(COORD startPosition)
{
    long unsigned int cWrittenChars;

    for (int j = 0; j < LONG_LINE_LENGTH; ++j)
    {
        FillConsoleOutputCharacter(HStdOut, (TCHAR)CHAR_NUMBERS, DOT, startPosition, &cWrittenChars);
        ++startPosition.Y;
    }
}

void drawShortHorizontalLine(COORD startPosition)
{
    long unsigned int cWrittenChars;

    FillConsoleOutputCharacter(HStdOut, (TCHAR)CHAR_NUMBERS, SHORT_LINE_LENGTH, startPosition, &cWrittenChars);
}

void drawAnyLengthHorizontalLine(COORD startPosition, short length)
{
    long unsigned int cWrittenChars;

    FillConsoleOutputCharacter(HStdOut, (TCHAR)CHAR_NUMBERS, length, startPosition, &cWrittenChars);
}