#include <bits/stdc++.h> 
using namespace std;
///////////////////////////////////////-------->>>>>.memoization 
bool isPalindrome(int i, int j , string &s){
    while(i<j){
        if(s[i] != s[j]) return false;
        i++; j--;

    }
    return true;
}
int f(int i, string &str,int n,vector<int> &dp){
    if(i==n) return 0;
    if(dp[i] != -1) return dp[i];
    int mincost= 1e9;
    for(int j=i; j<n; j++ ){
        if(isPalindrome(i,j,str))
        {
           int cost = 1+ f(j+1,str,n,dp);
            mincost= min(mincost, cost);
        }
    }
    return dp[i]= mincost;
}
int palindromePartitioning(string str) {
    // Write your code here
    int n= str.size();
    vector<int> dp(n,-1);
    return f(0,str,n,dp)-1;
}







#include <bits/stdc++.h> 
using namespace std;
///////////////////////////////////////-------->>>>>.tabulaiton 
bool isPalindrome(int i, int j , string &s){
    while(i<j){
        if(s[i] != s[j]) return false;
        i++; j--;

    }
    return true;
}

int palindromePartitioning(string str) {
    // Write your code here
    int n= str.size();
    vector<int> dp(n+1,0);

    dp[n]=0;
    for(int i=n-1; i>=0; i--){
        int mincost= 1e9;
        for(int j=i; j<n; j++ ){
            if(isPalindrome(i,j,str))
            {
            int cost = 1+ dp[j+1];
                mincost= min(mincost, cost);
            }
        }
         dp[i]= mincost;
    }
    return dp[0]-1;
}



//  TLE MILEGA HAR BAR BECOZ WE ARE CHECKING IS PALINDROMW AGAIN AND AGAIN BY APPLYING WHILE LOOP. SO WE CAN MAKE ONE MORE FUCNTION WHICH WILL PRE CALUCULATE THE IS PALINDROME OR NOT FOR EVERY STRING. SO FOR THIS WE WILL MAKE ONE 2D DP TO PRE CALCULATE THE IS PALINDROME OR NOTE THING


class Solution {
public:

    bool pal(string &a, int i, int j){
        while(i<=j){
            if(a[i]!=a[j]) return false;
            i++, j--;
        }
        return true;
    }

    //  pre calculation of string to be palindrome for all i and j
    void preCalculate(vector<vector<int>> &ispal, string &s){
        ispal[0][0] = 1;
        for(int i = 1; i<s.size(); i++){
            if(pal(s, 0, i)){
                ispal[0][i] = 1;
                ispal[i][0] = 1;
            }
            ispal[i][i] = 1;
        }
        for(int i = s.size()-1; i>=0; i--){
            for(int j = 1; j<s.size(); j++){
                if(s[i]==s[j] && (j-i<2 || ispal[i+1][j-1])){
                    ispal[i][j] = 1;
                }
            }
        }
        return;
    }


    int minCut(string s) {
        vector<vector<int>> ispal(s.size()+1, vector<int>(s.size()+1, 0));
        preCalculate(ispal, s);
        vector<int> dp(s.size()+1, 0);

        // Tabulation
        for(int i = s.size()-1; i>=0; i--){
            int ans = INT_MAX;
            for(int k = i; k<s.size(); k++){
                if(ispal[i][k]){
                    int x = 1+dp[k+1];
                    ans = min(ans, x);
                }
            }
            dp[i] = ans;
        }
        return dp[0]-1;
    }
};