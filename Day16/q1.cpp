#include <bits/stdc++.h>
using namespace std;
///////////////////////////////// app
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size()> haystack.size()) return -1;
        // if(needle.size()== haystack.size()) return 0;
        int x= needle.size();
        int y= haystack.size();
        for(int i=0; i<=y-x; i++){ //as we are traveersing in haystack string so at the end our loop should ends at the size of needle dist peeche
        string s= haystack.substr(i, x);
        if(s==needle) return i;

        }
        return -1;
    }
};