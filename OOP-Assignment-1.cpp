#include<iostream>
using namespace std;

int main()
{
    int months = 2, days = 3, hrs = 4, act = 2;
    int count = 0;

    int*** a = new int** [months];

    for (int i = 0; i < months; i++) {
        a[i] = new int* [days];
        for (int j = 0; j < days; j++) {
            a[i][j] = new int [hrs];
        }
    }

    for (int i = 0; i < months; i++) {
        **a[i] = i;
        for (int j = 0; j < days; j++) {
            *a[i][j] = j;
            for (int k = 0; k < hrs; k++) {
                a[i][j][k] = k + 1;
            }
        }
    }

    for (int i = 0; i < months; i++) {
        cout << "Month: " << **a[i] << endl;
        for (int j = 0; j < days; j++) {
            cout << " -> Day: " << *a[i][j] << endl;
            for (int k = 0; k < hrs; k++) {
                cout << " ->  -> Hour: " << a[i][j][k] << endl;
            }
        }
        cout << endl;
    }

    return 0;
}