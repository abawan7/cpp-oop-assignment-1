#include<iostream>
using namespace std;

int main()
{
    int month = 12, days = 30, hrs = 24;
    int count = 0;

    int*** a = new int** [month];

    for (int i = 0; i < month; i++) {
        a[i] = new int* [days];
        for (int j = 0; j < days; j++) {
            a[i][j] = new int[hrs];
        }
    }

    for (int i = 0; i < month; i++) {
        for (int j = 0; j < days; j++) {
            for (int k = 0; k < hrs; k++) {
                a[i][j][k] = ++count;
            }
        }
    }

    for (int i = 0; i < month; i++) {
        for (int j = 0; j < days; j++) {
            for (int k = 0; k < hrs; k++) {
                cout << a[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}