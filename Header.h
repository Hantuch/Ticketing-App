#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <dos.h>
#include <dir.h>
#include <string.h>


void SetColor(int ForgC)
 {
 WORD wColor;

  HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO csbi;

                       
 if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
 {
                 
      wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
      SetConsoleTextAttribute(hStdOut, wColor);
 }
return;
}

void printcolor(char input[],int color)
{
	SetColor(color);
	printf("%s", input);
	SetColor(15);
}

void separator(int number, char input[][40],char output[][4][10])
{	
	int i = 0;
	char *b[3];
	b[i] = strtok(input[number]," ");
	while(b[i] != NULL)
	{	
		i++;
		b[i] = strtok(NULL," ");
 	}	
 	for(i=0;i<3;i++)
 	{
 		strcpy(output[number][i],b[i]);	
	}	
}
