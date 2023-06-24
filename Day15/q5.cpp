#include <bits/stdc++.h>
using namespace std;
/////////////////////////////////brute force app
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n= strs.size();
        string  ans="";
        for(int i=0; i<strs[0].size(); i++){
            char ch= strs[0][i];

            bool match= true;
            for(int j=1; j< strs.size(); j++){
                if(strs[j].size()<i or ch!= strs[j][i]){
                    match=false;
                    break;
                }
            }

            if(match==false) break;

            ans += ch;
        }
        return ans;
    }
};








#include <bits/stdc++.h>
using namespace std;
/////////////////////////////////optimised app
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        string st = strs[0], en=strs[strs.size()-1],ans="";
        for (int i=0;i<st.size();i++){
            if (st[i]==en[i]) ans+=st[i];
            else break;
        }
        return ans;
    }
};