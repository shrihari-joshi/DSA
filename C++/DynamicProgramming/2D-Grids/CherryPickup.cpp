#include <bits/stdc++.h>
using namespace std;

int recurse(int i, int j1, int j2, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)
{
    int n = grid.size(), m = grid[0].size();

    if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m)
        return -1e8;

    if (dp[i][j1][j2] != -1)
        return dp[i][j1][j2];

    if (i == n - 1)
    {
        if (j1 == j2)
            return grid[i][j1];
        else
            return grid[i][j1] + grid[i][j2];
    }
    int ans = 0;
    for (int dj1 = -1; dj1 <= 1; dj1++)
    {
        for (int dj2 = -1; dj2 <= 1; dj2++)
        {
            if (j1 == j2)
                ans = max(ans, grid[i][j1] + recurse(i + 1, j1 + dj1, j2 + dj2, grid, dp));
            else
                ans = max(ans, grid[i][j1] + grid[i][j2] + recurse(i + 1, j1 + dj1, j2 + dj2, grid, dp));
        }
    }
    return dp[i][j1][j2] = ans;
}
int tabulation(vector<vector<int>> &grid)
{
    int n = grid.size(), m = grid[0].size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));

    // Base case
    for (int j1 = 0; j1 < m; j1++)
    {
        for (int j2 = 0; j2 < m; j2++)
        {
            dp[n - 1][j1][j2] = (j1 == j2) ? grid[n - 1][j1] : grid[n - 1][j1] + grid[n - 1][j2];
        }
    }

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j1 = 0; j1 < m; j1++)
        {
            for (int j2 = 0; j2 < m; j2++)
            {
                int ans = 0;
                for (int dj1 = -1; dj1 <= 1; dj1++)
                {
                    for (int dj2 = -1; dj2 <= 1; dj2++)
                    {
                        int temp = 0;
                        if (j1 == j2)
                            temp = grid[i][j1];
                        else
                            temp = grid[i][j1] + grid[i][j2];

                        if (j1 + dj1 >= 0 && j1 + dj1 < m && j2 + dj2 >= 0 && j2 + dj2 < m)
                        {
                            ans = max(ans, temp + dp[i + 1][j1 + dj1][j2 + dj2]);
                        }
                    }
                }
                dp[i][j1][j2] = ans;
            }
        }
    }
    return dp[0][0][m - 1];
}
int solve(int n, int m, vector<vector<int>> &grid)
{
    // vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
    // return recurse(0, 0, m - 1, grid, dp);
    return tabulation(grid);
}

int main()
{
    vector<vector<int>> grid = {{3, 1, 1}, {2, 5, 1}, {1, 5, 5}, {2, 1, 1}};
    int n = grid.size(), m = grid[0].size();
    cout << "Ans: " << solve(n, m, grid) << endl;
    return 0;
}