#include <bits/stdc++.h>
using namespace std;

int func(int n)
{
    // 1-9 -- 9
    // 10-99 -- 9
    // 100 - 999 -- 9
    // 1000 - 9999 -- 9
    int res = 0, d = 0, temp = n;
    while (temp > 0)
    {
        d++;
        temp /= 10;
    }
    if (d == 1)
        return n;
    res += (d - 1) * 9;
    temp = pow(10, d - 1);
    while (temp <= n)
    {
        res++;
        temp += pow(10, d - 1);
    }
    return res;
}
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        cout << func(n) << endl;
    }
    return 0;
}