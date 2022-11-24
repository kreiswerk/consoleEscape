#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include "chartributes.h"

void printInColorB(char *str, color txt, color background);
void printInColor(char *str, color txt); //Prints *str in [color txt] 
void printIn256Color(char *str, color txt);
void printInRGB(char *str, color red, color blue, color green);
void printInRGBB(char *str, color txt_r, color txt_b, color txt_g, color bckgnd_r, color bckgnd_g, color bckgnd_b);

int main()
{
	for(int i = 0; i < 255; i++)
	{
		printIn256Color("text\n", i);
	}
}


void printInColorB(char *str, color txt, color background)
{
	printf("\x1b[0;%i;%im%s\e[0m", txt, background, str);
}

void printInColor(char *str, color txt)
{
	printf("\x1b[0;%im%s\e[0m", txt, str);
}

void printIn256Color(char *str, color txt)
{
	printf("\x1b[1;38;5;%im%s\x1b[0m", txt, str);
}




//ONYL SUPPORTED IN TERMINALS WHICH SUPPORT TRUECOLOR (APPLE TERMINAL DOESNT, MINGW ON WINDOWS DOES, usw)
void printInRGB(char *str, color r, color b, color g)
{
	 printf("\x1b[38;2;%i;%i;%im%s\x1b[0m", r, g, b, str); 
}

void printInRGBB(char *str, color txt_r, color txt_b, color txt_g, color bckgnd_r, color bckgnd_g, color bckgnd_b) //has to be checked on mingw if implemented correctly
{
	 printf("\x1b[38;2;%i;%i;%i48;2;%i;%i;%im%s\x1b[0m", txt_r, txt_g, txt_b, bckgnd_r, bckgnd_g, bckgnd_b, str); 
}
