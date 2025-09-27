#include <bits/stdc++.h>
using namespace std;

void func(int n, vector<int> &arr)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }
    if (mp.size() > 2)
    {
        cout << "NO" << endl;
        return;
    }
    if (mp.size() == 1)
    {
        cout << "YES" << endl;
        return;
    }
    int cnt = 0;
    for (auto it : mp)
    {
        if (cnt == 0)
            cnt = it.second;
        else
        {
            if (it.second == cnt || it.second == cnt - 1 || it.second == cnt + 1)
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