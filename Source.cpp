#include <iostream>
#include<stdio.h>
#include <windows.h>
#include <cwchar>
#include <string>
#include <fstream>

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

void split(string& act, int& Day, int& Months, int& Start_time, int& End_time, float& Priority, string& User_Id, string& Activity_Id, string& Title)
{
	int Position;

	Position = act.find('/');
	Day = atoi((act.substr(0, Position)).c_str());
	act.erase(0, Position + 1);

	Position = act.find(',');
	Months = atoi((act.substr(0, Position)).c_str());
	act.erase(0, Position + 1);

	Position = act.find(',');
	Start_time = atoi((act.substr(0, Position)).c_str());
	act.erase(0, Position + 1);

	Position = act.find(',');
	End_time = atoi((act.substr(0, Position)).c_str());
	act.erase(0, Position + 5);

	Position = act.find(',');
	User_Id = act.substr(0, Position);
	act.erase(0, Position + 1);

	Position = act.find(',');
	Activity_Id = act.substr(0, Position);
	act.erase(0, Position + 1);

	Position = act.find(',');
	Title = act.substr(0, Position);
	act.erase(0, Position + 1);

	Position = act.find(',');
	Priority = ::strtod(act.c_str(), 0);

	int Duration = End_time - Start_time;
}

void Print_Calender(Activity**** Calender)
{
	system("cls");

	int x = 0;
	int y = 0;
	int Days = 0;
	setCursorPointer(2, 0);
	cout << "---January---" << endl;
	setCursorPointer(27, 0);
	cout << "---Febraury---" << endl;
	setCursorPointer(52, 0);
	cout << "---March---" << endl;
	setCursorPointer(2, 10);
	cout << "---April---" << endl;
	setCursorPointer(30, 10);
	cout << "---May---" << endl;
	setCursorPointer(52, 10);
	cout << "---June---" << endl;
	setCursorPointer(2, 20);
	cout << "---July---" << endl;
	setCursorPointer(28, 20);
	cout << "---August---" << endl;
	setCursorPointer(51, 20);
	cout << "---September---" << endl;
	setCursorPointer(2, 30);
	cout << "---October---" << endl;
	setCursorPointer(27, 30);
	cout << "---November---" << endl;
	setCursorPointer(51, 30);
	cout << "---December---" << endl;

	int cx = 0, px = 0, py = 0, count = 0;
	bool flag = true;

	for (int i = 0; i < 12; i++)
	{
		if (i == 0)
		{
			Days = 31;
			x = 9;
			y = 2;
			cx = 0;
			px = cx;
			py = y - 1;
		}
		else if (i == 1)
		{
			Days = 28;
			x = 42;
			y = 2;
			cx = 24;
			px = cx;
			py = y - 1;
		}
		else if (i == 2)
		{
			Days = 31;
			x = 66;
			y = 2;
			cx = 48;
			px = cx;
			py = y - 1;
		}
		else if (i == 3)
		{
			Days = 30;
			x = 6;
			y = 12;
			cx = 0;
			px = cx;
			py = y - 1;
		}
		else if (i == 4)
		{
			Days = 31;
			x = 36;
			y = 12;
			cx = 24;
			px = cx;
			py = y - 1;
		}
		else if (i == 5)
		{
			Days = 30;
			x = 48;
			y = 12;
			cx = 48;
			px = cx;
			py = y - 1;
		}
		else if (i == 6)
		{
			Days = 31;
			x = 6;
			y = 22;
			cx = 0;
			px = cx;
			py = y - 1;
		}
		else if (i == 7)
		{
			Days = 31;
			x = 39;
			y = 22;
			cx = 24;
			px = cx;
			py = y - 1;
		}
		else if (i == 8)
		{
			Days = 30;
			x = 51;
			y = 22;
			cx = 48;
			px = cx;
			py = y - 1;
		}
		else if (i == 9)
		{
			Days = 31;
			x = 9;
			y = 32;
			cx = 0;
			px = cx;
			py = y - 1;
		}
		else if (i == 10)
		{
			Days = 30;
			x = 42;
			y = 32;
			cx = 24;
			px = cx;
			py = y - 1;
		}
		else if (i == 11)
		{
			Days = 31;
			x = 51;
			y = 32;
			cx = 48;
			px = cx;
			py = y - 1;
		}
		for (int j = 1; j <= Days; j++)
		{
			setCursorPointer(x, y);
			cout << j;
			x = x + 3;
			if (x == 21 || x == 45 || x == 69)
			{
				x = cx;
				y++;
			}

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

void list_all_activity(Activity**** Calender) {
	string User_Id;
	int count = 0, Days = 0;
	int position;
	string start, end;
	int start_month = 0, end_month = 0, start_date = 0, end_date = 0;
}

void Print_activity_stats(Activity**** Calender) {
	
}

void list_of_users(Activity**** Calender) {

}

void clashing_activities(Activity**** Calender) {

}

void longest_free_period(Activity**** Calender) {

}

void Important_activities(Activity**** Calender) {

}

void Remove_user(Activity**** Calender) {

}

void Calendar_Stats(Activity**** Calender) {

}

void Save_calendar(Activity**** Calender) {

}
int main()
{
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);

	int Day = 0, Months = 0;
	int Start_time = 0, End_time = 0;

	float Priority = 0;

	string User_Id;
	string Activity_Id;
	string Title;

	int months = 12, days = 0, hours = 24, act1 = 1;

	string act;

	fstream activity;
	activity.open("Activity", ios::out);
	if (!activity) {
		cout << "File not created!" << endl;
	}
	else {
		cout << "File created successfully!" << endl;
		cout << "User Are Given Below: " << endl;
		activity << "09/10,11,14,user1,act33,Gym,0.22" << endl;
		activity.close();
	}

	ifstream Fetch("Activity");
	while (getline(Fetch, act)) {
		split(act, Day, Months, Start_time, End_time, Priority, User_Id, Activity_Id, Title);
	}
	activity.close();

	int Duration = End_time - Start_time;

	Activity**** Calender;
	Calender = new Activity * **[months];

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
		Calender[i] = new Activity * *[days];
		for (int j = 0; j < days; j++)
		{
			Calender[i][j] = new Activity * [hours];
			for (int k = 0; k < hours; k++)
			{
				Activity* act_node = new Activity();
				act_node->activity_Id = Activity_Id;
				act_node->user_Id = User_Id;
				act_node->title = Title;
				act_node->priority = Priority;
				act_node->duration = Duration;
				Calender[i][j][k] = act_node;
			}
		}
	}

	cout << "Duration: " << Calender[Months][Day][Start_time]->duration << " User Id: " << Calender[Months][Day][Start_time]->user_Id << " Activity Id: " << Calender[Months][Day][Start_time]->activity_Id << " title: " << Calender[Months][Day][Start_time]->title << " Priority: " << Calender[Months][Day][Start_time]->priority << endl;

	while (1)
	{
		int choice;
		cout << "\n\nWelcome to the Calendar.." << endl << endl;
		cout << "1) List all activities of a given user during a time period." << endl;
		cout << "2) List the 5 most important activities of a given user during a time period." << endl;
		cout << "3) longest consecutive number of days in which the user has no activity. " << endl;
		cout << "4) List all the clashing activities of a pair of users, during a time period." << endl;
		cout << "5) list all hourly slots that are free for all these user in this time period." << endl;
		cout << "6) Print activity stats for a given month" << endl;
		cout << "7) Print Calendar Stats (for the whole year)" << endl;
		cout << "8) Remove a user from the calendar" << endl;
		cout << "9) Save the calendar" << endl;
		cout << "10) Print the calendar." << endl << endl;
		cout << "Please Choice (1 - 10): ";
		cin >> choice;
		cout << endl;
		if (choice == 1)
		{
			list_all_activity(Calender);
		}
		else if (choice == 2)
		{
			Important_activities(Calender);
		}
		else if (choice == 3)
		{
			longest_free_period(Calender);
		}
		else if (choice == 4)
		{
			clashing_activities(Calender);
		}
		else if (choice == 5)
		{
			list_of_users(Calender);
		}
		else if (choice == 6)
		{
			Print_activity_stats(Calender);
		}
		else if (choice == 7)
		{
			Calendar_Stats(Calender);
		}
		else if (choice == 8)
		{
			Remove_user(Calender);
		}
		else if (choice == 9)
		{
			Save_calendar(Calender);
		}
		else if (choice == 10) {
			Print_Calender(Calender);
		}
		else
		{
			cout << "Invalid Value.. Try Again" << endl;
		}
	}
	return 0;
}