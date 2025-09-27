#include <bits/stdc++.h>
using namespace std;

int func(int n, int k, vector<int> &arr)
{
    int cnt = arr[0];
    for (int i = 1; i < n; i++)
    {
        cnt = max(cnt, arr[i] - arr[i - 1]);
    }
    cnt = max(cnt, 2 * (k - arr[n - 1]));
    return cnt;
}
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << func(n, k, arr) << endl;
    }
    return 0;
}