#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
//////////memoization
int f(int ind1,int ind2, string s1, string s2, vector<vector<int>> &dp){
    if(ind1<0 or ind2<0) return 0;
    if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
    if(s1[ind1]== s2[ind2])
    return dp[ind1][ind2]= 1+ f(ind1-1, ind2-1, s1,s2,dp);

    else
    return dp[ind1][ind2]=0+ max(f(ind1-1, ind2,s1,s2,dp), f(ind1, ind2-1, s1,s2,dp));
}
    int longestCommonSubsequence(string text1, string text2) {
        int n= text1.size();
        int m= text2.size();
        vector<vector<int>> dp(n, vector<int>(m,-1));
        return f(n-1,m-1,text1,text2,dp);
    }
};








//tabulation
class Solution {
public:


    int longestCommonSubsequence(string s1, string s2) {
        int n= s1.size();
        int m= s2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1,-1));
//      HERE WE HAVE DONE SHIFTING OF INDEX TO THE RIGHT SO WE CAN USE TABULATION. BUT WE HAVE TO KEEP IN MIND THAT WHEN WE WILL DO SHIFTING WE WILL INC DP SIZE BY PLUS1. IT WILL REFLECT ITS EFFECT ON WHEN WE CONSIDER STRING'S INDEX AND AT THE END WHILE RETURNING THE ANSWER
        for(int i=0; i<=m; i++)
        dp[0][i]=0;

        for(int i=0; i<=n; i++)
        dp[i][0]=0;

        for(int ind1=1; ind1<=n ; ind1++){
            for(int ind2=1; ind2<=m; ind2++){
                if(s1[ind1-1]== s2[ind2-1])
                 dp[ind1][ind2]= 1+ dp[ind1-1][ind2-1];

                else
                 dp[ind1][ind2]=0+ max(dp[ind1-1][ind2], dp[ind1][ind2-1]);
            }
        }
        return dp[n][m];
    }
};