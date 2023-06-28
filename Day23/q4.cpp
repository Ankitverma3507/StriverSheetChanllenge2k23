#include <bits/stdc++.h>
using namespace std;
bool solve(int node, vector<int> adj[], int n, int m, vector<int> &vis)
{
    vis[node] = 1;
    queue<pair<int, int>> q;
    q.push({node, -1});

    while (!q.empty())
    {
        int front = q.front().first;
        int parentnode = q.front().second;
        q.pop();

        for (auto adjacentNode : adj[front])
        {
            if (!vis[adjacentNode])
            {
                vis[adjacentNode] = 1;
                q.push({adjacentNode, front});
            }

            else if (adjacentNode != parentnode)
            {
                return true;
            }
        }
    }
    return false;
}
string cycleDetection(vector<vector<int>> &edges, int n, int m)
{
    // Write your code here.
    vector<int> adj[n + 1];
    //this code is to convert given edges into adj list. here given 2d vector is not adj matrix it is only the edges given. Like this [[6 4][1 6][2 3][3 4][2 4][3 2] [2 1]]
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
            if (solve(i, adj, n, m, vis) == true)
                return "Yes";
        }
    }

    return "No";
}
