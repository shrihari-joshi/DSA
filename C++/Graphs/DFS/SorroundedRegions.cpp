#include <bits/stdc++.h>
using namespace std;

void dfs(int row, int col, vector<vector<char>> &board, vector<vector<int>> &vis, vector<int> &dx, vector<int> &dy)
{
    vis[row][col] = 1;
    int m = board.size(), n = board[0].size();
    for (int i = 0; i < 4; i++)
    {
        int nrow = row + dx[i], ncol = col + dy[i];
        if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && vis[nrow][ncol] == 0 && board[nrow][ncol] == 'O')
            dfs(nrow, ncol, board, vis, dx, dy);
    }
}
void solve(vector<vector<char>> &board)
{
    int m = board.size(), n = board[0].size();
    vector<vector<int>> vis(m, vector<int>(n, 0));
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};

    for (int j = 0; j < n; j++)
    {
        if (board[0][j] == 'O')
            dfs(0, j, board, vis, dx, dy);
        if (board[m - 1][j] == 'O')
            dfs(m - 1, j, board, vis, dx, dy);
    }

    for (int i = 0; i < m; i++)
    {
        if (board[i][0] == 'O')
            dfs(i, 0, board, vis, dx, dy);
        if (board[i][n - 1] == 'O')
            dfs(i, n - 1, board, vis, dx, dy);
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (vis[i][j] == 0 && board[i][j] == 'O')
                board[i][j] = 'X';
        }
    }
}

int main()
{
    vector<vector<char>> mat = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}};

    solve(mat);
    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[0].size(); j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}