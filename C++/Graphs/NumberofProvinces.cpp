#include <bits/stdc++.h>
using namespace std;

void bfs(int node, vector<vector<int>> &adj, vector<int> &visited)
{
    queue<int> q;
    q.push(node);
    visited[node] = 1;

    while (!q.empty())
    {
        node = q.front();
        q.pop();
        for (int i = 0; i < adj.size(); i++)
        {
            if (adj[node][i] && visited[i] == 0)
            {
                visited[i] = 1;
                q.push(i);
            }
        }
    }
}
int findCircleNum(vector<vector<int>> &isConnected)
{
    int n = isConnected.size();
    int ans = 0;
    vector<int> vis(n);
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            ans++;
            bfs(i, isConnected, vis); // or dfs can also be used
        }
    }
    return ans;
}
int main()
{
    vector<vector<int>> adj = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1},
    };
    // vector<vector<int>> adj = {
    //     {1, 1, 0},
    //     {1, 1, 0},
    //     {0, 0, 1},
    // };
    int ans = findCircleNum(adj);
    cout << "Answer: " << ans;
    return 0;
}