#include <iostream>
#include<stdio.h>
#include <windows.h>
#include <cwchar>

using namespace std;

struct Activity
{
	string title;
	string user_Id;
	string activity_Id;
	float priority;
	int duration;
};

void setCursorPointer(int x = 0, int y = 0)
{
	HANDLE handle;
	COORD coordinates;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	coordinates.X = x;
	coordinates.Y = y;
	SetConsoleCursorPosition(handle, coordinates);
}

void Print_Calender(Activity**** Calender)
{
	system("cls");

	int x = 0;
	int y = 0;
	int Days = 0;
	setCursorPointer(5, 0);
	cout << "January" << endl;
	setCursorPointer(50, 0);
	cout << "Febraury" << endl;
	setCursorPointer(90, 0);
	cout << "March" << endl;
	setCursorPointer(5, 10);
	cout << "April" << endl;
	setCursorPointer(50, 10);
	cout << "May" << endl;
	setCursorPointer(90, 10);
	cout << "June" << endl;
	setCursorPointer(5, 20);
	cout << "July" << endl;
	setCursorPointer(50, 20);
	cout << "August" << endl;
	setCursorPointer(90, 20);
	cout << "September" << endl;
	setCursorPointer(5, 30);
	cout << "October" << endl;
	setCursorPointer(50, 30);
	cout << "November" << endl;
	setCursorPointer(90, 30);
	cout << "December" << endl;
	int cx = 0, px = 0, py = 0, count = 0;
	for (int i = 0; i < 12; i++)
	{
		if (i == 0)
		{
			//Days = 31;
			x = 9;
			y = 2;
			cx = 0;
			px = cx;
			py = y - 1;
		}
		else if (i == 1)
		{
			//Days = 28;
			x = 42;
			y = 2;
			cx = 45;
			px = cx;
			py = y - 1;
		}
		else if (i == 2)
		{
			//Days = 31;
			x = 78;
			y = 2;
			cx = 84;
			px = cx;
			py = y - 1;
		}
		else if (i == 3)
		{
			//Days = 30;
			x = 6;
			y = 12;
			cx = 0;
			px = cx;
			py = y - 1;
		}
		else if (i == 4)
		{
			//Days = 31;
			x = 36;
			y = 12;
			cx = 45;
			px = cx;
			py = y - 1;
		}
		else if (i == 5)
		{
			//Days = 30;
			x = 84;
			y = 12;
			cx = 84;
			px = cx;
			py = y - 1;
		}
		else if (i == 6)
		{
			//Days = 31;
			x = 6;
			y = 22;
			cx = 0;
			px = cx;
			py = y - 1;
		}
		else if (i == 7)
		{
			//Days = 31;
			x = 39;
			y = 22;
			cx = 45;
			px = cx;
			py = y - 1;
		}
		else if (i == 8)
		{
			//Days = 30;
			x = 51;
			y = 22;
			cx = 84;
			px = cx;
			py = y - 1;
		}
		else if (i == 9)
		{
			//Days = 31;
			x = 9;
			y = 32;
			cx = 0;
			px = cx;
			py = y - 1;
		}
		else if (i == 10)
		{
			//Days = 30;
			x = 42;
			y = 32;
			cx = 45;
			px = cx;
			py = y - 1;
		}
		else if (i == 11)
		{
			//Days = 31;
			x = 51;
			y = 32;
			cx = 84;
			px = cx;
			py = y - 1;
		}

		setCursorPointer(px, py);
		cout << "M";
		px += 3;
		setCursorPointer(px, py);
		cout << "T";
		px += 3;
		setCursorPointer(px, py);
		cout << "W";
		px += 3;
		setCursorPointer(px, py);
		cout << "T";
		px += 3;
		setCursorPointer(px, py);
		cout << "F";
		px += 3;
		setCursorPointer(px, py);
		cout << "S";
		px += 3;
		setCursorPointer(px, py);
		cout << "S";
		cout << endl << endl << endl << endl << endl << endl;
	}
}

int main()
{
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);

	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;                   // Width of each character in the font
	cfi.dwFontSize.Y = 22;                  // Height
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);

	int months = 12, days = 0, hours = 24;
    int count = 0;
    Activity**** Calender;
    Calender = new Activity*** [months];


	for (int i = 0; i < months; i++)
	{
		if (i == 0 || i == 2 || i == 4 || i == 6 || i == 7 || i == 9 || i == 11)
		{
			days = 31;
		}
		else if (i == 1)
		{
			days = 28;
		}
		else if (i == 3 || i == 5 || i == 8 || i == 10)
		{
			days = 30;
		}
		Calender[i] = new Activity **[days];
		for (int j = 0; j < days; j++)
		{
			Calender[i][j] = new Activity * [hours];
			for (int k = 0; k < hours; k++)
			{
				Calender[i][j][k] = NULL;
			}
		}
	}

	while (1)
	{
		int choice;
		cout << "\n\nWelcome to the Calendar...You Can use Any Function" << endl << endl;
		cout << "1) Print the calendar." << endl;
		cin >> choice;
		cout << endl;
		if(choice==1)
		{
			Print_Calender(Calender);
		}
		else if(choice==2)
		{
	    }
	    else if(choice==3)
	    {
	    }
	    else if(choice==4)
	    {
	    }
	    else if(choice==5)
	    {
	    }
	    else if(choice==6)
	    {
	    }
	    else if(choice==7)
	    {
	    }
	    else if(choice==8)
	    {
	    }
	    else if(choice==9)
	    {
	    }
	    else
	    {
	    	cout<<"Invalid Value"<<endl;
	    }
    }
	return 0;
}