#include <bits/stdc++.h>
using namespace std;

int func(int n, vector<int> &arr)
{
    int cnt = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i - 1] % 2 == arr[i] % 2)
            cnt++;
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
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << func(n, arr) << endl;
    }
    return 0;
}