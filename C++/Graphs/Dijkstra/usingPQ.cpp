#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src)
{
    int n = adj.size();
    vector<int> dis(n, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dis[src] = 0;
    pq.push({0, src});

    while (!pq.empty())
    {
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (auto it : adj[node])
        {

            if (dis[it.first] > d + it.second)
            {
                dis[it.first] = d + it.second;
                pq.push({d + it.second, it.first});
            }
        }
    }
    return dis;
}

int main()
{
    vector<vector<pair<int, int>>> adj = {{{1, 1}, {2, 6}}, {{2, 3}, {0, 1}}, {{1, 3}, {0, 6}}};
    int src = 2;
    vector<int> res = dijkstra(adj, src);
    for (auto i : res)
        cout << i << " ";

    return 0;
}