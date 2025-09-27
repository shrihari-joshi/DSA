#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a > b)
            cout << "First" << endl;
        else if (a < b)
            cout << "Second" << endl;
        else if (a == b && c % 2 == 0)
            cout << "Second" << endl;
        else if (a == b && c % 2 == 1)
            cout << "First" << endl;
    }
    return 0;
}