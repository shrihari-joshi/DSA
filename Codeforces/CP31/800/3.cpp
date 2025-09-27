#include <bits/stdc++.h>
using namespace std;

int func(int n, string str)
{
    int cnt = 0, temp = 0;
    for (int i = 0; i < n; i++)
    {
        if (str[i] == '.')
        {
            temp++;
            cnt++;
            if (temp == 3)
                return 2;
        }
        else
            temp = 0;
    }
    return cnt;
}
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        string str;
        cin >> str;
        cout << func(n, str) << endl;
    }
    return 0;
}