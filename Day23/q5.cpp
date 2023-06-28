#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, int parent, vector<int> adj[], int n, int m, vector<int> &vis)
{
    vis[node] = 1;

    for (auto adjacentNode : adj[node])
    {
        if (!vis[adjacentNode])
        {
            if (dfs(adjacentNode, node, adj, n, m, vis) == true)
                return true;
        }

        else if (adjacentNode != parent)
        {
            return true;
        }
    }
    return false;
}
string cycleDetection(vector<vector<int>> &edges, int n, int m)
{
    // Write your code here.
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++)
    {

        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> vis(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            if (dfs(i, -1, adj, n, m, vis) == true)
                return "Yes";
        }
    }

    return "No";
}
