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

void split(string& act, Activity**** Calender)
{
	int Day, Months;
	int Start_time, End_time, Position;

	float Priority;

	string User_Id;
	string Activity_Id;
	string Title;
	string EmptyTitle = " ";

	Position = act.find('/');
	Day = atoi((act.substr(0, Position)).c_str());
	Day--;
	act.erase(0, Position + 1);

	Position = act.find(',');
	Months = atoi((act.substr(0, Position)).c_str());
	Months--;
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
	Priority = atof((act.substr(0)).c_str());

	int Duration = End_time - Start_time;

	int n = 0;
	if (Calender[Months][Day][Start_time] != NULL)
	{
		for (int i = 0; Calender[Months][Day][Start_time][i].title != ""; i++)
		{
			n++;
		}
		n++;
		for (int i = (n - 2); i < n; i++)
		{
			if (i != (n - 1))
			{
				Calender[Months][Day][Start_time][i].activity_Id = Activity_Id;
				Calender[Months][Day][Start_time][i].user_Id = User_Id;
				Calender[Months][Day][Start_time][i].title = Title;
				Calender[Months][Day][Start_time][i].priority = Priority;
				Calender[Months][Day][Start_time][i].duration = Duration;
			}

			if (i == (n - 1))
			{
				Calender[Months][Day][Start_time][i].title = "";
			}
		}
	}
	if (Calender[Months][Day][Start_time] == NULL)
	{
		n = 0;
		Calender[Months][Day][Start_time] = new Activity[n + 2];
		Calender[Months][Day][Start_time][n].activity_Id = Activity_Id;
		Calender[Months][Day][Start_time][n].user_Id = User_Id;
		Calender[Months][Day][Start_time][n].title = Title;
		Calender[Months][Day][Start_time][n].priority = Priority;
		Calender[Months][Day][Start_time][n].duration = Duration;
		Calender[Months][Day][Start_time][n + 1].title = "";
	}
	cout << "Duration: " << Calender[Months][Day][Start_time]->duration << " User Id: " << Calender[Months][Day][Start_time]->user_Id << " Activity Id: " << Calender[Months][Day][Start_time]->activity_Id << " title: " << Calender[Months][Day][Start_time]->title << " Priority: " << Calender[Months][Day][Start_time]->priority << endl;
}

void list_all_activity(Activity**** Calender) {
	string User_Id;
	int count = 0, Days = 0;
	int position;
	string start, end;
	int start_month = 0, end_month = 0, start_date = 0, end_date = 0;

	cout << "Enter the ID of the User whose Activities are to be Displayed" << endl;
	cin >> User_Id;
	cout << "Enter the Start Date :" << endl;
	cin >> start;
	cout << "Enter the End Date :" << endl;
	cin >> end;

	position = start.find('/');
	start_date = atoi((start.substr(0, position)).c_str());
	start_date--;
	start.erase(0, position + 1);
	start_month = atoi((start.substr(0, position + 1)).c_str());
	start_month--;

	position = end.find('/');
	end_date = atoi((end.substr(0, position)).c_str());
	end.erase(0, position + 1);
	end_month = atoi((end.substr(0, position + 1)).c_str());

	cout << endl << "The List of the User Activities is" << endl;
	int j = 0;
	for (int i = start_month; i < end_month; i++)
	{
		if (i == start_month)
		{
			if (i == 0 || i == 2 || i == 4 || i == 6 || i == 7 || i == 9 || i == 11)
			{
				Days = 31;
			}
			else if (i == 1)
			{
				Days = 28;
			}
			else if (i == 3 || i == 5 || i == 8 || i == 10)
			{
				Days = 30;
			}
			for (j = start_date; j < Days; j++)
			{
				for (int k = 0; k < 24; k++)
				{
					if (Calender[i][j][k] != NULL)
					{
						for (int l = 0; Calender[i][j][k][l].title != ""; l++)
						{
							if (User_Id == (Calender[i][j][k][l].user_Id))
							{
								cout << Calender[i][j][k][l].title << endl;
								count++;
							}
						}
					}
				}
			}
		}
	}
	if (count == 0)
	{
		cout << "The User Has No Activity In this Time Span" << endl;
	}
}

