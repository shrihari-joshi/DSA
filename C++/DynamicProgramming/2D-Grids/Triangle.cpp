#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int recurse(int m, int n, vector<vector<int>> &grid)
{
    int s = grid.size();
    if (m == s - 1)
        return grid[m][n];

    int down = recurse(m + 1, n, grid);
    int diag = recurse(m + 1, n + 1, grid);

    return min(diag, down) + grid[m][n];
}
int memoi(int m, int n, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    int s = grid.size();
    if (m == s - 1)
        return grid[m][n];
    if (dp[m][n] != -1)
        return dp[m][n];

    int down = memoi(m + 1, n, grid, dp);
    int diag = memoi(m + 1, n + 1, grid, dp);

    return dp[m][n] = min(diag, down) + grid[m][n];
}
int tabulation(vector<vector<int>> &grid, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < n; i++)
    {
        dp[n - 1][i] = grid[n - 1][i];
    }

    for (int i = n - 2; i >= 0; i--)
    {
        int first = 0, second = 0;
        for (int j = i; j >= 0; j--)
        {
            first = grid[i][j] + dp[i + 1][j];
            second = grid[i][j] + dp[i + 1][j + 1];
            dp[i][j] = min(first, second);
        }
    }

    return dp[0][0];
}
int space(vector<vector<int>> &grid, int n)
{
    vector<int> prev(n, 0), curr(n, 0);
    for (int i = 0; i < n; i++)
    {
        prev[i] = grid[n - 1][i];
    }

    for (int i = n - 2; i >= 0; i--)
    {
        int first = 0, second = 0;
        for (int j = i; j >= 0; j--)
        {
            first = grid[i][j] + prev[j];
            second = grid[i][j] + prev[j + 1];
            curr[j] = min(first, second);
        }
        prev = curr;
    }

    return prev[0];
}

int main()
{
    vector<vector<int>> grid = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    // vector<vector<int>> grid = {{2}};

    int m = grid.size(), n = grid[m - 1].size();
    // int ans = recurse(0, 0, grid);

    // vector<vector<int>> dp(m, vector<int>(n, -1));
    // int ans = memoi(0, 0, grid, dp);

    int ans = tabulation(grid, m);

    // int ans = space(grid, m);

    cout << "\nAnswer: " << ans;

    return 0;
}