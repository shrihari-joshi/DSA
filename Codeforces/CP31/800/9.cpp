#include <bits/stdc++.h>
using namespace std;

void func(int n, vector<int> &arr)
{
    int sum = 0;
    for (int i = 0; i < n - 1; i++)
        sum += arr[i];

    cout << -sum << endl;
    return;
}
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<int> arr(n - 1);
        for (int i = 0; i < n - 1; i++)
        {
            cin >> arr[i];
        }
        func(n, arr);
    }
    return 0;
}