void Print_activity_stats(Activity**** Calender) {
	int count = 0;
	float total;
	float avg = 0;
	int Days = 0;
	int acts = 0;
	int month;
	cout << "Enter Month Number: " << endl;
	cin >> month;


	if (month == 0 || month == 2 || month == 4 || month == 6 || month == 7 || month == 9 || month == 11)
	{
		Days = 31;
	}
	else if (month == 1)
	{
		Days = 28;
	}
	else if (month == 3 || month == 5 || month == 8 || month == 10)
	{
		Days = 30;
	}
	for (int j = 0; j < Days; j++)
	{
		for (int k = 0; k < 24; k++)
		{
			if (Calender[month][j][k] != NULL)
			{
				for (int l = 0; Calender[month][j][k][l].title != ""; l++)
				{
					count++;
				}
			}
		}
	}
	total = count;
	int i = 0;
	if (month == 0 || month == 2 || month == 4 || month == 6 || month == 7 || month == 9 || month == 11)
	{
		Days = 31;
		avg = total / Days;
	}
	else if (month == 1)
	{
		Days = 28;
		avg = total / Days;
	}
	else if (month == 3 || month == 5 || month == 8 || month == 10)
	{
		Days = 30;
		avg = total / Days;
	}
	cout << "The Total Number of Activities in the Year are : " << total << endl;
	cout << "The Average Number of Activities Per Month are : " << avg << endl;

	int day_act = 0;
	int curr_day = 0;
	int buzy_day = 0;
	int high_day = 0;
	int yex = 0;

	if (month == 0 || month == 2 || month == 4 || month == 6 || month == 7 || month == 9 || month == 11)
	{
		Days = 31;
	}
	else if (month == 1)
	{
		Days = 28;
	}
	else if (month == 3 || month == 5 || month == 8 || month == 10)
	{
		Days = 30;
	}
	for (int j = 0; j < Days; j++)
	{
		for (int k = 0; k < 24; k++)
		{
			if (Calender[month][j][k] != NULL)
			{
				for (int l = 0; Calender[month][j][k][l].title != ""; l++)
				{
					curr_day++;
					yex++;
				}
			}
		}
	}
	if (high_day < curr_day)
	{
		high_day = curr_day;
		day_act = curr_day;
		buzy_day = month;
	}

	if (yex > 0)
	{
		buzy_day++;
		cout << "The Buziest Day of the Month is                              : Day " << buzy_day << endl;
		cout << "The No. Activities on the Buziest Day of the Month are       : " << day_act << endl;
	}

	float priority = 0;
	float count1 = 0;
	if (month == 0 || month == 2 || month == 4 || month == 6 || month == 7 || month == 9 || month == 11)
	{
		Days = 31;
	}
	else if (month == 1)
	{
		Days = 28;
	}
	else if (month == 3 || month == 5 || month == 8 || month == 10)
	{
		Days = 30;
	}
	for (int j = 0; j < Days; j++)
	{
		for (int k = 0; k < 24; k++)
		{
			if (Calender[month][j][k] != NULL)
			{
				for (int l = 0; Calender[month][j][k][l].title != ""; l++)
				{
					priority = Calender[month][j][k][l].priority;
					count1++;
				}
			}
		}
	}
	priority = priority / count1;
	cout << "The Average Number of Activities Priority In the Month are : " << priority << endl;

}

void list_of_users(Activity**** Calender) {
	int count = 0, Days = 0;
	int position;
	string start, end;
	int start_month = 0, end_month = 0, start_date = 0, end_date = 0;

	cout << "Enter the Start Date :" << endl;
	cin >> start;
	cout << "Enter the End Date :" << endl;
	cin >> end;

	position = start.find('/');
	start_date = atoi((start.substr(0, position)).c_str());
	start_date--;
	start.erase(0, position + 1);
	start_month = atoi((start.substr(0, position + 1)).c_str());
	start_month--;

	position = end.find('/');
	end_date = atoi((end.substr(0, position)).c_str());
	end.erase(0, position + 1);
	end_month = atoi((end.substr(0, position + 1)).c_str());

	cout << endl << "The List of the User Free In Time Slot Is: " << endl;
	int j = 0;
	for (int i = start_month; i < end_month; i++)
	{
		if (i == start_month)
		{
			if (i == 0 || i == 2 || i == 4 || i == 6 || i == 7 || i == 9 || i == 11)
			{
				Days = 31;
			}
			else if (i == 1)
			{
				Days = 28;
			}
			else if (i == 3 || i == 5 || i == 8 || i == 10)
			{
				Days = 30;
			}
			for (j = start_date; j < Days; j++)
			{
				for (int k = 0; k < 24; k++)
				{
					if (Calender[i][j][k] != NULL)
					{
						for (int l = 0; Calender[i][j][k][l].title == ""; l++)
						{
							cout << "User: " << Calender[i][j][k][l].user_Id << endl;
						}
					}
				}
			}
		}
	}
	if (count == 0)
	{
		cout << "No User Is Free " << endl;
	}
}

