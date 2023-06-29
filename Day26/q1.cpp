#include <bits/stdc++.h>
using namespace std;
//recursion
class Solution {
public:

    int f(int row, int col,vector<vector<int>>& grid, int n, int m ){
        if(row==0 and col==0)
        return grid[row][col];
        if(row<0 or col<0)
        return 1e9;

        int left= grid[row][col]+ f(row,col-1,grid,n,m);
        int up= grid[row][col]+ f(row-1,col,grid,n,m);

        return min(left,up);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();

        return f(n-1,m-1,grid,n,m);
    }
};





class Solution {
public:
//memoization
    int f(int row, int col,vector<vector<int>>& grid, int n, int m,vector<vector<int>>&dp ){
        if(row==0 and col==0)
        return grid[row][col];
        if(row<0 or col<0)
        return 1e9;
        if(dp[row][col] !=-1) return dp[row][col];

        int left= grid[row][col]+ f(row,col-1,grid,n,m,dp);
        int up= grid[row][col]+ f(row-1,col,grid,n,m,dp);

        return dp[row][col]= min(left,up);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(n-1,m-1,grid,n,m,dp);
    }
};









//tabulation
class Solution {
public:

    
    int minPathSum(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));

        for(int row=0; row<n; row++){
            for(int col=0; col<m; col++){
                if(row==0 and col==0)
                dp[row][col]= grid[row][col];

                else{
                    int left= grid[row][col];
                    if(col >0)
                    left+= dp[row][col-1];
                    else
                    left+= 1e9;

                    int up= grid[row][col];
                    if(row>0)
                    up+= dp[row-1][col];
                    else
                    up+= 1e9;
                
                dp[row][col]= min(left,up);
                }
            }
        }

        return dp[n-1][m-1];
    }
};