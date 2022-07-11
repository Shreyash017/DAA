#include <iostream>
#include <string>
using namespace std;

void naive(string txt, string pat)
{
    int n, m;
    n = txt.length();
    m = pat.length();

//  A loop to slide window pattern
    for (int i = 0; i <= n - m; i++)
    {
        int j = 0;
        // To match pattern
        while (j < m)
        {
            if (txt[i + j] != pat[j])
            {
                break;
            }
            j++;
        }
        if (j == m)
        {
            cout << "\nPattern found at index " << i;
        }
    }
}

int main()
{
    string txt, pat;
    cout << "\nEnter the String: ";
    cin >> txt;
    cout << "\nEnter the Pattern: ";
    cin >> pat;
    naive(txt, pat);
    return 0;
}

/*
Eg:- 
txt = "AABAACAADAABAAABAA"
pat = "AABA"
*/