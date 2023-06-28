#include <bits/stdc++.h>
using namespace std;
bool dfs(int node, vector<int> adj[], int n, int m, vector<int> &vis, vector<int> &pathvis)
{
    vis[node] = 1;
    pathvis[node] = 1;

    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            if (dfs(it, adj, n, m, vis, pathvis) == true)
                return true;
        }

        else if (vis[it] == 1 and pathvis[it] == 1)
            return true;
    }

    pathvis[node] = 0;
    return false;
}

int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges)
{
    // Write your code here.
    vector<int> adj[n + 1];

    int m = edges.size();
    for (int i = 0; i < m; i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
    }

    vector<int> vis(n + 1, 0), pathvis(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            if (dfs(i, adj, n, m, vis, pathvis) == true)
                return 1;
        }
    }
    return 0;
}