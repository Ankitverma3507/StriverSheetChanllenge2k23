#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    
    void dfs(int start,vector<int> adj[], vector<int>&vis, vector<int>&ans){
        vis[start]=1;
        ans.push_back(start);
        for(auto it: adj[start]){
            if(!vis[it])
            dfs(it,adj,vis,ans);
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> ans;
        vector<int>vis(V,0);
        
        
            dfs(0,adj,vis, ans);
        
        return ans;
    }
};

