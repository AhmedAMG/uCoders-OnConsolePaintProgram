/*               uCoders                     */
/* Paint Program (Third Part in the Project) */
/*           Team number : 2                 */
/*      IDs: 2 - 4 - 10 - 14 - 41            */
/* Team Leader: Ahmed Mohammed Gamal Al-Din  */
/*       Release Date : 16/8/2019            */

#ifndef __SCREEN_H_
#define __SCREEN_H_
#include <windows.h>
#include "mouse_and_keyboard.h"

///The console dimensions : 0 < x < 173 and 0 < y < 41

//To define the regions of colors, rubber and buttons
typedef struct{
    POINT upperLeft;
    POINT bottomRight;
}REGION;

//Clear the drawing section (The right part)
void clearWorkingSection(void);

//Clear the command section (The left part)
void clearCommandSection(void);

//Change the position of the cursor to be able to paint wherever the user points with the mouse
void gotoxy(int x, int y);

//To know in which area the click has happened
int cmpZone(MOUSE* mouse,REGION* zone);

#endif // __SCREEN_H_
