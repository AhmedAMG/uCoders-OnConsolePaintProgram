/*               uCoders                     */
/* Paint Program (Third Part in the Project) */
/*           Team number : 2                 */
/*      IDs: 2 - 4 - 10 - 14 - 41            */
/* Team Leader: Ahmed Mohammed Gamal Al-Din  */
/*       Release Date : 16/8/2019            */

#ifndef __FIGURES_H_
#define __FIGURES_H_

///Each "point" variable is the point where each drawing starts from whatever the shape is

//The are TWO modes in each function of drawing each shape
//Each "arrow" variable is for passing the arrow pressed in the keyboard to know the direction of movement
///Each "firstTime" variable is an indication whether I am drawing that object for the first time or I am just moving it

typedef enum{
    Horizontal = 1, Vertical = 2
}ORIENTATION;

typedef enum{
    //integer representation to the arrows in the keyboard to move the figure after drawing it
    //Right = 22477, Left = 22475, Up = 22472, Down = 22480
    Right = 77, Left = 75, Up = 72, Down = 80
}ARROW;

typedef struct{
    int x;
    int y;
}COORDINATES;

typedef struct{
    int length;
    COORDINATES point;
    ORIENTATION orientation;
}LINE;

typedef struct{
    int length;
    int width;
    COORDINATES point;
}RECTANGLE;

typedef struct{
    int length;
    COORDINATES point;
}SQUARE;

typedef struct{
    int height;
    COORDINATES point;
}TRIANGLE;

typedef struct{
    int radius;
    COORDINATES point;
}CIRCLE;

void drawLine(LINE*, int arrow, int firstTime);
void drawRectangle(RECTANGLE* ,int arrow, int firstTime);
void drawSquare(SQUARE*, int arrow, int firstTime);
void drawTriangle(TRIANGLE*, int arrow, int firstTime);
void drawCircle(CIRCLE*, int arrow, int firstTime);

#endif // __FIGURES_H_
