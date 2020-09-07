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
#include <math.h>
#include "screen.h"
#include "mouse_and_keyboard.h"
#include "figures.h"
#include "mainFunctions.h"

///drawLine is commented well and the rest of the functions have the same concepts in drawLine function

void drawLine(LINE* line, int arrow, int firstTime){
    int i = 0;

    //Static variables to remember the last values the function had before it returns
    static int d = 0;
    static int orientation = 0;
    static int x = 80;
    static int y = 10;

    ///Update "x" and "y" according to the arrow passed  ----> LABEL:1
    if(arrow == Up) y--;
    else if(arrow == Down) y++;
    else if(arrow == Right) x++;
    else x--;

    //If it is the first time calling the function for that specific object "line", then know its required orientation
    //and its required length
    if(firstTime == 1){

        //Restore the default values for "x" and "y" to create the new object in
        x = 80;
        y = 10;

        printf("1.Horizontal\n2.Vertical\n");
        fflush(stdin);
        orientation = getch() - '0';

        printf("\nEnter the length:\n");
        //Scanf is a must here where the length may consists of more than one digit
        scanf("%d",&d);
        line->length = d;
    }else{
        //If it is NOT the first time, then you have just to move the previously created object "line"

        //Handle both orientations and prohibit any further movements that lead to crossing the borders of the console
        //Borders here are : x > 27 and y >= 0
        //Other borders depend on the orientation: x + length , y + length
        if(orientation == Horizontal){
            if(x <= 27 || x + d >= 173 || y <= 0 || y >= 40){
                //Wanted to cross the borders so ignore the command to move the line
                clearCommandSection();

                ///UNDO What has been done in LABEL:1
                if(arrow == Up) y++;
                else if(arrow == Down) y--;
                else if(arrow == Right) x--;
                else x++;

                return;
            }
        }else if(orientation == Vertical){
            if(x <= 27 || x >= 173 || y <= 0 || y + d >= 42){
                //Wanted to cross the borders so ignore the command to move the line
                clearCommandSection();

                ///UNDO What has been done in LABEL:1
                if(arrow == Up) y++;
                else if(arrow == Down) y--;
                else if(arrow == Right) x--;
                else x++;

                return;
            }
        }

        //Erase the old previously printed line by printing a " " (space) to the same places it is drawn in
        ///This is EXACTLY the same as what in LABEL:2 underneath but with "spaces" instead of other characters
        if(orientation == Horizontal){
            gotoxy(line->point.x,line->point.y);
            for(i = 0; i < d; i++)
                printf(" ");
        }else if(orientation == Vertical){
            for(i = 0; i < d; i++){
                gotoxy(line->point.x,line->point.y+i);
                printf(" ");
            }
        }
    }

    //Update the real coordinates in the line structure to be drawn accordingly
    line->point.x = x;
    line->point.y = y;

    ///Draw the line with the new coordinates   ---> This is LABEL:2
    gotoxy(line->point.x,line->point.y);
    if(orientation == Horizontal){
        line->orientation = Horizontal;
        for(i = 0; i < d; i++)
            printf("-");
    }else if(orientation == Vertical){
        line->orientation = Vertical;
        for(i = 0; i < d; i++){
            printf("|");
            gotoxy(line->point.x,line->point.y+i);
        }

    }else{ //Should NOT be here AT ALL
        printf("Invalid input\n");
    }

    //Clear the command section not to make the bar to be scrolled down
    clearCommandSection();

}

void drawRectangle(RECTANGLE* rectangle, int arrow, int firstTime){
    int i = 0;
    static int width = 0;
    static int length = 0;
    static int x = 80;
    static int y = 10;

    if(arrow == Up) y--;
    else if(arrow == Down) y++;
    else if(arrow == Right) x++;
    else x--;

    if(firstTime == 1){
        x = 80;
        y = 10;

        printf("\nEnter the length:\n");
        scanf("%d",&length);
        rectangle->length = length;

        printf("\nEnter the width:\n");
        scanf("%d",&width);
        rectangle->width = width;
    }else{
        if(x <= 27 || x + width >= 172 || y <= 0 || y + length >= 40){
            clearCommandSection();
            if(arrow == Up) y++;
            else if(arrow == Down) y--;
            else if(arrow == Right) x--;
            else x++;

            return;
        }

        gotoxy(rectangle->point.x,rectangle->point.y);
        for(i = 0; i < width; i++)
            printf(" ");
        gotoxy(rectangle->point.x,rectangle->point.y+length);
        for(i = 0; i < width; i++)
            printf(" ");

        for(i = 0; i < length+1; i++){
            printf(" ");
            gotoxy(rectangle->point.x,rectangle->point.y+i);
        }
        gotoxy(rectangle->point.x+width,rectangle->point.y);
        for(i = 0; i < length+1; i++){
            printf(" ");
            gotoxy(rectangle->point.x+width,rectangle->point.y+i);
        }
    }

    rectangle->point.x = x;
    rectangle->point.y = y;

    gotoxy(rectangle->point.x,rectangle->point.y);
    for(i = 0; i < width; i++)
        printf("-");
    gotoxy(rectangle->point.x,rectangle->point.y+length);
    for(i = 0; i < width; i++)
        printf("-");

    for(i = 0; i < length+2; i++){
        printf("|");
        gotoxy(rectangle->point.x,rectangle->point.y+i);
    }
    gotoxy(rectangle->point.x+width,rectangle->point.y);
    for(i = 0; i < length+1; i++){
        printf("|");
        gotoxy(rectangle->point.x+width,rectangle->point.y+i);
    }

    clearCommandSection();
}

