#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int recurse(int i, int j, vector<vector<int>> &grid, int n)
{
    if (i == n - 1)
        return grid[i][j];

    int down = recurse(i + 1, j, grid, n);
    int dleft = INT_MAX;
    if (j > 0)
        dleft = recurse(i + 1, j - 1, grid, n);
    int dright = INT_MAX;
    if (j < n - 1)
        dright = recurse(i + 1, j + 1, grid, n);

    return min(min(dleft, dright), down) + grid[i][j];
}
int memoi(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp, int n)
{
    if (i == n - 1)
        return grid[i][j];
    if (dp[i][j] != -1)
        return dp[i][j];

    int down = memoi(i + 1, j, grid, dp, n);
    int dleft = INT_MAX;
    if (j > 0)
        dleft = memoi(i + 1, j - 1, grid, dp, n);
    int dright = INT_MAX;
    if (j < n - 1)
        dright = memoi(i + 1, j + 1, grid, dp, n);

    return dp[i][j] = min(min(dleft, dright), down) + grid[i][j];
}
int tabulation(vector<vector<int>> &grid, int n)
{
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int j = 0; j < n; j++)
        dp[n - 1][j] = grid[n - 1][j];

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            int down = dp[i + 1][j];
            int dleft = INT_MAX;
            if (j > 0)
                dleft = dp[i + 1][j - 1];
            int dright = INT_MAX;
            if (j < n - 1)
                dright = dp[i + 1][j + 1];

            dp[i][j] = min(min(dleft, dright), down) + grid[i][j];
        }
    }
    int ans = INT_MAX;
    for (int j = 0; j < n; j++)
    {
        ans = min(ans, dp[0][j]);
    }
    return ans;
}
int space(vector<vector<int>> &grid, int n)
{
    vector<int> prev(n, 0), curr(n, 0);

    for (int j = 0; j < n; j++)
        prev[j] = grid[n - 1][j];

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            int down = prev[j];
            int dleft = INT_MAX;
            if (j > 0)
                dleft = prev[j - 1];
            int dright = INT_MAX;
            if (j < n - 1)
                dright = prev[j + 1];

            curr[j] = min(min(dleft, dright), down) + grid[i][j];
        }
        prev = curr;
    }
    int ans = INT_MAX;
    for (int j = 0; j < n; j++)
    {
        ans = min(ans, prev[j]);
    }
    return ans;
}
int main()
{
    vector<vector<int>> grid = {{2, 1, 3}, {6, 5, 4}, {7, 8, 9}};
    // vector<vector<int>> grid = {{-19, 57}, {-40, -5}};

    int n = grid.size();
    // int ans = INT_MAX;
    // for (int j = 0; j < n; j++)
    //     ans = min(ans, recurse(0, j, grid, n));

    // int ans = INT_MAX;
    // vector<vector<int>> dp(n, vector<int>(n, -1));
    // for (int j = 0; j < n; j++)
    //     ans = min(ans, memoi(0, j, grid, dp, n));

    int ans = tabulation(grid, n);

    // int ans = space(grid, n);

    cout << "\nAnswer: " << ans;

    return 0;
}