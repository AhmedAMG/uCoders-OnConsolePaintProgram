/*               uCoders                     */
/* Paint Program (Third Part in the Project) */
/*           Team number : 2                 */
/*      IDs: 2 - 4 - 10 - 14 - 41            */
/* Team Leader: Ahmed Mohammed Gamal Al-Din  */
/*       Release Date : 16/8/2019            */

///The paint program has TWO modes to operate: Free Paint - Geometrical Figures

///In Free paint mode: User can draw whatever he wants using the mouse
///Available colors are SEVEN colors to draw with
///A rubber is available also to erase anything has been drawn
///TWO buttons are available: "Home" to return to the main menu - "Clear" to start a new painting

///In geometrical figures: User can draw FIVE available shapes: Lines, Rectangles, Squares, Triangles and circles
///Available colors are SEVEN colors to draw with
///Any shape can be MOVED using arrows after it is drawn immediately
///TWO buttons are available: "Home" to return to the main menu - "Clear" to start a new painting

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "screen.h"
#include "figures.h"
#include "mouse_and_keyboard.h"

int main()
{
    MOUSE* mouse = (MOUSE*)malloc(sizeof(MOUSE));

    //Maximize the console size
    system("MODE 1000,1000");

    while(1){
        //Make the cursor color to be red
        system("color 0C");

        //Show the main menu with "Free paint", "Geometrical figures" and "Exit" sections
        menu();

        //Get the mouse action and the point where the click occurs in the console
        updateMouse(mouse);

        //Check the y coordinate where this is the distinguishable coordinate and the separator between
        //the 3 sections and take decisions according to the section chosen
        if(mouse->point.y <= 13){
            ///Free Paint
            //Clear the screen and start the free paint function with specifying the reason of the call
            system("cls");

            //There are two modes inside the free paint function:
            //Passing ZERO to indicate that the calling is due to user choice from main menu.
            //Passing ONE to indicate that the calling is due to just clearing the screen to have a new drawing
            freePaint(0);
        }else if(mouse->point.y >= 26){
            ///Exit
            //Freeing the allocated memory for the mouse object and close the whole program
            free(mouse);
            return 0;
        }else{
            ///Geometrical figures
            //Clearing the screen and start the geometrical figures function with specifying the reason of the call
            system("cls");

            //There are two modes inside the geometrical figures function:
            //Passing ZERO to indicate that the calling is due to user choice from main menu.
            //Passing ONE to indicate that the calling is due to just clearing the screen to have a new drawing
            geometricalFigures(0);
        }
    }

    return 0;
}
