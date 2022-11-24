#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include "chartributes.h"

void printInColorB(char *str, color txt, color background);
void printInColor(char *str, color txt); //Prints *str in [color txt] 
void printInRGB(char *str, color red, color blue, color green);

int main()
{
	printInRGB("HelloWorld", 255, 0, 0);	
	printInColor("color", TXT_RED);
}


void printInColorB(char *str, color txt, color background)
{
	printf("\x1b[0;%i;%im%s\e[0m", txt, background, str);
}

void printInColor(char *str, color txt)
{
	printf("\x1b[0;%im%s\e[0m", txt, str);
}

void printInRGB(char *str, color r, color b, color g)
{
	 printf("\x1b[38;2;%i;%i;%im%s", r, g, b, str); //38 color text, 48 color backgnd
}
