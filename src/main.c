/* @Author: Daniil Maslov */

#include <windows.h>
#include <stdio.h>
#include <stdbool.h>

#include "shapes.c"
#include "time.c"


void main()
{
    HStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(HStdOut, &CsbInfo);
    SetConsoleTitle("Pretty clocks");
    system("cls");
    cycleDrawTime();

}