#include <bits/stdc++.h>
using namespace std;
//memoization
class Solution {
public:

    bool f(int ind, int tar, vector<int> &nums, vector<vector<int>>&dp){
        if(tar==0) return true;
        if(ind==0){
        if(nums[0]==tar) return true;
        else return false;
        }

        if(dp[ind][tar] !=-1) return dp[ind][tar];

        bool nottake= f(ind-1,tar,nums,dp);
        bool take=false;
        if(tar>= nums[ind])
         take= f(ind-1,tar- nums[ind], nums,dp);

        return dp[ind][tar]= take or nottake;

    }
    bool canPartition(vector<int>& nums) {
        int  totsum=0;
        for(int i=0; i<nums.size(); i++)
        totsum+= nums[i];

        if(totsum %2 !=0) return false;
        int target= totsum/2;

        int n= nums.size();
        vector<vector<int>>dp(n, vector<int>(target+1,-1));

        return f(nums.size()-1,target,nums,dp);
    }
};