#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &res)
{
    vis[node] = 1;
    res.push_back(node);
    for (auto it : adj[node])
    {
        if (vis[it] == 0)
            dfs(it, adj, vis, res);
    }
}
vector<int> dfsOfGraph(vector<vector<int>> &adj)
{
    vector<int> vis(adj.size(), 0);
    vector<int> res;
    dfs(0, adj, vis, res);
    return res;
}

int main()
{
    vector<vector<int>> adj = {{2, 3, 1}, {0}, {0, 4}, {0}, {2}};
    vector<int> ans = dfsOfGraph(adj);
    for (auto it : ans)
        cout << it << " ";

    return 0;
}