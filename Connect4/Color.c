#include "Color.h"

//------------------------------------------------------

color C_fromColorName(char *color_name)
{
	if(strcmp(color_name, "red")==0)
		return C_RED; 
	else if(strcmp(color_name, "green")==0)
		return C_GREEN; 
	else if(strcmp(color_name, "blue")==0)
		return C_BLUE; 
	else if(strcmp(color_name, "yellow")==0)
		return C_YELLOW; 
	else if(strcmp(color_name, "purple")==0)
		return C_PURPLE; 
	else if(strcmp(color_name, "orange")==0)
		return C_ORANGE; 
	else if(strcmp(color_name, "white")==0)
		return C_WHITE; 
	else if(strcmp(color_name, "black")==0)
		return C_BLACK; 
	else
		return C_UNKNOWN; 
}

//------------------------------------------------------

void C_printChar(char character, color text_color, color bg_color)
{
	if(text_color == C_DEFAULT && bg_color == C_DEFAULT)
		printf("%c", character);

	else if(text_color == C_DEFAULT)
		printf("\033[48;5;%dm%c\033[0m", bg_color, character); 

	else if(bg_color == C_DEFAULT)
		printf("\033[38;5;%dm%c\033[0m", text_color, character); 

	else
		printf("\033[38;5;%d;48;5;%dm%c\033[0m", text_color, bg_color, character);
}

//------------------------------------------------------

