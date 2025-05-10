#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
{
    int n = mat.size(), m = mat[0].size();

    vector<vector<int>> ans(n, vector<int>(m, 0));
    vector<vector<bool>> vis(n, vector<bool>(m, false));

    queue<pair<pair<int, int>, int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 0)
            {
                vis[i][j] = true;
                q.push({{i, j}, 0});
                ans[i][j] == 0;
            }
        }
    }
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};

    while (!q.empty())
    {
        int x = q.front().first.first, y = q.front().first.second;
        int cnt = q.front().second;
        q.pop();
        ans[x][y] = cnt;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny])
            {
                vis[nx][ny] = true;
                q.push({{nx, ny}, cnt + 1});
            }
        }
    }
    return ans;
}
int main()
{
    vector<vector<int>> mat = {
        {0, 1, 1},
        {0, 1, 1},
        {1, 1, 1}};

    vector<vector<int>> ans = updateMatrix(mat);
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