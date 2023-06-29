#include <bits/stdc++.h>
using namespace std;
//memoization

class Solution {
public:

    int f(int ind,vector<int>& coins, int amount,vector<vector<int>>&dp ){
        if(ind==0){
            if(amount % coins[0]==0)
            return amount/coins[0];
            else
            return 1e9;
        }
        if(dp[ind][amount] !=-1) return dp[ind][amount] ;

        int nottake= 0+ f(ind-1,coins,amount,dp);
        int take= 1e9;
        if(coins[ind]<= amount)
        take = 1+ f(ind, coins,amount- coins[ind],dp);

        return dp[ind][amount] = min(take,nottake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n= coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1,-1));
        int ans= f(n-1, coins, amount,dp);
        if(ans>= 1e9) return -1;
        else return ans;
    }
};





#include <bits/stdc++.h>

using namespace std;
///////////////////////////////------------------->>>>>tabulation

int minimumElements(vector<int> &num, int x)
{
    // Write your code here.
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(x + 1, 0));
    for (int t = 0; t <= x; t++)
    {
        if (t % num[0] == 0)
            dp[0][t] = t / num[0];
        else
            dp[0][t] = 1e9;
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 0; target <= x; target++)
        {
            int nontake = 0 + dp[ind - 1][target];
            int take = 1e9;
            if (num[ind] <= target)
                take = 1 + dp[ind][target - num[ind]]; // here we are at the same
            // ind coz we have infinite supply of on coin

            dp[ind][target] = min(take, nontake);
        }
    }

    int ans = dp[n - 1][x];
    if (ans >= 1e9)
        return -1;
    return ans;
}

#include <bits/stdc++.h>

using namespace std;
///////////////////////////////------------------->>>>>space optimization

int minimumElements(vector<int> &num, int x)
{
    // Write your code here.
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(x + 1, 0));
    vector<int> prev(x + 1, 0), curr(x + 1);
    for (int t = 0; t <= x; t++)
    {
        if (t % num[0] == 0)
            prev[t] = t / num[0];
        else
            prev[t] = 1e9;
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 0; target <= x; target++)
        {
            int nontake = 0 + prev[target];
            int take = 1e9;
            if (num[ind] <= target)
                take = 1 + curr[target - num[ind]]; // here we are at the same
            // ind coz we have infinite supply of on coin

            curr[target] = min(take, nontake);
        }
        prev = curr;
    }

    int ans = prev[x];
    if (ans >= 1e9)
        return -1;
    return ans;
}