/*               uCoders                     */
/* Paint Program (Third Part in the Project) */
/*           Team number : 2                 */
/*      IDs: 2 - 4 - 10 - 14 - 41            */
/* Team Leader: Ahmed Mohammed Gamal Al-Din  */
/*       Release Date : 16/8/2019            */

#ifndef __MOUSE_AND_KEYBOARD_H_
#define __MOUSE_AND_KEYBOARD_H_
#include <windows.h>
#include "mainFunctions.h"

typedef struct{
    unsigned char buttonPressed;
    //Save the point (Coordinates) of the mouse when clicking on anything inside the console window
    POINT point;
}MOUSE;

//Update the whole structure object with the position and state if needed
//Update the position(point) of the MOUSE object with the coordinates the mouse actually clicked on
void updateMouse(MOUSE*);

//Update the whole structure object with the position and state if needed
//Update the position(point) of the MOUSE object with the coordinates the mouse actually clicked on
//Get the next event whether it is a mouse event or keyboard event
void updateMouseAndKeyboard(MOUSE* m);

//Determine whether the keyboard event was pressing the key or releasing it
int KeyEventProc(KEY_EVENT_RECORD ker);

#endif // __MOUSE_AND_KEYBOARD_H_

