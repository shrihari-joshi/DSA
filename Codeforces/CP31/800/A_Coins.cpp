#include <bits/stdc++.h>
using namespace std;

void func(int n, int k)
{
    if (n % 2 == 0 || (n - k) % 2 == 0)
    {
        cout << "YES" << endl;
        return;
    }
    else
    {
        cout << "NO" << endl;
        return;
    }
}
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        long long n, k;
        cin >> n >> k;
        func(n, k);
    }
    return 0;
}