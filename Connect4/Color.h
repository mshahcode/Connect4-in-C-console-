#ifndef __COLOR_H__
#define __COLOR_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define C_BLACK  0
#define C_WHITE  15
#define C_RED    196
#define C_GREEN  10
#define C_BLUE   39
#define C_CYAN   14
#define C_PURPLE 99
//#define C_PURPLE 201
#define C_YELLOW 11
#define C_ORANGE 215
#define C_PINK   13
#define C_DEFAULT 255
#define C_UNKNOWN 255

typedef unsigned char color;

//--------------------------------------------------------
// color_name : a character string
// precondition : this character string should be one of 
// red, green, blue, yellow, purple, white or black. 
// return value : a color (an unsigned char)
// If the precondition is met, the returned value is the 
// color corresponding to the color name, otherwise
// the function returns C_UNKNOWN. 

color C_fromColorName(char *color_name);

//--------------------------------------------------------
// character : a char
// text_color and bg_color : a number between 0 and 255
//      interpreted as a color
// return value : none
// side effect : prints on the standard output character
// with text color text_color and background color bg_color.

void C_printChar(char character, color text_color, color bg_color); 

//--------------------------------------------------------
// parameters : none
// return value : none
// side effect : prints on the standard output 255 numbers
// and corresponding colors for the foreground and background. 
// It is meant to be a help for the choice of different colors.

void C_printAllColors(void);



#endif // __COLOR_H__