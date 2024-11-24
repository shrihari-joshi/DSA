#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int recurse(int m, int n)
{
    if (m == 0 && n == 0)
        return 1;
    if (m < 0 || n < 0)
        return 0;

    int up = recurse(m - 1, n);
    int left = recurse(m, n - 1);

    return up + left;
}
int memoi(int m, int n, vector<vector<int>> &dp)
{
    if (m == 0 && n == 0)
        return 1;
    if (m < 0 || n < 0)
        return 0;

    if (dp[m][n] != -1)
        return dp[m][n];

    int up = memoi(m - 1, n, dp);
    int left = memoi(m, n - 1, dp);

    dp[m][n] = up + left;
    return up + left;
}
int tabulation(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
            {
                dp[0][0] = 1;
                continue;
            }
            int up = 0, left = 0;
            if (i > 0)
                up = dp[i - 1][j];
            if (j > 0)
                left = dp[i][j - 1];

            dp[i][j] = up + left;
        }
    }
    return dp[m - 1][n - 1];
}
int space(int m, int n)
{
    vector<int> prev(n, 0);
    for (int i = 0; i < m; i++)
    {
        vector<int> temp(n, 0);
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
            {
                temp[0] = 1;
                continue;
            }
            int up = 0, left = 0;
            if (i > 0)
                up = prev[j];
            if (j > 0)
                left = temp[j - 1];

            temp[j] = up + left;
        }
        prev = temp;
    }
    return prev[n - 1];
}

int main()
{
    int m = 3, n = 7;
    vector<vector<int>> dp(m, vector<int>(n, -1));
    int ans = recurse(m - 1, n - 1);
    // int ans = memoi(m-1, n-1, dp);
    // int ans = tabulation(m, n);
    // int ans = space(m, n);
    cout << ans;

    return 0;
}