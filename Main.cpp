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

void split(string &act) {

	string day, month, start_time, end_time , user_id, act_id, title, priority;
	int space = 0;
	int n = 0;
	int count = 0;
	for (int i = 0; i < act.size(); i++) {
		{
			if (act[i] != '/') {
				day += act[i];
			}
			else if (act[i] == '/') {
				n = i + 1;
				break;
			}
		}
	}
	bool flag = true;
	for (int i = n; i < act.size(); i++) {
		flag = true;
		if (act[i] != ',' && count == 0) {
			month += act[i];
		}
		else if (act[i] == ',' && count == 0) {
			flag = false;
		}
		if (act[i] != ',' && count == 1) {
			start_time += act[i];
		}
		else if (act[i] == ',' && count == 1) {
			flag = false;
		}
		if (act[i] != ',' && count == 2) {
			end_time += act[i];
		}
		else if (act[i] == ',' && count == 2) {
			flag = false;
		}
		if (act[i] != ',' && count == 3) {
			user_id += act[i];
		}
		else if (act[i] == ',' && count == 3) {
			flag = false;
		}
		if (act[i] != ',' && count == 4) {
			act_id += act[i];
		}
		else if (act[i] == ',' && count == 4) {
			flag = false;
		}
		if (act[i] != ',' && count == 5) {
			title += act[i];
		}
		else if (act[i] == ',' && count == 5) {
			flag = false;
		}
		if (act[i] != ',' && count == 6) {
			priority += act[i];
		}
		else if (act[i] == ',' && count == 6) {
			flag = false;
		}
		if (flag == false) {
			count++;
		}
	}
	cout <<"DAY: " << day << " Month: " << month << " Start time: " << start_time << " End Time: " << end_time << " User Id: " << user_id << " Activity Id: " << act_id << " title: " << title << " Priority: " << priority << endl;
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


int main()
{
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);

	int months = 12, days = 0, hours = 24;
	int count = 0;
	Activity**** Calender;
	Calender = new Activity * **[months];

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
		activity << "02/21,10,13,user1,act23,Play Cricket,0.12" << endl;
		activity << "09/10,11,18,user1,act144,Study for Exam,0.00009";
		activity.close();
	}

	ifstream Fetch("Activity");
	while (getline(Fetch, act)) {
		split(act);
	}
	activity.close();

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
				Calender[i][j][k] = NULL;
			}
		}
	}

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

		}
		else if (choice == 2)
		{
		}
		else if (choice == 3)
		{
		}
		else if (choice == 4)
		{
		}
		else if (choice == 5)
		{
		}
		else if (choice == 6)
		{
		}
		else if (choice == 7)
		{
		}
		else if (choice == 8)
		{
		}
		else if (choice == 9)
		{

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