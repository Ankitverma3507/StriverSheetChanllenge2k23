
#include <bits/stdc++.h>
using namespace std;



class Solution {
  public:
  
  void dfs(int row, int col,vector<vector<int>>& grid,vector<vector<int>>& vis,vector<pair<int,int>>&vect,
  int row0, int col0){
      int n= grid.size();
      int m= grid[0].size();
      vis[row][col]=1;
      vect.push_back({row-row0, col-col0});
      
      int delrow[] = {-1, 0, 1, 0};
      int delcol[] = {0, -1, 0, 1};
      
      for(int i=0; i<4; i++){
          int nrow= row+ delrow[i];
          int ncol= col+ delcol[i];
          
          if(nrow>=0 and ncol>=0 and nrow<n and ncol<m and !vis[nrow][ncol] and grid[nrow][ncol]==1){
              dfs(nrow,ncol,grid,vis,vect,row0, col0);
          }
      }
  }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n= grid.size();
        int m= grid[0].size();
        set<vector<pair<int,int>>>st;
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] and grid[i][j]==1){
                    vector<pair<int,int>>vect;
                    dfs(i,j,grid,vis,vect, i,j);
                    st.insert(vect);
                }
            }
        }
        return st.size();
    }
};

