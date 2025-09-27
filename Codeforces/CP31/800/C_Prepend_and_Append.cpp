#include <bits/stdc++.h>
using namespace std;

int calc(string s)
{
    int n = s.size();
    int l = 0, r = n - 1;
    while (l <= r)
    {
        if (s[l] != s[r])
        {
            l++;
            r--;
        }
        else
            return r - l + 1;
    }
    return 0;
}

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        string s(n, 0);
        for (int i = 0; i < n; i++)
            cin >> s[i];
        cout << calc(s) << endl;
    }
}