void longest_free_period(Activity**** Calender) {

}

void Important_activities(Activity**** Calender) {
	string User_Id;
	int count = 0, Days = 0;
	int position;
	string start, end;
	int start_month = 0, end_month = 0, start_date = 0, end_date = 0;

	cout << "Enter the ID of the User whose Activities are to be Displayed" << endl;
	cin >> User_Id;
	cout << "Enter the Start Date :" << endl;
	cin >> start;
	cout << "Enter the End Date :" << endl;
	cin >> end;

	position = start.find('/');
	start_date = atoi((start.substr(0, position)).c_str());
	start_date--;
	start.erase(0, position + 1);
	start_month = atoi((start.substr(0, position + 1)).c_str());
	start_month--;

	position = end.find('/');
	end_date = atoi((end.substr(0, position)).c_str());
	end.erase(0, position + 1);
	end_month = atoi((end.substr(0, position + 1)).c_str());

	cout << endl << "The List of the User Activities is" << endl;
	int j = 0;
	if (count <= 5) {
		for (int i = start_month; i < end_month; i++)
		{
			if (i == start_month)
			{
				if (i == 0 || i == 2 || i == 4 || i == 6 || i == 7 || i == 9 || i == 11)
				{
					Days = 31;
				}
				else if (i == 1)
				{
					Days = 28;
				}
				else if (i == 3 || i == 5 || i == 8 || i == 10)
				{
					Days = 30;
				}
				for (j = start_date; j < Days; j++)
				{
					for (int k = 0; k < 24; k++)
					{
						if (Calender[i][j][k] != NULL)
						{
							for (int l = 0; Calender[i][j][k][l].title != ""; l++)
							{
								if (User_Id == (Calender[i][j][k][l].user_Id))
								{
									cout << Calender[i][j][k][l].title << endl;
									count++;
								}
							}
						}
					}
				}
			}
		}
		int counter = 0;
		float prt[5000] = { 0 };
		if (count > 0) {
			for (int i = start_month; i < end_month; i++)
			{
				if (start_month == end_month - 1)
				{
					if (i == start_month)
					{
						if (i == 0 || i == 2 || i == 4 || i == 6 || i == 7 || i == 9 || i == 11)
						{
							Days = 31;
						}
						else if (i == 1)
						{
							Days = 28;
						}
						else if (i == 3 || i == 5 || i == 8 || i == 10)
						{
							Days = 30;
						}
						for (j = start_date; j < Days; j++)
						{
							for (int k = 0; k < 24; k++)
							{
								if (Calender[i][j][k] != NULL)
								{
									for (int l = 0; Calender[i][j][k][l].title != ""; l++)
									{
										if (User_Id == (Calender[i][j][k][l].user_Id))
										{
											prt[counter] = Calender[i][j][k][l].priority;
											counter++;
										}
									}
								}
							}
						}
					}
				}
				for (int i = 0; i < counter; i++)
				{
					j = i + 1;
					while (j < counter)
					{
						if (prt[i] < prt[i + j])
						{
							swap(prt[i], prt[i + j]);
						}
						j++;
					}
				}
				for (int i = 0; i < counter && i < 5; i++)
				{
					cout << prt[i] << endl;
				}
			}
		}
		else if (count == 0)
		{
			cout << "The User Has No Activity In this Time Span" << endl;
		}
	}
}

bool ID_Remover(Activity*& Calender, int& l)
{
	bool flag = true;
	int i = 0, j = 0;
	for (i = 0; Calender[i].title != ""; i++);
	{
	}
	if (i == 1)
	{
		Calender[0].title.assign("");
	}
	else
	{
		for (i = 0; Calender[i].title != ""; i++);
		{
			if (i >= l)
			{
				Calender[i] = Calender[i + 1];
			}
		}
	}
	return flag;
}
void Remove_user(Activity**** Calender)
{
	int count = 0;
	int Days = 0;
	bool flag = true;
	string User_id;
	cout << "Enter the ID of the User to be Removed" << endl;
	cin >> User_id;
	for (int i = 0; i < 12; i++)
	{
		if (i == 0 || i == 2 || i == 4 || i == 6 || i == 7 || i == 9 || i == 11)
		{
			Days = 31;
		}
		else if (i == 1)
		{
			Days = 28;
		}
		else if (i == 3 || i == 5 || i == 8 || i == 10)
		{
			Days = 30;
		}
		for (int j = 0; j < Days; j++)
		{
			for (int k = 0; k < 24; k++)
			{
				if (Calender[i][j][k] != NULL)
				{
					for (int l = 0; flag && Calender[i][j][k][l].title != ""; l++)
					{
						if (Calender[i][j][k][l].user_Id == User_id)
						{
							ID_Remover(Calender[i][j][k], l);
							l--;
						}
					}
					if (Calender[i][j][k][0].title.compare("") == 0)
					{
						delete[]Calender[i][j][k];
						Calender[i][j][k] = NULL;
					}
				}
			}
		}
	}
	cout << endl << "All the Data of User " << User_id << " has been removed" << endl;
}

