#include <bits/stdc++.h>
using namespace std;

bool func(long long n, long long k, long long x)
{
    long long mini = 1LL * k * (k + 1) / 2;
    long long maxi = 1LL * n * (n + 1) / 2 - 1LL * (n - k) * (n - k + 1) / 2;

    if (mini <= x && x <= maxi)
        return 1;
    return 0;
}
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        long long n, k, x;
        cin >> n >> k >> x;
        if (func(n, k, x))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}