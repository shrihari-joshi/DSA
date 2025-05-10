#include <bits/stdc++.h>
using namespace std;

int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
{
    // instead we could have also done Dijkstra's Algo for each node
    vector<vector<int>> dist(n, vector<int>(n, 1e9 + 7));
    for (int i = 0; i < n; i++)
        dist[i][i] = 0;

    for (auto it : edges)
    {
        int from = it[0], to = it[1], wt = it[2];
        dist[from][to] = wt;
        dist[to][from] = wt;
    }

    for (int via = 0; via < n; via++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                dist[i][j] = min(dist[i][via] + dist[via][j], dist[i][j]);
            }
        }
    }
    int city = -1, mini = n;
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            if (dist[i][j] <= distanceThreshold)
                cnt++;
        }
        if (cnt <= mini)
        {
            mini = cnt;
            city = i;
        }
    }
    return city;
}

int main()
{

    // n = 5, edges = [[0,1,2],[0,4,8],[1,2,3],[1,4,2],[2,3,1],[3,4,1]], distanceThreshold = 2
    int n = 5;
    vector<vector<int>> edges = {{0, 1, 2}, {0, 4, 8}, {1, 2, 3}, {1, 4, 2}, {2, 3, 1}, {3, 4, 1}};
    int distanceThreshold = 2;
    cout << findTheCity(n, edges, distanceThreshold) << endl;
    return 0;
}