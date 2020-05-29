/*
 * @Author: Daniil Maslov
 * @CreationDate: 21.05.2020
 * @LastUpdate: 24.05.2020 
 * 
 * TODO оно не хочет работать с нулями в минутах. я там ошибку сделал в compute функциях
 */

#include <windows.h>
#include <stdio.h>
#include <stdbool.h>

#include "table.c"
#include "shapes.c"
#include "time.c"


void main()
{
    HStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(HStdOut, &CsbInfo);

    system("cls");
    computeAngleValues();
    drawTable();

    cycleTime();

}