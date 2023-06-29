//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    
    int knapsackUtil(int wt[], int val[], int ind, int W, vector<vector<int>>& dp){

    if(ind == 0){
        if(wt[0] <=W) return val[0];
        else return 0;
    }
    
    if(dp[ind][W]!=-1)
        return dp[ind][W];
        
    int notTaken = 0 + knapsackUtil(wt,val,ind-1,W,dp);
    
    int taken = INT_MIN;
    if(wt[ind] <= W)
        taken = val[ind] + knapsackUtil(wt,val,ind-1,W-wt[ind],dp);
        
    return dp[ind][W] = max(notTaken,taken);
}
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
        vector<vector<int>> dp(n,vector<int>(W+1,-1));
        return knapsackUtil(wt, val, n-1, W, dp);
    }
};





#include <bits/stdc++.h>
using namespace std;
///////////////////////////////------------------->>>>>super super space otpimisation

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    // Write your code here

    vector<int> prev(maxWeight + 1, 0);
    for (int i = weight[0]; i <= maxWeight; i++)
        prev[i] = value[0];

    for (int ind = 1; ind < n; ind++)
    {
        for (int wt = maxWeight; wt >= 0; wt--)
        {
            int take = -1e9;
            int nontake = 0 + prev[wt];
            if (weight[ind] <= wt)
                take = value[ind] + prev[wt - weight[ind]];

            prev[wt] = max(take, nontake);
        }
    }
    return prev[maxWeight];
}