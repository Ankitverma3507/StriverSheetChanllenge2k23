#include <bits/stdc++.h>
using namespace std;


class Disjoint
{

    vector<int> rank, parent, size;

public:
    Disjoint(int n) // no of nodes in graph
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findParent(int u)
    {
        if (u == parent[u])
            return u;

        return parent[u] = findParent(parent[u]); // memoization to save time in future and this will also done path compression
    }

    void unionbyRank(int u, int v)
    {
        int ulParentU = findParent(u);
        int ulParentV = findParent(v);

        if (ulParentU == ulParentV)
            return;

        if (rank[ulParentU] < rank[ulParentV])
        {
            parent[ulParentU] = ulParentV;
        }

        else if (rank[ulParentU] > rank[ulParentV])
        {
            parent[ulParentV] = ulParentU;
        }

        else
        {
            parent[ulParentV] = ulParentU;
            rank[ulParentU]++;
        }
    }

    void unionbySize(int u, int v)
    {
        int ulParentU = findParent(u);
        int ulParentV = findParent(v);

        if (ulParentU == ulParentV)
            return;

        if (size[ulParentU] < size[ulParentV])
        {
            parent[ulParentU] = ulParentV;
            size[ulParentV] += size[ulParentU];
        }

        else
        {
            parent[ulParentV] = ulParentU;
            size[ulParentU] += size[ulParentV];
        }
    }
};
class Solution
{
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<pair<int, pair<int, int>>> edges; // to save edges with their weights. in prev we used the min pq.
        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
            {
                int adjnode = it[0];
                int wt = it[1];
                int node = i;

                edges.push_back({wt, {node, adjnode}});
            }
        }

        sort(edges.begin(), edges.end());
        Disjoint ds(V);
        int mstsum = 0;
        for (auto it : edges)
        {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;

            if (ds.findParent(u) != ds.findParent(v))
            {
                mstsum += wt;
                ds.unionbyRank(u, v);
            }
        }

        return mstsum;
    }
};

