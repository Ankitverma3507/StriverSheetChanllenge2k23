#include <bits/stdc++.h> 
using namespace std;
/////////////////////////////Optimal approach
class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        int maxi;
        unordered_map<int, int> mpp;
            int sum=0;
        for(int i=0; i<n; i++){
                sum+= A[i];
            if(sum==0) maxi= i+1;
              
              else{  
                
                if (mpp.find(sum) != mpp.end()){
                    int len= i- mpp[sum];
                    maxi= max(maxi,len);
                }
                    
                else{
                    mpp[sum]= i;
                    
                }
                
              }
        }
        return maxi;
    }
};