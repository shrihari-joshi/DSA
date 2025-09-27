#include <bits/stdc++.h>
using namespace std;

void func(int n, int k, vector<int> &arr)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == k)
        {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
    return;
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
        func(n, k, arr);
    }
    return 0;
}