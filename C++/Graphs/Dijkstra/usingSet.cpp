#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src)
{
    int n = adj.size();
    vector<int> dis(n, INT_MAX);
    set<pair<int, int>> s;

    dis[src] = 0;
    s.insert({0, src});

    while (!s.empty())
    {
        auto i = *s.begin();
        int d = i.first;
        int node = i.second;
        s.erase(s.begin());

        for (auto it : adj[node])
        {
            if (dis[it.first] > d + it.second)
            {
                if (dis[it.first] != INT_MAX)
                    s.erase({dis[it.first], it.first});

                dis[it.first] = d + it.second;
                s.insert({d + it.second, it.first});
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