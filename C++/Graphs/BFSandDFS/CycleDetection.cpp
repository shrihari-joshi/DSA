#include <bits/stdc++.h>
using namespace std;

bool detectCycleDFS(int node, int parent, vector<vector<int>> &adj, vector<int> &vis)
{
    vis[node] = 1;

    for (auto adjNode : adj[node])
    {
        if (!vis[adjNode])
        {
            if (detectCycleDFS(adjNode, node, adj, vis))
                return true;
        }

        else if (adjNode != parent)
            return true;
    }
    return false;
}

bool detectCycleBFS(int src, vector<vector<int>> &adj, vector<int> &vis)
{
    vis[src] = 1;
    queue<pair<int, int>> q;
    q.push({src, -1});
    while (!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (auto adjNode : adj[node])
        {
            if (!vis[adjNode])
            {
                vis[adjNode] = 1;
                q.push({adjNode, node});
            }
            else if (adjNode != parent)
                return true;
        }
    }
    return false;
}
bool isCycle(vector<vector<int>> &adj)
{
    int n = adj.size();
    vector<int> vis(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
            // if (detectCycleBFS(i, adj, vis))
            if (detectCycleDFS(i, -1, adj, vis))
                return true;
    }
    return false;
}
int main()
{
    // vector<vector<int>> adj = {
    //     {1},
    //     {0, 2, 4},
    //     {1, 3},
    //     {2, 4},
    //     {1, 3}};
    vector<vector<int>> adj = {
        {},
        {2},
        {1, 3},
        {2}};

    bool ans = isCycle(adj);
    if (ans)
        cout << "Cycle Detected";
    else
        cout << "Not Detected";

    return 0;
}