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

//Called in the program launch and when the "Home" button is pressed
void menu(void){
    system("cls");
    gotoxy(81,6);
    printf("Free Paint");

    //Draw the horizontal line separating sections
    int i = 0;
    system("color 0C");
    while(i<172){
        gotoxy(i++,13);
        printf("%c",220);
    }

    gotoxy(78,20);
    printf("Geometrical Figures");

    //Draw the horizontal line separating sections
    i = 0;
    system("color 0C");
    while(i<172){
        gotoxy(i++,26);
        printf("%c",220);
    }

    gotoxy(85,33);
    printf("Exit");
    gotoxy(0,0);
}

void freePaint(int clearCheck){
    MOUSE* mouse = (MOUSE*)malloc(sizeof(MOUSE));

    //Draw the vertical line separating drawing section and the control section
    int i = 0;
    system("color 0C");
    while(i<40){
        gotoxy(145,i++);
        printf("|");
    }

    //Handler for the cursor
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    //Creating the colors regions in the control section
    SetConsoleTextAttribute(hConsole,Blue);
    gotoxy(152,3);
    printf("%c%c%c%c%c",219,219,219,219,219);
    gotoxy(152,4);
    printf("%c%c%c%c%c",219,219,219,219,219);
    gotoxy(152,5);
    printf("%c%c%c%c%c",219,219,219,219,219);
    gotoxy(152,6);
    printf("Blue");


    SetConsoleTextAttribute(hConsole,Green);
    gotoxy(162,3);
    printf("%c%c%c%c%c",219,219,219,219,219);
    gotoxy(162,4);
    printf("%c%c%c%c%c",219,219,219,219,219);
    gotoxy(162,5);
    printf("%c%c%c%c%c",219,219,219,219,219);
    gotoxy(162,6);
    printf("Green");


    SetConsoleTextAttribute(hConsole,Aqua);
    gotoxy(152,7);
    printf("%c%c%c%c%c",219,219,219,219,219);
    gotoxy(152,8);
    printf("%c%c%c%c%c",219,219,219,219,219);
    gotoxy(152,9);
    printf("%c%c%c%c%c",219,219,219,219,219);
    gotoxy(152,10);
    printf("Aqua");


    SetConsoleTextAttribute(hConsole,Red);
    gotoxy(162,7);
    printf("%c%c%c%c%c",219,219,219,219,219);
    gotoxy(162,8);
    printf("%c%c%c%c%c",219,219,219,219,219);
    gotoxy(162,9);
    printf("%c%c%c%c%c",219,219,219,219,219);
    gotoxy(162,10);
    printf("Red");


    SetConsoleTextAttribute(hConsole,Purple);
    gotoxy(152,11);
    printf("%c%c%c%c%c",219,219,219,219,219);
    gotoxy(152,12);
    printf("%c%c%c%c%c",219,219,219,219,219);
    gotoxy(152,13);
    printf("%c%c%c%c%c",219,219,219,219,219);
    gotoxy(152,14);
    printf("Purple");


    SetConsoleTextAttribute(hConsole,Yellow);
    gotoxy(162,11);
    printf("%c%c%c%c%c",219,219,219,219,219);
    gotoxy(162,12);
    printf("%c%c%c%c%c",219,219,219,219,219);
    gotoxy(162,13);
    printf("%c%c%c%c%c",219,219,219,219,219);
    gotoxy(162,14);
    printf("Yellow");


    SetConsoleTextAttribute(hConsole,White);
    gotoxy(152,15);
    printf("%c%c%c%c%c",219,219,219,219,219);
    gotoxy(152,16);
    printf("%c%c%c%c%c",219,219,219,219,219);
    gotoxy(152,17);
    printf("%c%c%c%c%c",219,219,219,219,219);
    gotoxy(152,18);
    printf("White");


    SetConsoleTextAttribute(hConsole,White);
    gotoxy(162,15);
    printf("%c%c%c%c%c",177,177,177,177,177);
    gotoxy(162,16);
    printf("%c%c%c%c%c",177,177,177,177,177);
    gotoxy(162,17);
    printf("%c%c%c%c%c",177,177,177,177,177);
    gotoxy(162,18);
    SetConsoleTextAttribute(hConsole,8);
    printf("Rubber");


    //Creating the 2 buttons of home and clear
    SetConsoleTextAttribute(hConsole,White);
    gotoxy(162,23);
    printf("---------");
    gotoxy(162,24);
    printf("| Clear |");
    gotoxy(162,25);
    printf("---------");

    SetConsoleTextAttribute(hConsole,White);
    gotoxy(150,23);
    printf("--------");
    gotoxy(150,24);
    printf("| Home |");
    gotoxy(150,25);
    printf("--------");
    gotoxy(0,0);


    //Create a REGION object for each color and each button in order to have the ability to know regions dimensions
    //to know when the mouse clicks on any of them
    REGION* BlueZone = (REGION*)malloc(sizeof(REGION));
    BlueZone->upperLeft.x = 152;
    BlueZone->upperLeft.y = 3;
    BlueZone->bottomRight.x = 157;
    BlueZone->bottomRight.y = 6;

    REGION* GreenZone = (REGION*)malloc(sizeof(REGION));
    GreenZone->upperLeft.x = 162;
    GreenZone->upperLeft.y = 3;
    GreenZone->bottomRight.x = 167;
    GreenZone->bottomRight.y = 6;

    REGION* AquaZone = (REGION*)malloc(sizeof(REGION));
    AquaZone->upperLeft.x = 152;
    AquaZone->upperLeft.y = 7;
    AquaZone->bottomRight.x = 157;
    AquaZone->bottomRight.y = 10;

    REGION* RedZone = (REGION*)malloc(sizeof(REGION));
    RedZone->upperLeft.x = 162;
    RedZone->upperLeft.y = 7;
    RedZone->bottomRight.x = 167;
    RedZone->bottomRight.y = 10;

    REGION* PurpleZone = (REGION*)malloc(sizeof(REGION));
    PurpleZone->upperLeft.x = 152;
    PurpleZone->upperLeft.y = 11;
    PurpleZone->bottomRight.x = 157;
    PurpleZone->bottomRight.y = 14;

    REGION* YellowZone = (REGION*)malloc(sizeof(REGION));
    YellowZone->upperLeft.x = 162;
    YellowZone->upperLeft.y = 11;
    YellowZone->bottomRight.x = 167;
    YellowZone->bottomRight.y = 14;

    REGION* WhiteZone = (REGION*)malloc(sizeof(REGION));
    WhiteZone->upperLeft.x = 152;
    WhiteZone->upperLeft.y = 15;
    WhiteZone->bottomRight.x = 157;
    WhiteZone->bottomRight.y = 18;

    REGION* RubberZone = (REGION*)malloc(sizeof(REGION));
    RubberZone->upperLeft.x = 162;
    RubberZone->upperLeft.y = 15;
    RubberZone->bottomRight.x = 167;
    RubberZone->bottomRight.y = 18;

    REGION* HomeZone = (REGION*)malloc(sizeof(REGION));
    HomeZone->upperLeft.x = 150;
    HomeZone->upperLeft.y = 23;
    HomeZone->bottomRight.x = 158;
    HomeZone->bottomRight.y = 25;

    REGION* ClearZone = (REGION*)malloc(sizeof(REGION));
    ClearZone->upperLeft.x = 162;
    ClearZone->upperLeft.y = 23;
    ClearZone->bottomRight.x = 171;
    ClearZone->bottomRight.y = 25;

    //Gather all of these region zones into one array to make dealing with them more easily
    REGION* zones[10] = {BlueZone,GreenZone,AquaZone,RedZone,PurpleZone,YellowZone,WhiteZone,RubberZone,HomeZone,ClearZone};

    //Execute the following ONLY when the calling is NOT due to "clear" pressing
    if(clearCheck == 0){
        while(1){

            //Read the next click from the mouse to decide what should be done
            updateMouse(mouse);

            //If it is in the working space (the Left part) then just print '*' and draw where the mouse clicked
            if(mouse->point.x < 145){
                gotoxy(mouse->point.x,mouse->point.y);
                printf("*");
            }else{
                //If it is in the control section (the right part) then determine which region has been clicked on
                for(i = 0; i < 10; i++){
                    //Loop on the array of defined zones
                    if(cmpZone(mouse, *(zones+i))){
                        if(i <= 7){
                            //Change the color according to the color zone pressed on
                            if(i != 7) SetConsoleTextAttribute(hConsole,Blue+i);
                            //Change color to BLACK if the rubber is pressed on
                            else SetConsoleTextAttribute(hConsole,Rubber);
                        }else{
                            //Handling the buttons
                            if(i == 8){
                                //Home button is pressed
                                return;
                            }else{
                                //Clear button is pressed
                                //Passing one to return to here again after wiping everything and display the default layout only
                                system("cls");
                                freePaint(1);
                            }
                        }
                    }
                }
            }
        }
    }
}

