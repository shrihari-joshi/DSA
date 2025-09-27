#include <bits/stdc++.h>
using namespace std;

bool isPossible(string x, string s)
{
    int n = x.size(), m = s.size();
    for (int i = 0; i + m <= n; i++)
    {
        int j = 0;
        while (j < m && x[i + j] == s[j])
            j++;

        if (j == m)
            return true;
    }
    return false;
}
int func(int n, int m, string x, string s)
{
    vector<int> mp1(26, 0), mp2(26, 0);
    for (int i = 0; i < n; i++)
        mp1[x[i] - 'a']++;
    for (int i = 0; i < m; i++)
        mp2[s[i] - 'a']++;

    for (int i = 0; i < 26; i++)
        if (mp1[i] == 0 && mp2[i] >= 1)
            return -1;

    for (int cnt = 0; cnt <= 6; cnt++)
    {
        if (isPossible(x, s))
            return cnt;
        x += x;
    }
    return -1;
}
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        string x, s;
        cin >> x;
        cin >> s;
        cout << func(n, m, x, s) << endl;
    }
    return 0;
}