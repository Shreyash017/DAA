#include <iostream>
#define s 100
using namespace std;
int main()
{
    int n, i, j, mat[s][s], arr[s], inv = 0, num = 0, input, row;

    cout << "\nEnter the number of rows:- ";
    cin >> n;

    cout << "\nEnter the numbers:- ";
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            cin >> input;
            arr[num++] = input;
            if (arr[num - 1] == 0)
                row = n - i + 1;
        }
    }
    cout << "\nIts a " << num - 1 << " puzzle problem";

    for (i = 0; i < num; i++)
    {
        for (j = i + 1; j < num; j++)
        {
            if (arr[i] > arr[j] && arr[i] != 0 && arr[j] != 0)
            {
                inv++;
            }
        }
    }

    cout << "\nNumber of Inversions: " << inv << endl;
    if ((n % 2 == 1 && inv % 2 == 0) || (n % 2 == 0 && inv % 2 == 1 && row % 2 == 0) || (n % 2 == 0 && inv % 2 == 0 && row % 2 == 1))
        cout << "Solve able\n";
    else
        cout << "Not Possible\n";
}

/*
Eg:- For 15 Puzzle Problem
Row:- 4
Number:- 1 2 3 4 5 6 7 8 9 10 12 0 13 14 11 15
{0 is the missing/blank tile}
{Goal State:- 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 0}
Ans:-
No. of Inversion:  3
Solve able
*/

/*
Details:-
Initial State:-
1 2 3 4
5 6 7 8
9 10 12 0
13 14 11 15


1:-->   Blank tile Left
        1 2 3 4
        5 6 7 8
        9 10 0 12
        13 14 11 15

2:-->   Blank tile Down
        1 2 3 4
        5 6 7 8
        9 10 11 12
        13 14 0 15

3:-->   Blank tile Right
        1 2 3 4
        5 6 7 8
        9 10 11 12
        13 14 15 0

Final/Goal State
Therefore, Number of Inversions:- 3
*/