#include <bits/stdc++.h>
using namespace std;

void func(int n, vector<int> &arr)
{
    if (arr[0] > arr[1])
    {
        cout << "NO" << endl;
        return;
    }
    for (int i = 1; i < n - 1; i++)
    {
        if (arr[i - 1] < arr[i] && arr[i] > arr[i + 1])
        {
            if (arr[i - 1] < arr[i + 1])
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
    }
    cout << "YES" << endl;
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
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        func(n, arr);
    }
    return 0;
}