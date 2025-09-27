#include <bits/stdc++.h>
using namespace std;

void func(int n, vector<int> &arr)
{
    int mini = INT_MAX;
    for (int i = 0; i < n; i++)
        mini = min(mini, abs(arr[i]));

    cout << mini << endl;
    return;
}
int main()
{

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    func(n, arr);
    return 0;
}