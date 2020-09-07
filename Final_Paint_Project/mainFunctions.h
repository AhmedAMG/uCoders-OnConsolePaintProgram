/*               uCoders                     */
/* Paint Program (Third Part in the Project) */
/*           Team number : 2                 */
/*      IDs: 2 - 4 - 10 - 14 - 41            */
/* Team Leader: Ahmed Mohammed Gamal Al-Din  */
/*       Release Date : 16/8/2019            */

#ifndef __MAINFUNCTIONS_H_
#define __MAINFUNCTIONS_H_

typedef enum{
    Shape_Line = 1, Shape_Square = 2, Shape_Rectangle = 3, Shape_Triangle = 4, Shape_Circle = 5
}SHAPE;

//Colors numbers in the the console
typedef enum{
    Blue = 9, Green = 10, Aqua = 11, Red = 12, Purple = 13, Yellow = 14, White = 15, Rubber = 0
}STATE;

//Draw the welcome screen with the 3 options: Free paint - Geometrical figures - Exit
void menu(void);

//Draw the free paint screen with the control buttons and handle everything within it
void freePaint(int clearCheck);

//Draw the geometrical figures screen that will interact with the user through keyboard and mouse and handle everything within it
void geometricalFigures(int clearCheck);

#endif // __MAINFUNCTIONS_H_
