#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

void dfs(int row, int col,vector<vector<int>>& image, int delrow[], int delcol[],int curcolor, int newcolor, vector<vector<int>>& ans){
    int n= image.size();
    int m= image[0].size();
    ans[row][col]= newcolor;

    for(int i=0; i<4; i++){
        int nrow= row+ delrow[i];
        int ncol= col+ delcol[i];

        if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and image[nrow][ncol]==curcolor and 
        ans[nrow][ncol]!= newcolor)
        {
            dfs(nrow,ncol,image,delrow,delcol,curcolor,newcolor,ans);
        }
    }
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> &ans= image;
        int currcolor= image[sr][sc];
        int delrow[]= {-1,0,1,0};
        int delcol[]= {0,1,0,-1};

        dfs(sr,sc,image,delrow,delcol,currcolor, color, ans);
        return ans;
    }
};