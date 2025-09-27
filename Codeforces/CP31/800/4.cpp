#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        if (n % 3 == 0)
            cout << "Second" << endl;
        if (n % 3 == 1)
            cout << "First" << endl;
        if (n % 3 == 2)
            cout << "First" << endl;
    }
    return 0;
}