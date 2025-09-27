
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll func(int a, int b, vector<int> &arr)
{
    int n = arr.size();
    ll sec = 0;
    for (int i = 0; i < n; i++)
        sec += min(arr[i], a - 1);
    return sec + b;
}
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int a, b, n;
        cin >> a >> b >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cout << func(a, b, arr) << endl;
    }
    return 0;
}