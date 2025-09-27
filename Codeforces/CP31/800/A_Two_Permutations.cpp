#include <bits/stdc++.h>
using namespace std;

int func(int n, int a, int b)
{
    if (n == a && a == b)
        return 1;
    if (a + b + 2 <= n)
        return 1;
    return 0;
}
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, a, b;
        cin >> n >> a >> b;
        int ans = func(n, a, b);
        if (ans)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}