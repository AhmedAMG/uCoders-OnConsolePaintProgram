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

//Update the whole structure object with the position and state if needed
//Update the position(point) of the MOUSE object with the coordinates the mouse actually clicked on
void updateMouse(MOUSE* m){
    HANDLE in = GetStdHandle(STD_INPUT_HANDLE);
    DWORD mode;
    DWORD read;

    //Create an object of the input record structure saving all info about the event happened
    INPUT_RECORD go[1];

    BOOL buttonMouseValidate = FALSE;

    GetConsoleMode(in, &mode);
    SetConsoleMode(in, (mode | ENABLE_MOUSE_INPUT) & ~ENABLE_QUICK_EDIT_MODE & ~ENABLE_INSERT_MODE);

    //Keep checking for a mouse event to process it
    while(!buttonMouseValidate){
        ReadConsoleInput(in, go, 1, &read);
        //Check if the event happened is due to the mouse not any other input device
        if(go[0].EventType == MOUSE_EVENT){
            if((buttonMouseValidate = go[0].Event.MouseEvent.dwButtonState) == FROM_LEFT_1ST_BUTTON_PRESSED)
                //Left button of the mouse
                m->buttonPressed = 1;
            else if((buttonMouseValidate = go[0].Event.MouseEvent.dwButtonState) == RIGHTMOST_BUTTON_PRESSED)
                //Right button of the mouse
                m->buttonPressed = -1;

            if(buttonMouseValidate){
                //Update the point clicked in the mouse object passed to the function
                m->point.x = go[0].Event.MouseEvent.dwMousePosition.X;
                m->point.y = go[0].Event.MouseEvent.dwMousePosition.Y;

            }
        }
    }
    //SetConsoleMode(in, mode);
}

//Update the whole structure object with the position and state if needed
//Update the position(point) of the MOUSE object with the coordinates the mouse actually clicked on
//Get the next event whether it is a mouse event or keyboard event
void updateMouseAndKeyboard(MOUSE* m){
    HANDLE in = GetStdHandle(STD_INPUT_HANDLE);
    DWORD mode;
    DWORD read;

    //Create an object of the input record structure saving all info about the event happened
    INPUT_RECORD go[1];

    BOOL buttonMouseValidate = FALSE;

    GetConsoleMode(in, &mode);
    SetConsoleMode(in, (mode | ENABLE_MOUSE_INPUT) & ~ENABLE_QUICK_EDIT_MODE & ~ENABLE_INSERT_MODE);

    //Keep checking for a mouse event to process it
    while(!buttonMouseValidate)
    {
        ReadConsoleInput(in, go, 1, &read);
        //Check if the event happened is due to the mouse not any other input device
        if(go[0].EventType == MOUSE_EVENT){
            if((buttonMouseValidate = go[0].Event.MouseEvent.dwButtonState) == FROM_LEFT_1ST_BUTTON_PRESSED)
                //Left button of the mouse
                m->buttonPressed = 1;
            else if((buttonMouseValidate = go[0].Event.MouseEvent.dwButtonState) == RIGHTMOST_BUTTON_PRESSED)
                //Right button of the mouse
                m->buttonPressed = -1;

            if(buttonMouseValidate){
                //Update the point clicked in the mouse object passed to the function
                m->point.x = go[0].Event.MouseEvent.dwMousePosition.X;
                m->point.y = go[0].Event.MouseEvent.dwMousePosition.Y;
            }
        }else if(go[0].EventType ==  KEY_EVENT){
            //Only break when the even of the keyboard was pressing the key not releasing it
            //Not to take 2 actions upon on press cause each press will be followed by a release
            if(KeyEventProc(go[0].Event.KeyEvent)) break;
        }
    }
}

//Determine whether the keyboard event was pressing the key or releasing it
int KeyEventProc(KEY_EVENT_RECORD ker){
    if(ker.bKeyDown) return 1;
    else return 0;
}
