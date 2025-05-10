#include <bits/stdc++.h>
using namespace std;

vector<int> topologicalSort(vector<vector<int>> &adj)
{
    int n = adj.size();
    vector<int> indegree(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (auto j : adj[i])
        {
            indegree[j]++;
        }
    }

    queue<int> que;
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
            que.push(i);
    }
    vector<int> res;

    while (!que.empty())
    {
        int node = que.front();
        que.pop();
        res.push_back(node);
        for (auto i : adj[node])
        {
            indegree[i]--;
            if (indegree[i] == 0)
                que.push(i);
        }
    }
    return res;
}

int main()
{
    vector<vector<int>> adj = {{}, {3}, {3}, {}, {0, 1}, {0, 2}};
    vector<int> res = topologicalSort(adj);
    for (auto i : res)
    {
        cout << i << " ";
    }
    return 0;
}