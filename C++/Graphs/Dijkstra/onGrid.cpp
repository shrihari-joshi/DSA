#include <bits/stdc++.h>
using namespace std;

int shortestDistance(int n, int m, vector<vector<int>> grid, int X, int Y)
{
    // code here
    if (grid[0][0] == 0)
        return -1;
    if (X == &&Y == 0)
        return 0;

    queue<vector<int>> que;
    vector<vector<int>> dis(n, vector<int>(m, INT_MAX));

    que.push({0, 0, 0}); // dist, row, col
    dis[0][0] = 0;

    vector<int> dx = {0, 1, 0, -1};
    vector<int> dy = {1, 0, -1, 0};

    while (!que.empty())
    {
        auto temp = que.front();
        que.pop();
        int d = temp[0], r = temp[1], c = temp[2];

        for (int i = 0; i < 4; i++)
        {
            int nr = r + dx[i];
            int nc = c + dy[i];

            if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                grid[nr][nc] == 1 && dis[nr][nc] > d + 1)
            {
                dis[nr][nc] = d + 1;
                if (nr == X && nc == Y)
                    return d + 1;
                que.push({d + 1, nr, nc});
            }
        }
    }
    return -1;
}

int main()
{
    int n = 3, m = 4;
    vector<vector<int>> grid = {{1, 0, 0, 0}, {1, 1, 0, 1}, {0, 1, 1, 1}};
    int X = 2, Y = 3;
    cout << shortestDistance(n, m, grid, X, Y) << endl;
    return 0;
}