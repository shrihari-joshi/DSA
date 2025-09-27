#include <bits/stdc++.h>
using namespace std;

void func(int n, int k, int x)
{
    if (x != 1)
    {
        cout << "YES" << endl;
        cout << n << endl;
        while (n > 0)
        {
            cout << "1 ";
            n--;
        }
        cout << endl;
    }
    else if (k == 1 || (k == 2 && n % 2 == 1))
    {
        cout << "NO" << endl;
    }
    else if (n % 2 == 0)
    {
        cout << "YES" << endl;
        cout << n / 2 << endl;
        while (n > 0)
        {
            cout << "2 ";
            n -= 2;
        }
        cout << endl;
    }
    else if (k >= 3 && n % 2 == 1)
    {
        cout << "YES" << endl;
        cout << 1 + (n - 3) / 2 << endl;
        cout << "3 ";
        n -= 3;
        while (n > 0)
        {
            cout << "2 ";
            n -= 2;
        }
        cout << endl;
    }
}
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, k, x;
        cin >> n >> k >> x;
        func(n, k, x);
    }
    return 0;
}