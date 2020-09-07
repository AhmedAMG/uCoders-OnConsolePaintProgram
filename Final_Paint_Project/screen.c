/*               uCoders                     */
/* Paint Program (Third Part in the Project) */
/*           Team number : 2                 */
/*      IDs: 2 - 4 - 10 - 14 - 41            */
/* Team Leader: Ahmed Mohammed Gamal Al-Din  */
/*       Release Date : 16/8/2019            */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "screen.h"
#include "mouse_and_keyboard.h"
#include "figures.h"
#include "mainFunctions.h"

void gotoxy(int x, int y)
{
    HANDLE consoleOutput;
    COORD cursorPosition;

    //New coordinates
    cursorPosition.X = x;
    cursorPosition.Y = y;

    //Create the object for the cursor
    consoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

    //Change the position of the cursor
    SetConsoleCursorPosition(consoleOutput,cursorPosition);
}

//Return True when the "mouse" click is within the "zone" passed to take action accordingly
int cmpZone(MOUSE* mouse,REGION* zone){
    if(mouse->point.x <= zone->bottomRight.x && mouse->point.x >= zone->upperLeft.x &&
       mouse->point.y <= zone->bottomRight.y && mouse->point.y >= zone->upperLeft.y){
        return 1;
       }else return 0;
}

//Clear 30 lines from the command section (27 in width)
void clearCommandSection(void){
    int i = 0;
    gotoxy(0,0);
    for(i = 0; i < 30; i++)
    printf("                          \n");
    gotoxy(0,0);
}

//Used when the "clear" button is pressed to wipe all printed shapes in the drawing section
void clearWorkingSection(void){
    int i = 0, j = 0;
    gotoxy(26,0);
    for(i = 0; i < 40; i++){
        for(j = 0; j < 170; j++) printf(" ");
        printf("\n");
    }
    gotoxy(0,0);
}
