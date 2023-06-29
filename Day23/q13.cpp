#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

    bool dfs(int node,int currcolor,vector<vector<int>>& graph,vector<int>&color ){
        
        color[node]=currcolor;

            for(auto it: graph[node]){
                if(color[it]==-1){
                    if(dfs(it, !currcolor, graph,color)==false)
                    return false;
                }

                else if(color[it]== currcolor){
                    return false;
                }
            }
        return true;
        }

 
 
    bool isBipartite(vector<vector<int>>& graph) {
        int n= graph.size();
        int m= graph[0].size();
        vector<int> color(n,-1);

        for(int i=0;i<n; i++){
            if(color[i]==-1){
                if(dfs(i,0,graph,color)==false)
                return false;
            }
        }
        return true;
    }
};