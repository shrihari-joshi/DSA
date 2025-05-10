#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    vector<int> rank, parent, size;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
        {
            size[i] = 1;
            parent[i] = i;
        }
    }

    int findUParent(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUParent(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);

        if (ulp_u == ulp_v)
            return;

        if (rank[ulp_u] < rank[ulp_v])
            parent[ulp_u] = ulp_v;
        else if (rank[ulp_u] > rank[ulp_v])
            parent[ulp_v] = ulp_u;
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v)
    {
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);

        if (ulp_u == ulp_v)
            return;

        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

int spanningTree(int V, vector<vector<int>> adj[])
{
    vector<pair<int, pair<int, int>>> edges;
    for (int i = 0; i < V; i++)
    {
        for (auto it : adj[i])
            edges.push_back({it[1], {i, it[0]}}); // wt, node, adj
    }
    sort(edges.begin(), edges.end());
    DisjointSet ds(V);

    int mstWeight = 0;
    for (auto edge : edges)
    {
        int weight = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;

        if (ds.findUParent(u) != ds.findUParent(v))
        {
            mstWeight += weight;
            ds.unionBySize(u, v);
        }
    }

    return mstWeight;
}

int main()
{
    int V = 4;
    vector<vector<int>> adj[V] = {
        {{1, 10}, {2, 6}, {3, 5}},
        {{0, 10}, {3, 15}},
        {{0, 6}, {3, 4}},
        {{0, 5}, {1, 15}, {2, 4}}};

    cout << "Minimum Spanning Tree Weight: " << spanningTree(V, adj) << endl;

    return 0;
}