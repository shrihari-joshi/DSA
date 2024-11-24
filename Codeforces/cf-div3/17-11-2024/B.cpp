#include <bits/stdc++.h>
using namespace std;

pair<int, int> Intercepted(vector<int> &arr, int k)
{
    int prod = k - 2;
    if (prod == 1)
        return {1, 1};
    vector<int> factors;
    for (int i = 1; i <= prod; i++)
        if (prod % i == 0)
            factors.push_back(i);
    int sz = factors.size();

    if (sz % 2 == 0)
    {
        for (int i = 0; i < sz / 2; i++)
        {
            auto it1 = find(arr.begin(), arr.end(), factors[i]);
            if (it1 != arr.end())
            {
                auto it2 = find(arr.begin(), arr.end(), factors[sz - i - 1]);
                if (it2 != arr.end())
                    return {factors[i], factors[sz - i - 1]};
            }
        }
    }
    else
    {
        int i = 0;
        for (i; i < sz / 2; i++)
        {
            auto it1 = find(arr.begin(), arr.end(), factors[i]);
            if (it1 != arr.end())
            {
                auto it2 = find(arr.begin(), arr.end(), factors[sz - i - 1]);
                if (it2 != arr.end())
                    return {factors[i], factors[sz - i - 1]};
            }
        }
        return {factors[i], factors[i]};
    }
}

int main()
{

    int tc;
    cin >> tc;
    int ind = 0;
    vector<pair<int, int>> ans(tc, {0, 0});
    while (tc--)
    {
        int k;
        cin >> k;
        vector<int> arr(k);
        for (int i = 0; i < k; i++)
            cin >> arr[i];

        ans[ind] = Intercepted(arr, k);
        ind++;
    }
    for (auto it : ans)
        cout << it.first << " " << it.second << endl;
    return 0;
}