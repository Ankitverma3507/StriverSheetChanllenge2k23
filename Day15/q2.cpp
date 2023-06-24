#include <bits/stdc++.h>
using namespace std;
//////////////////////////////////
class Solution {
public:
    string longestPalindrome(string s) {
     if(s.length()<=1) return s;
        int n= s.length();
        int maxlength=1;

        int st= 0; int end=0;

        //odd
        for(int i=0; i<n-1; i++){
            int l=i;
            int r=i;

            while(l>=0 and r<n ){
                if(s[l]==s[r]){
                    l--;
                    r++;
                }
                else break;
            }
            int len= r-l-1;
            if(len>maxlength){
                maxlength= len;
                st= l+1;
                end= r-1;
            }
        }

        //even
        for(int i=0; i<n-1; i++){
            int l=i;
            int r=i+1;

            while(l>=0 and r<n ){
                if(s[l]==s[r]){
                    l--;
                    r++;
                }
                else break;
            }
            int len= r-l-1;
            if(len>maxlength){
                maxlength= len;
                st= l+1;
                end= r-1;
            }
        }
        return s.substr(st,maxlength);
    }
};