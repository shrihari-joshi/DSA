#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> spanningTree(int V, vector<vector<vector<int>>> adj)
{
    vector<pair<int, int>> mst;
    vector<int> vis(V, 0);
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
                   greater<pair<int, pair<int, int>>>>
        pq;
    int sum = 0;

    pq.push({0, {0, -1}}); // wt, node, parent
    while (!pq.empty())
    {
        int wt = pq.top().first;
        int node = pq.top().second.first;
        int parent = pq.top().second.second;
        pq.pop();
        if (!vis[node])
        {
            vis[node] = 1;
            if (parent != -1)
            {
                sum += wt;
                mst.push_back({node, parent});
            }
        }
        for (auto it : adj[node])
        {
            int adjNode = it[0];
            int edgeWt = it[1];
            if (!vis[adjNode])
                pq.push({edgeWt, {adjNode, node}});
        }
    }
    return mst;
}
int main()
{
    int V = 4;
    vector<vector<vector<int>>> adj = {
        {{1, 10}, {2, 6}, {3, 5}},
        {{0, 10}, {3, 15}},
        {{0, 6}, {3, 4}},
        {{0, 5}, {1, 15}, {2, 4}}};

    vector<pair<int, int>> mst = spanningTree(V, adj);
    cout << "Minimum Spanning Tree Edges:" << endl;
    for (auto edge : mst)
    {
        cout << edge.first << " - " << edge.second << endl;
    }

    return 0;
}