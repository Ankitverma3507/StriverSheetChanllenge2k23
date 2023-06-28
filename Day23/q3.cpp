#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    
    void bfs(queue<int>&q, vector<int> adj[], vector<int>&ans, vector<int>&vis){
        while(!q.empty()){
            int node= q.front();
            q.pop();
            ans.push_back(node);
            
            for(auto it: adj[node]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push(it);
                }
            }
            
        }
    }
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        queue<int>q;
        vector<int> vis(V,0);
        vector<int>ans;
        q.push(0);
        vis[0]=1;
        bfs(q,adj,ans,vis);
        return ans;
    }
};

