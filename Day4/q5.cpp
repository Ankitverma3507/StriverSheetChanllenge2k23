#include <bits/stdc++.h> 
using namespace std;
/////////////////////////////brute force
int subarraysXor(vector<int> &arr, int x)
{
    //    Write your code here.
    int n= arr.size();
    int cnt=0;
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            int xorr=0;
            for(int k=i; k<=j; k++){
                xorr= xorr ^ arr[k];
            }

            if(xorr==x)
            cnt++;
        }

    }
    return cnt;
}





#include <bits/stdc++.h> 
using namespace std;
/////////////////////////////optimal using hashmap
int solve(vector<int> &arr, int tar) {
    int n= arr.size();
    int cnt=0;
    map<int,int> mpp;
    mpp[0]=1;
    int xorr=0;
    for(int i=0; i<n; i++){
        xorr= xorr^ arr[i];
        int x= xorr ^ tar;
        
        cnt += mpp[x];
        
        mpp[xorr]++;
    }
    return cnt;
}
