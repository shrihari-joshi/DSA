#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> floodFillBFS(vector<vector<int>> &image, int sr, int sc, int color)
{
    if (image[sr][sc] == color)
        return image;
    int m = image.size(), n = image[0].size();
    vector<vector<int>> grid = image;
    vector<vector<int>> vis(m, vector<int>(n, 0));

    int ogcolor = grid[sr][sc];
    queue<pair<int, int>> q;

    q.push({sr, sc});
    vis[sr][sc] = 1;

    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        grid[x][y] = color;
        for (int i = 0; i < 4; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < m && ny < n && grid[nx][ny] == ogcolor && vis[nx][ny] != 1)
            {
                q.push({nx, ny});
                vis[nx][ny] = 1;
            }
        }
    }
    return grid;
}

void dfs(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &image, int newColor, vector<int> &dRow,
         vector<int> &dCol, int iniColor)
{

    grid[row][col] = newColor;
    int n = image.size();
    int m = image[0].size();
    for (int i = 0; i < 4; i++)
    {
        int nrow = row + dRow[i];
        int ncol = col + dCol[i];
        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == iniColor &&
            grid[nrow][ncol] != newColor)
        {
            dfs(nrow, ncol, grid, image, newColor, dRow, dCol, iniColor);
        }
    }
}

vector<vector<int>> floodFillDFS(vector<vector<int>> &image, int sr, int sc, int newColor)
{
    int iniColor = image[sr][sc];
    vector<vector<int>> grid = image;
    vector<int> dRow = {-1, 0, +1, 0};
    vector<int> dCol = {0, +1, 0, -1};
    dfs(sr, sc, grid, image, newColor, dRow, dCol, iniColor);
    return grid;
}

int main()
{
    vector<vector<int>> image = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    // vector<vector<int>> image = {{0, 0, 0}, {0, 1, 0}};
    // vector<vector<int>> ans = floodFillBFS(image, 1, 1, 2);
    vector<vector<int>> ans = floodFillDFS(image, 1, 1, 2);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[0].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}