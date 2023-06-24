#include <bits/stdc++.h>
using namespace std;
///////////////////////////////// app
//TC will be O(logN)   SC will O(1);
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        map<int,int> mp;

        for(int i=0; i<s.size(); i++){
            mp[s[i]]++;
            mp[t[i]]--;
        }

        for(auto it: mp){
            if(it.second !=0)
            return false;
        }
        return true;
    }
};