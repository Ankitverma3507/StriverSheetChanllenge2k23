#include <bits/stdc++.h>
using namespace std;
////////////////////////////////////////////////////--optimal approach
class Solution {
public:

    void f(int ind, string s, unordered_set<string> st, vector<string> &ans, string curr){
        if(ind== s.length()){
            curr.pop_back();
            ans.push_back(curr);
        }
        for(int i= ind; i< s.length(); i++){
            string sub= s.substr(ind, i-ind+1);
            if(st.find(sub) != st.end()){
                f(i+1, s,st,ans,curr+sub +" ");
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        for(auto i: wordDict)
        st.insert(i);

        vector<string> ans;
        f(0, s, st,ans,"");
        return ans;
    }
};