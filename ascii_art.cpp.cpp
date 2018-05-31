/*  include this file directly to use the function   */
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include <fstream>

using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

void gotoxy(int x, int y)
{
	CursorPosition.X = x; // Locates column
	CursorPosition.Y = y; // Locates Row
	SetConsoleCursorPosition(console,CursorPosition); // Sets position for next thing to be printed
}

/*  the pointer loc takes up the full location of the file from where the art is to be read
    x and y denotes the x and y positions (respectively), where the art is needed to be printed
    (Note: x and y denotes the position where the first character in the file is to be printed)
    (Note2: if you want to print the art at (0,0), then ignore the x and y arguments     */
void ascii_art(const char* loc, int x=0, int y=0)
{
    fstream f;  //  used for file handling
	f.open(loc, ios::in);   //  opened file in reading mode

	gotoxy(x,y);    //  position to start printing

	char t; //  used for reading the character from file
	while(f.get(t)) //  loop for reading the whole file
    {
        if(f.eof())
            break;  //  break the loop if end of file is reached

        if(t=='\n') //  detecting new line character in file
        {
            y++;
            gotoxy(x,y);    //  going to the new line
            continue;
        }

        cout<<t;    //  printing the character read from the file
    }
}

/*  this main is just for representation purposes, hence commented
    learn how to use this function from the following main function  */
/*
int main()
{
	system("cls");

	int x=10, y=10;

	ascii_art("art.txt", x, y);

    _getch();

	return 0;
}
*/
