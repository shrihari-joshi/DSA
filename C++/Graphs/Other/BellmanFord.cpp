#include <bits/stdc++.h>
using namespace std;

vector<int> bellmanFord(int V, vector<vector<int>> &edges, int src)
{
    vector<int> dist(V, 1e8);
    dist[src] = 0;
    for (int i = 0; i < V; i++)
    {
        for (auto it : edges)
        {
            int from = it[0], to = it[1], wt = it[2];
            if (dist[from] != 1e8 && dist[to] > dist[from] + wt)
                dist[to] = dist[from] + wt;
        }
    }

    for (auto it : edges)
    {
        int from = it[0], to = it[1], wt = it[2];
        if (dist[from] != 1e8 && dist[to] > dist[from] + wt)
            return {-1};
    }
    return dist;
}

int main()
{
    // V = 4, edges[][] = [[0, 1, 4], [1, 2, -6], [2, 3, 5], [3, 1, -2]], src = 0
    int V = 4;
    vector<vector<int>> edges = {{0, 1, 4}, {1, 2, -6}, {2, 3, 5}, {3, 1, -2}};
    int src = 0;

    vector<int> result = bellmanFord(V, edges, src);
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";

    cout << endl;
    return 0;
}