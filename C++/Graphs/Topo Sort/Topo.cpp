#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> &vis, vector<vector<int>> &adj, stack<int> &st)
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
            dfs(it, vis, adj, st);
    }
    st.push(node);
}
vector<int> topologicalSort(vector<vector<int>> &adj)
{

    int n = adj.size();
    vector<int> vis(n, 0);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
            dfs(i, vis, adj, st);
    }

    vector<int> res;
    for (int i = 0; i < n; i++)
    {
        res.push_back(st.top());
        st.pop();
    }
    return res;
}

int main()
{
    vector<vector<int>> adj = {{1, 2}, {2}, {3}, {3}};
    vector<int> res = topologicalSort(adj);
    for (auto i : res)
        cout << i << " ";
    return 0;
}