void drawSquare(SQUARE* square, int arrow, int firstTime){
    int i = 0;
    static int length = 0;
    static int width = 0;
    static int x = 80;
    static int y = 10;

    if(arrow == Up) y--;
    else if(arrow == Down) y++;
    else if(arrow == Right) x++;
    else x--;

    if(firstTime == 1){
        x = 80;
        y = 10;

        printf("\nEnter the length:\n");
        scanf("%d",&length);
        square->length = length;
        width = 2*length;
    }else{
        if(x <= 27 || x + width >= 172 || y <= 0 || y + length >= 40){
            clearCommandSection();
            if(arrow == Up) y++;
            else if(arrow == Down) y--;
            else if(arrow == Right) x--;
            else x++;

            return;
        }

        gotoxy(square->point.x,square->point.y);
        for(i = 0; i < width; i++)
            printf(" ");
        gotoxy(square->point.x,square->point.y+length);
        for(i = 0; i < width; i++)
            printf(" ");

        for(i = 0; i < length+1; i++){
            printf(" ");
            gotoxy(square->point.x,square->point.y+i);
        }
        gotoxy(square->point.x+width,square->point.y);
        for(i = 0; i < length+1; i++){
            printf(" ");
            gotoxy(square->point.x+width,square->point.y+i);
        }
    }

    square->point.x = x;
    square->point.y = y;

    gotoxy(square->point.x,square->point.y);
    for(i = 0; i < width; i++)
        printf("-");
    gotoxy(square->point.x,square->point.y+length);
    for(i = 0; i < width; i++)
        printf("-");

    for(i = 0; i < length+2; i++){
        printf("|");
        gotoxy(square->point.x,square->point.y+i);
    }
    gotoxy(square->point.x+width,square->point.y);
    for(i = 0; i < length+1; i++){
        printf("|");
        gotoxy(square->point.x+width,square->point.y+i);
    }

    clearCommandSection();
}

void drawTriangle(TRIANGLE* triangle, int arrow, int firstTime){
    int i = 0, j = 0;
    static int height = 0;
    static int x = 100;
    static int y = 10;

    if(arrow == Up) y--;
    else if(arrow == Down) y++;
    else if(arrow == Right) x++;
    else x--;

    if(firstTime == 1){
        x = 100;
        y = 10;

        printf("\nEnter the height:\n");
        scanf("%d",&height);
        triangle->height = height;

    }else{
        if(x - 1 <= 27 || x + 2*height >= 172 || y <= -1 || y + height >= 40){ //NOT LOGICAL AT ALL !!!
            clearCommandSection();
            if(arrow == Up) y++;
            else if(arrow == Down) y--;
            else if(arrow == Right) x--;
            else x++;

            return;
        }

        gotoxy(triangle->point.x,triangle->point.y);
        for(i = 0; i < height+1; i++){
            gotoxy(triangle->point.x,triangle->point.y+i);
            for(j = 0; j < height-i; j++){
                printf(" ");
            }
            for(j = 0; j < 2*i-1; j++){
                printf(" ");
            }
        }
        gotoxy(triangle->point.x-1,triangle->point.y+i);
        for(j = 0; j < 2*i-1; j++) printf(" ");
    }

    triangle->point.x = x;
    triangle->point.y = y;

    gotoxy(triangle->point.x,triangle->point.y);
    for(i = 0; i < height+1; i++){
        gotoxy(triangle->point.x,triangle->point.y+i);
        for(j = 0; j < height-i; j++){
            printf(" ");
        }
        for(j = 0; j < 2*i-1; j++){
            if(j == 0 || j == 2*i-2) printf("*");
            else printf(" ");
        }
    }
    gotoxy(triangle->point.x-1,triangle->point.y+i);
    for(j = 0; j < 2*i-1; j++) printf("*");

    clearCommandSection();
}

void drawCircle(CIRCLE* circle, int arrow, int firstTime){
    int i = 0, j = 0;
    static int radius = 0;
    static int x = 80;
    static int y = 5;

    if(arrow == Up) y--;
    else if(arrow == Down) y++;
    else if(arrow == Right) x++;
    else x--;

    if(firstTime == 1){
        x = 80;
        y = 5;

        printf("\nEnter the radius:\n");
        scanf("%d",&radius);
        circle->radius = radius;

    }else{
        if(x - 1 <= 26 || x + 2*radius >= 172 || y <= -1 || y + 2*radius >= 40){ //NOT LOGICAL AT ALL !!!
            clearCommandSection();
            if(arrow == Up) y++;
            else if(arrow == Down) y--;
            else if(arrow == Right) x--;
            else x++;

            return;
        }

        for (i=0; i<=2*radius; i++)
        {
            gotoxy(circle->point.x,circle->point.y+i);
            for (j=0; j<=2*radius; j++)
            {
                double distance = sqrt((double)(i-radius)*(i-radius) + (j-radius)*(j-radius));
                if (distance>radius-0.5 && distance<radius+0.5) printf(" ");
                else printf(" ");
            }
        }
    }

    circle->point.x = x;
    circle->point.y = y;

    gotoxy(circle->point.x,circle->point.y);
    for (i=0; i<=2*radius; i++)
    {
        gotoxy(circle->point.x,circle->point.y+i);
        for (j=0; j<=2*radius; j++)
        {
            double distance = sqrt((double)(i-radius)*(i-radius) + (j-radius)*(j-radius));
            if (distance>radius-0.5 && distance<radius+0.5) printf("*");
            else printf(" ");
        }
    }

    clearCommandSection();
}

