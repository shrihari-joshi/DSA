#include <bits/stdc++.h>
using namespace std;

int oddQueries(vector<int> &arr, int l, int r, int k)
{
    int n = arr.size(), sum = 0;

    for (int i = 0; i < l - 1; i++)
        sum += arr[i];

    for (int i = l - 1; i <= r - 1; i++)
        sum += k;

    for (int i = r; i < n; i++)
        sum += arr[i];

    return sum % 2;
}

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, q;
        cin >> n;
        cin >> q;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        while (q--)
        {
            int l, r, k;
            cin >> l;
            cin >> r;
            cin >> k;
            if (oddQueries(arr, l, r, k) == 1)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
    return 0;
}