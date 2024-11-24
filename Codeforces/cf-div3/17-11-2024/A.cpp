#include <bits/stdc++.h>
using namespace std;

int Twice(vector<int> &arr)
{
    int n = arr.size(), ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j] && arr[j] != -1)
            {
                arr[j] = -1;
                ans++;
                break;
            }
        }
    }
    return ans;
}

int main()
{

    int tc;
    cin >> tc;
    int ind = 0;
    vector<int> ans(tc, 0);
    while (tc--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        ans[ind] = Twice(arr);
        ind++;
    }
    for (auto it : ans)
        cout << it << endl;
    return 0;
}