#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int recurse(int m, int n, vector<vector<int>> &grid)
{
    if (m == 0 && n == 0)
        return grid[0][0];

    int up = INT_MAX, left = INT_MAX;
    if (m > 0)
        up = recurse(m - 1, n, grid);
    if (n > 0)
        left = recurse(m, n - 1, grid);

    return min(left, up) + grid[m][n];
}
int memoi(int m, int n, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    if (m == 0 && n == 0)
        return grid[0][0];

    if (dp[m][n] != -1)
        return dp[m][n];

    int up = INT_MAX, left = INT_MAX;
    if (m > 0)
        up = memoi(m - 1, n, grid, dp);
    if (n > 0)
        left = memoi(m, n - 1, grid, dp);

    dp[m][n] = min(left, up) + grid[m][n];
    return dp[m][n];
}
int tabulation(int m, int n, vector<vector<int>> &grid)
{
    vector<vector<int>> dp(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
            {
                dp[0][0] = grid[0][0];
                continue;
            }

            int up = INT_MAX, left = INT_MAX;
            if (i > 0)
                up = dp[i - 1][j];
            if (j > 0)
                left = dp[i][j - 1];

            dp[i][j] = min(left, up) + grid[i][j];
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return dp[m - 1][n - 1];
}
int space(int m, int n, vector<vector<int>> &grid)
{
    vector<int> prev(n, 0), curr(n, 0);

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
            {
                curr[0] = grid[0][0];
                continue;
            }

            int up = INT_MAX, left = INT_MAX;
            if (i > 0)
                up = prev[j];
            if (j > 0)
                left = curr[j - 1];

            curr[j] = min(left, up) + grid[i][j];
        }
        prev = curr;
    }

    return prev[n - 1];
}

int main()
{
    vector<vector<int>> grid = {{1, 2, 3}, {4, 5, 6}};
    // vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};

    int m = grid.size(), n = grid[0].size();

    // int ans = recurse(m - 1, n - 1, grid);

    vector<vector<int>> dp(m, vector<int>(n, -1));
    int ans = memoi(m - 1, n - 1, grid, dp);

    // int ans = tabulation(m, n, grid);

    // int ans = space(m, n, grid);

    cout << "\nAnswer: " << ans;

    return 0;
}