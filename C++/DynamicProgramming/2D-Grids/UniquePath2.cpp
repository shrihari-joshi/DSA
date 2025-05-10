#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int recurse(int m, int n, vector<vector<int>> &grid)
{
    if (m >= 0 && n >= 0 && grid[m][n] == 1)
        return 0;
    if (m == 0 && n == 0)
        return 1;
    if (m < 0 || n < 0)
        return 0;

    int up = recurse(m - 1, n, grid);
    int left = recurse(m, n - 1, grid);

    return up + left;
}
int memoi(int m, int n, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    if (m >= 0 && n >= 0 && grid[m][n] == 1)
    {
        dp[m][n] = 0;
        return 0;
    }
    if (m == 0 && n == 0)
        return 1;
    if (m < 0 || n < 0)
        return 0;

    if (dp[m][n] != -1)
        return dp[m][n];

    int up = memoi(m - 1, n, grid, dp);
    int left = memoi(m, n - 1, grid, dp);

    dp[m][n] = up + left;
    return up + left;
}

int main()
{
    // vector<vector<int>> grid = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    vector<vector<int>> grid = {{0, 1}, {0, 0}};
    int m = grid.size(), n = grid[0].size();
    // 	int ans = recurse(m-1, n-1, grid);
    // vector<vector<int>> dp (m, vector<int> (n, -1));
    // int ans = memoi(m-1, n-1, grid, dp);
    int ans = tabulation(m, n, grid);
    // int ans = space(m, n, grid);
    cout << ans;

    return 0;
}