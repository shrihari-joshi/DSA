#include <bits/stdc++.h>
using namespace std;

bool func(int n, int k, string str)
{
    map<char, int> mp;
    for (int i = 0; i < n; i++)
        mp[str[i]]++;
    int cnt = 0;
    for (auto it : mp)
    {
        if (it.second % 2 == 1)
            cnt++;
    }
    cnt--;
    if (cnt <= k)
        return 1;
    return 0;
}
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, k;
        cin >> n >> k;
        string str(n, ' ');
        for (int i = 0; i < n; i++)
            cin >> str[i];
        if (func(n, k, str))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}