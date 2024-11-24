#include <bits/stdc++.h>
using namespace std;

vector<int> bfsOfGraph(vector<vector<int>> &adj)
{
    vector<int> bfs;
    vector<int> visited(adj.size(), 0);
    queue<int> q;
    q.push(0);
    visited[0] = 1;

    while (!q.empty())
    {
        int node = q.front();
        bfs.push_back(node);
        q.pop();
        for (auto it : adj[node])
        {
            if (visited[it] == 0)
            {
                visited[it] = 1;
                q.push(it);
            }
        }
    }
    return bfs;
}

int main()
{
    vector<vector<int>> adj = {{2, 3, 1}, {0}, {0, 4}, {0}, {2}};
    vector<int> ans = bfsOfGraph(adj);
    for (auto it : ans)
        cout << it << " ";
    return 0;
}