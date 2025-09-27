#include <bits/stdc++.h>
using namespace std;

int func(int n, vector<int> &arr)
{
    int cnt = INT_MAX;
    for (int i = 1; i < n; i++)
    {
        if (arr[i - 1] > arr[i])
            return 0;
        else
            cnt = min(cnt, arr[i] - arr[i - 1]);
    }
    return (cnt / 2) + 1;
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