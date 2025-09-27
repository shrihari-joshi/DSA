#include <bits/stdc++.h>
using namespace std;

int func(int N, vector<int> &arr)
{
    int p = 0, n = 0;
    for (int i = 0; i < N; i++)
    {
        if (arr[i] == -1)
            n++;
        else
            p++;
    }
    if (p >= n && n % 2 == 0)
        return 0;
    if (p >= n && n % 2 == 1)
        return 1;
    int cnt = 0;
    while (p < n)
    {
        p++;
        n--;
        cnt++;
    }
    if (p >= n && n % 2 == 0)
        return cnt;
    if (p >= n && n % 2 == 1)
        return cnt + 1;
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
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << func(n, arr) << endl;
    }
    return 0;
}