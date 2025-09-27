#include <bits/stdc++.h>
using namespace std;

void calc(vector<int> &arr)
{
    int n = arr.size();
    bool possible = false;
    for (int i = 0; i < n && !possible; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (__gcd(arr[i], arr[j]) <= 2)
            {
                possible = true;
                break;
            }
        }
    }

    cout << (possible ? "Yes" : "No") << "\n";
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