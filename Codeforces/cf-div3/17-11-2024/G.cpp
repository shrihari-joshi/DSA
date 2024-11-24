#include <bits/stdc++.h>
using namespace std;

int dfs(const vector<vector<int>> &graph, int s, int g, int n)
{
    vector<long long> dp(n, 0);
    dp[s] = 1;

    for (int i = s; i < n; ++i)
    {
        if (dp[i] > 0)
        {
            for (int n : graph[i])
            {
                if (n >= i)
                    dp[n] += dp[i];
            }
        }
    }

    return dp[g];
}

int Natlan(vector<int> &arr, int n)
{
    vector<vector<int>> graph(n);
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            int temp = __gcd(arr[i], arr[j]);
            if (temp != 1)
            {
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }
    return dfs(graph, 0, n - 1, n);
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << Natlan(arr, n);
    return 0;
}