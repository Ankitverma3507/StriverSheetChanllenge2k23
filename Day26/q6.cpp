#include <bits/stdc++.h>
using namespace std;
// /memoization
class Solution {
public:

    bool  solve(int ind, string s,set<string> &st,vector<int>&dp ){
        if(ind==s.size()) return true;
        if(dp[ind] !=-1) return dp[ind];
        string temp;
        for(int i=ind; i<s.size(); i++){
            temp+= s[i];
            if(st.find(temp) != st.end()){
                if(solve(i+1, s, st,dp))
                return dp[i]= true;
            }
        }
        return dp[ind]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> st;
        vector<int>dp(s.size(),-1);
        for(auto it: wordDict) st.insert(it);
        return solve(0,s,st,dp);
    }
};