void Calendar_Stats(Activity**** Calender) {
	int count = 0;
	float total;
	float avg = 0;
	int g = 0;
	int Days = 0;
	int acts = 0;
	for (int i = 0; i < 12; i++)
	{
		if (i == 0 || i == 2 || i == 4 || i == 6 || i == 7 || i == 9 || i == 11)
		{
			Days = 31;
		}
		else if (i == 1)
		{
			Days = 28;
		}
		else if (i == 3 || i == 5 || i == 8 || i == 10)
		{
			Days = 30;
		}
		for (int j = 0; j < Days; j++)
		{
			for (int k = 0; k < 24; k++)
			{
				if (Calender[i][j][k] != NULL)
				{
					for (int l = 0; Calender[i][j][k][l].title != ""; l++)
					{
						count++;
					}
				}
			}
		}
	}
	total = count;
	avg = total / 12;
	int i = 0;
	cout << "The Total Number of Activities in the Year are : " << total << endl;
	cout << "The Average Number of Activities Per Month are : " << avg << endl;
	int month_act = 0;
	int curr_month = 0;
	int buzy_month = 0;
	int high_month = 0;
	int yex = 0;
	for (int i = 0; i < 12; i++)
	{
		curr_month = 0;
		if (i == 0 || i == 2 || i == 4 || i == 6 || i == 7 || i == 9 || i == 11)
		{
			Days = 31;
		}
		else if (i == 1)
		{
			Days = 28;
		}
		else if (i == 3 || i == 5 || i == 8 || i == 10)
		{
			Days = 30;
		}
		for (int j = 0; j < Days; j++)
		{
			for (int k = 0; k < 24; k++)
			{
				if (Calender[i][j][k] != NULL)
				{
					for (int l = 0; Calender[i][j][k][l].title != ""; l++)
					{
						curr_month++;
						yex++;
					}
				}
			}
		}
		if (high_month < curr_month)
		{
			high_month = curr_month;
			month_act = curr_month;
			buzy_month = i;
		}
	}
	if (yex > 0)
	{
		buzy_month++;
		cout << "The Buziest Month of the Year is                              : Month " << buzy_month << endl;
		cout << "The No. Activities on the Buziest Month of the Year are       : " << month_act << endl;
	}
}

void Save_calendar(Activity**** Calender)
{
	int Days = 0;
	ofstream Write("Activiy");
	for (int i = 0; i < 12; i++)
	{
		if (i == 0 || i == 2 || i == 4 || i == 6 || i == 7 || i == 9 || i == 11)
		{
			Days = 31;
		}
		else if (i == 1)
		{
			Days = 28;
		}
		else if (i == 3 || i == 5 || i == 8 || i == 10)
		{
			Days = 30;
		}
		for (int j = 0; j < Days; j++)
		{
			for (int k = 0; k < 24; k++)
			{
				if (Calender[i][j][k] != NULL)
				{
					for (int l = 0; Calender[i][j][k][l].title != ""; l++)
					{
						Write << j + 1 << "/" << i + 1 << "," << k
							<< "," << k + Calender[i][j][k][l].duration << "," << "user" << Calender[i][j][k][l].user_Id
							<< "," << Calender[i][j][k][l].activity_Id << "," << Calender[i][j][k][l].title
							<< "," << Calender[i][j][k][l].priority << endl;
					}
				}
			}
		}
	}
	cout << "Calender Saved /_" << endl;
}

