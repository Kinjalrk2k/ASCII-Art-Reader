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

void ascii_art(const char* loc, int x, int y)
{
    fstream f;
	f.open(loc, ios::in);

	gotoxy(x,y);

	char t;
	while(f.get(t))
    {
        if(f.eof())
            break;

        if(t=='\n')
        {
            y++;
            gotoxy(x,y);
            continue;
        }

        cout<<t;
    }
}

int main()
{
	system("cls");

	int x=10, y=10;

	ascii_art("art.txt", x, y);

    _getch();

	return 0;
}
