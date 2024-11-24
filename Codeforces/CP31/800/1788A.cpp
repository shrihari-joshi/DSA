#include <bits/stdc++.h>
using namespace std;

int oneTwo(vector<int> &arr)
{
    int n = arr.size(), twos = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 2)
            twos++;
    }
    int cnt = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] == 2)
            cnt++;

        if (2 * cnt == twos)
            return i + 1;
    }
    return -1;
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

        cout << oneTwo(arr) << endl;
    }
    return 0;
}