void Print_Calender_Month(Activity**** Calender)
{
	int i;
	cout << "Enter Month: " << endl;
	cin >> i;

	system("cls");

	int x = 0;
	int y = 0;
	int Days = 0;

	int cx = 0, px = 0, py = 0, count = 0;
	bool flag = true;


	if (i == 1)
	{
		setCursorPointer(2, 0);
		cout << "---January---" << endl;
		Days = 31;
	}
	else if (i == 2)
	{
		setCursorPointer(2, 0);
		cout << "---Febraury---" << endl;
		Days = 28;
	}
	else if (i == 3)
	{
		setCursorPointer(2, 0);
		cout << "---March---" << endl;
		Days = 31;
	}
	else if (i == 4)
	{
		setCursorPointer(2, 0);
		cout << "---April---" << endl;
		Days = 30;
	}
	else if (i == 5)
	{
		setCursorPointer(2, 0);
		cout << "---May---" << endl;
		Days = 31;
	}
	else if (i == 6)
	{
		setCursorPointer(2, 0);
		cout << "---June---" << endl;
		Days = 30;
	}
	else if (i == 7)
	{
		setCursorPointer(2, 0);
		cout << "---July---" << endl;
		Days = 31;
	}
	else if (i == 8)
	{
		setCursorPointer(2, 0);
		cout << "---August---" << endl;
		Days = 31;
	}
	else if (i == 9)
	{
		setCursorPointer(2, 0);
		cout << "---September---" << endl;
		Days = 30;
	}
	else if (i == 10)
	{
		setCursorPointer(2, 0);
		cout << "---October---" << endl;
		Days = 31;
	}
	else if (i == 11)
	{
		setCursorPointer(2, 0);
		cout << "---November---" << endl;
		Days = 30;
	}
	else if (i == 12)
	{
		setCursorPointer(2, 0);
		cout << "---December---" << endl;
		Days = 31;
	}
	x = 9;
	y = 2;
	cx = 0;
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

	setCursorPointer(px, 1);
	cout << "M";
	px += 3;
	setCursorPointer(px, 1);
	cout << "T";
	px += 3;
	setCursorPointer(px, 1);
	cout << "W";
	px += 3;
	setCursorPointer(px, 1);
	cout << "T";
	px += 3;
	setCursorPointer(px, 1);
	cout << "F";
	px += 3;
	setCursorPointer(px, 1);
	cout << "S";
	px += 3;
	setCursorPointer(px, 1);
	cout << "S";
	cout << endl << endl << endl << endl << endl << endl;

}

int main()
{
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);

	int Days = 0;
	int Monthss = 12;
	int hours = 24;
	Activity**** Calender;
	Calender = new Activity * **[Monthss];
	for (int i = 0; i < Monthss; i++)
	{
		if (i == 0 || i == 2 || i == 4 || i == 6 || i == 7 || i == 9 || i == 11)
		{
			Days = 31;
		}
		else if (i == 1)
		{
			Days = 28;
		}
		else if (i == 3 || i == 5 || i == 8 || i == 10)
		{
			Days = 30;
		}
		Calender[i] = new Activity * *[Days];
		for (int j = 0; j < Days; j++)
		{
			Calender[i][j] = new Activity * [hours];
			for (int k = 0; k < hours; k++)
			{
				Calender[i][j][k] = NULL;
			}
		}
	}
	string act;

	fstream activity;
	activity.open("Activity", ios::out);
	if (!activity) {
		cout << "File not created!" << endl;
	}
	else {
		cout << "File created successfully!" << endl;
		cout << "User Are Given Below: " << endl;
		activity << "09/10,11,14,user1,act33,Gym,0.99" << endl;
		activity << "10/11,10,12,user2,act34,Study,0.1" << endl;
		activity << "02/09,18,20,user1,act28,Cricket,0.80" << endl;
		activity.close();
	}

	ifstream Fetch("Activity");
	if (Fetch.is_open())
	{
		while (getline(Fetch, act))
		{
			split(act, Calender);
		}
	}
	while (1)
	{
		int choice;
		cout << "\n\nWelcome to the Calendar.." << endl << endl;
		cout << "1) List all activities of a given user during a time period." << endl;
		cout << "2) List the 5 most important activities of a given user during a time period." << endl;
		cout << "3) longest consecutive number of days in which the user has no activity. " << endl;
		cout << "4) list all hourly slots that are free for all these user in this time period." << endl;
		cout << "5) Print activity stats for a given month" << endl;
		cout << "6) Print Calendar Stats (for the whole year)" << endl;
		cout << "7) Remove a user from the calendar" << endl;
		cout << "8) Save the calendar" << endl;
		cout << "9) Print the calendar month." << endl << endl;
		cout << "Please Choice (1 - 9): ";
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
			list_of_users(Calender);
		}
		else if (choice == 5)
		{
			Print_activity_stats(Calender);
		}
		else if (choice == 6)
		{
			Calendar_Stats(Calender);
		}
		else if (choice == 7)
		{
			Remove_user(Calender);
		}
		else if (choice == 8)
		{
			Save_calendar(Calender);
		}
		else if (choice == 9) {
			Print_Calender_Month(Calender);
		}
		else
		{
			cout << "Invalid Value.. Try Again" << endl;
		}
	}
	return 0;
}