#include <bits/stdc++.h>
using namespace std;

int calc(vector<int> &arr)
{
    int x = 0, n = arr.size();
    while (x <= 256)
    {
        int xorsum = 0;
        for (int i = 0; i < n; i++)
        {
            int temp = arr[i] ^ x;
            xorsum = xorsum ^ temp;
        }
        if (xorsum == 0)
            return x;
        x++;
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
        {
            cin >> arr[i];
        }
        cout << calc(arr) << endl;
    }
}