#include <bits/stdc++.h>
using namespace std;

int func(int n, vector<int> &arr)
{
    int cnt = 0, maxi = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
            cnt++;
        else
        {
            maxi = max(maxi, cnt);
            cnt = 0;
        }
    }
    return max(maxi, cnt);
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