void geometricalFigures(int clearCheck){
    int i = 0, choice = 0;
    SHAPE shape = 0;
    MOUSE* mouse = (MOUSE*)malloc(sizeof(MOUSE));

    //Initialization and never leave anything to the chance
    mouse->point.x = 0;
    mouse->point.y = 0;

    //Clear the screen to draw the separator of the geometrical figures screen
    system("cls");
    system("color 0C");
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    //Draw the vertical line that separates the command section and the working section
    while(i<40){
        gotoxy(26,i++);
        printf("|");
    }

    //Draw the Home and Clear buttons
    SetConsoleTextAttribute(hConsole,White);
    gotoxy(15,35);
    printf("---------");
    gotoxy(15,36);
    printf("| Clear |");
    gotoxy(15,37);
    printf("---------");

    SetConsoleTextAttribute(hConsole,White);
    gotoxy(2,35);
    printf("--------");
    gotoxy(2,36);
    printf("| Home |");
    gotoxy(2,37);
    printf("--------");
    gotoxy(0,0);

    //Create the regions objects for these two buttons
    REGION* HomeZone = (REGION*)malloc(sizeof(REGION));
    HomeZone->upperLeft.x = 2;
    HomeZone->upperLeft.y = 35;
    HomeZone->bottomRight.x = 10;
    HomeZone->bottomRight.y = 37;

    REGION* ClearZone = (REGION*)malloc(sizeof(REGION));
    ClearZone->upperLeft.x = 15;
    ClearZone->upperLeft.y = 35;
    ClearZone->bottomRight.x = 23;
    ClearZone->bottomRight.y = 37;

    //Execute the following ONLY when the calling is NOT due to "clear" pressing
    if(clearCheck == 0){
        while(1){
            //At the beginning, give to the user the ability to click on Home or Clear or to continue drawing
            SetConsoleTextAttribute(hConsole,White);
            printf("Home and Clear buttons\nare activated now:\n\nDo either of the following\nPress on any button\npress any key to continue\n");
            gotoxy(0,0);
            updateMouseAndKeyboard(mouse);

            //Detect whether the user has clicked on any button or not
            if(cmpZone(mouse,HomeZone)){
                mouse->point.x = 0;
                mouse->point.y = 0;
                system("cls");
                break;
            }else if(cmpZone(mouse,ClearZone)){
                mouse->point.x = 0;
                mouse->point.y = 0;
                geometricalFigures(1);
            }else{
                clearCommandSection();
                gotoxy(0,0);
                printf("Home and Clear buttons\nare deactivated now\n\n");
            }

            //From this point, clicking on the buttons are NOT allowed till a complete shape drawing is accomplished
            //Allocating some memory for the shapes to be drawn
            LINE *line = (LINE*)malloc(sizeof(LINE));
            SQUARE* square = (SQUARE*)malloc(sizeof(SQUARE));
            RECTANGLE* rectangle = (RECTANGLE*)malloc(sizeof(RECTANGLE));
            TRIANGLE* triangle = (TRIANGLE*)malloc(sizeof(TRIANGLE));
            CIRCLE* circle = (CIRCLE*)malloc(sizeof(CIRCLE));

            //Display the options to the user to choose the shape and its color
            SetConsoleTextAttribute(hConsole,White);
            printf("Choose which figure\nyou want to draw:\n");
            printf("1.Line\n2.Square\n3.Rectangle\n4.Triangle\n5.Circle\n\n");
            fflush(stdin);
            shape = getch() - '0';
            fflush(stdin);

            if(shape < 1 || shape > 5){
                clearCommandSection();
                continue;
            }

            printf("Choose the color:\n");
            printf("1.Blue\n2.Green\n3.Aqua\n4.Red\n5.Purple\n6.Yellow\n7.White\n");
            fflush(stdin);
            choice = getch() - '0';
            fflush(stdin);

            //Change the cursor color accordingly
            if(choice < 1 || choice > 7){
                clearCommandSection();
                continue;
            }
            SetConsoleTextAttribute(hConsole,choice+8);

            //Clear the command section not to allow the screen to be scrolled down
            clearCommandSection();

            //Draw the chosen shape
            switch(shape){
            case Shape_Line:
                drawLine(line,Up,1);
                break;

            case Shape_Square:
                drawSquare(square,Up,1);
                break;

            case Shape_Rectangle:
                drawRectangle(rectangle,Up,1);
                break;

            case Shape_Triangle:
                drawTriangle(triangle,Up,1);
                break;

            case Shape_Circle:
                drawCircle(circle,Up,1);
                break;
            default:
                //Should NOT be her AT ALL
                clearCommandSection();
                continue;

            }

            //After drawing the shape: Allow the user to fix it wherever he wants by moving
            //the shape using the arrows
            printf("Use Arrows to\nmove the figure\n\nExit: press Enter TWICE");
            fflush(stdin);
            getch();
            choice = getch();
            fflush(stdin);

            //Keep moving the shape as long as the user is pressing one of the arrows
            //Skip it only when pressing any key other than those arrows
            while(choice == Up || choice == Down || choice == Right || choice == Left){

                //Recalling the SAME shape but passing 0 as the last parameter to tell it that
                //we are just moving a previously printed shape
                switch(shape){
                case Shape_Line:
                    drawLine(line,choice,0);
                    break;
                case Shape_Square:
                    drawSquare(square,choice,0);
                    break;
                case Shape_Rectangle:
                    drawRectangle(rectangle,choice,0);
                    break;
                case Shape_Triangle:
                    drawTriangle(triangle,choice,0);
                    break;
                case Shape_Circle:
                    drawCircle(circle,choice,0);
                    break;
                }

                //User should press Enter twice to continue to the next drawing (Actually any other key than arrows)
                printf("Use Arrows to\nmove the figure\n\nExit: press Enter TWICE");
                fflush(stdin);
                getch();
                choice = getch();
                fflush(stdin);

            }

            clearCommandSection();

            //Free the allocated memory for all shapes (The used one and all others not used)
            free(line);
            free(square);
            free(triangle);
            free(rectangle);
            free(circle);
        }

    }

    //Free allocating memory for the zones allocated in memory. This happen only int two cases: before exiting the
    //whole function to change the mode of paint program and return to the main menu and when clearing the window
    free(HomeZone);
    free(ClearZone);
}
