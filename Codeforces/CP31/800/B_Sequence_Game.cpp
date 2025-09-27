#include <bits/stdc++.h>
using namespace std;

void calc(vector<int> &arr)
{
    int n = arr.size();
    vector<int> res;
    res.push_back(arr[0]);
    for (int i = 1; i < n; i++)
    {
        if (res.back() > arr[i])
            res.push_back(1);

        res.push_back(arr[i]);
    }
    cout << res.size() << endl;
    for (int it : res)
    {
        cout << it << " ";
    }
    cout << endl;
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
            cin >> arr[i];
        calc(arr);
    }
}