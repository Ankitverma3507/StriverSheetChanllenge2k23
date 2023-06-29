#include <bits/stdc++.h>
using namespace std;
//normal recursion
class Solution{
public:
    
    int f(int i, int j, int arr[], int n){
        
        if(i==j) return 0;
        int mini=1e9;
        for(int k= i ; k<=j-1; k++){
            int steps= arr[i-1]* arr[k]* arr[j] + f(i,k,arr,n)+ f(k+1,j,arr,n);
            mini= min(mini, steps);
        }
        
        return mini;
    }
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        int i=1; int j= N-1;
        return f(i,j,arr,N);
    }
};



#include <bits/stdc++.h>
using namespace std;
//memoization
class Solution{
public:
    
    int f(int i, int j, int arr[], int n, vector<vector<int>>&dp){
        
        if(i==j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int mini=1e9;
        for(int k= i ; k<=j-1; k++){
            int steps= arr[i-1]* arr[k]* arr[j] + f(i,k,arr,n,dp)+ f(k+1,j,arr,n,dp);
            mini= min(mini, steps);
        }
        
        return dp[i][j]=mini;
    }
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        vector<vector<int>>dp(N,vector<int>(N,-1));
        int i=1; int j= N-1;
        return f(i,j,arr,N,dp);
    }
};



