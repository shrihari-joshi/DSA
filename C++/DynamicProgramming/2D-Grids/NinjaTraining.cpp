#include <bits/stdc++.h>
using namespace std;
int recurse(int i, int j, vector<vector<int>> &arr, vector<vector<int>> &dp)
{
    int n = arr.size(), m = arr[0].size();
    if (j < 0 || j > m)
        return -1e8;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (i == n - 1)
        return arr[i][j];

    int ans = 0;
    for (int dj = 0; dj < m; dj++)
    {
        if (j == dj)
            continue;
        ans = max(ans, arr[i][j] + recurse(i + 1, dj, arr, dp));
    }
    return dp[i][j] = ans;
}
int tabulation(vector<vector<int>> &arr)
{
    int n = arr.size(), m = arr[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    for (int j = 0; j < m; j++)
    {
        dp[n - 1][j] = arr[n - 1][j];
    }
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 0; j < m; j++)
        {
            for (int dj = 0; dj < m; dj++)
            {
                if (j == dj)
                    continue;
                dp[i][j] = max(dp[i][j], arr[i][j] + dp[i + 1][dj]);
            }
        }
    }
    int ans = 0;
    for (int j = 0; j < m; j++)
    {
        ans = max(ans, dp[0][j]);
    }
    return ans;
}
int spaceOptimized(vector<vector<int>> &arr)
{
    int n = arr.size(), m = arr[0].size();
    vector<int> dp(m, -1);
    for (int j = 0; j < m; j++)
    {
        dp[j] = arr[n - 1][j];
    }
    for (int i = n - 2; i >= 0; i--)
    {
        vector<int> temp(m, -1);
        for (int j = 0; j < m; j++)
        {
            for (int dj = 0; dj < m; dj++)
            {
                if (j == dj)
                    continue;
                temp[j] = max(temp[j], arr[i][j] + dp[dj]);
            }
        }
        dp = temp;
    }
    int ans = 0;
    for (int j = 0; j < m; j++)
        ans = max(ans, dp[j]);
    
    return ans;
}
int maximumPoints(vector<vector<int>> &arr)
{
    // int n = arr.size(), m = arr[0].size();
    // vector<vector<int>> dp(n, vector<int>(m, -1));
    // int ans = 0;
    // for (int j = 0; j < m; j++)
    // {
    //     ans = max(ans, recurse(0, j, arr, dp));
    // }
    // return ans;
    // return tabulation(arr);
    return spaceOptimized(arr);
}

int main()
{
    vector<vector<int>> arr = {{1, 2, 5}, {3, 1, 1}, {3, 3, 3}};
    cout << "Ans: " << maximumPoints(arr) << endl;
}