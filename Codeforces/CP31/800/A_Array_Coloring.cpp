#include <bits/stdc++.h>
using namespace std;

void func(int n, vector<int> &arr)
{
    int odd = 0, even = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 == 0)
            even++;
        else
            odd++;
    }
    if (odd % 2 == 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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