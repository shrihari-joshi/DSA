#include <bits/stdc++.h>
using namespace std;

void dfs(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &vis, vector<int> &dx, vector<int> &dy)
{
    vis[row][col] = 1;
    int m = grid.size(), n = grid[0].size();
    for (int i = 0; i < 4; i++)
    {
        int nrow = row + dx[i], ncol = col + dy[i];
        if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1)
            dfs(nrow, ncol, grid, vis, dx, dy);
    }
}

int numEnclaves(vector<vector<int>> &grid)
{
    int m = grid.size(), n = grid[0].size(), cnt = 0;
    vector<vector<int>> vis(m, vector<int>(n, 0));
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};

    for (int j = 0; j < n; j++)
    {
        if (grid[0][j] == 1)
            dfs(0, j, grid, vis, dx, dy);
        if (grid[m - 1][j] == 1)
            dfs(m - 1, j, grid, vis, dx, dy);
    }

    for (int i = 0; i < m; i++)
    {
        if (grid[i][0] == 1)
            dfs(i, 0, grid, vis, dx, dy);
        if (grid[i][n - 1] == 1)
            dfs(i, n - 1, grid, vis, dx, dy);
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (vis[i][j] == 0 && grid[i][j] == 1)
                cnt++;
        }
    }
    return cnt;
}

int main()
{
    // implementation of floodfill algorithm
    //  vector<vector<int>> grid = {{0, 0, 0, 0}, {1, 0, 1, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}};
    vector<vector<int>> grid = {{0, 1, 1, 0}, {0, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 0, 0}};
    int ans = numEnclaves(grid);
    cout << ans;
    return 0;
}