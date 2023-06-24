#include <bits/stdc++.h>
using namespace std;
/////////////////////////////////optimised app
class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        
    string s ="";
    int count = 0;
    
    //add the string to be matched till the bigger string size and increase count
    while(s.size() < b.size()){
        s += a;
        count++;
    }
    
    //if string got found then return count
    if(s.find(b) != -1){
        return count;
    }
    
    //if string does not found then add again 
    //maybe in next replication it will be present
    s += a;
    count++;
    
    //if string got found then return count
    if(s.find(b) != -1){
        return count;
    }
    
    //string cant be found no matter how many replications
    return -1; 
    }
};



//robin karp method is left