
/////////////////////////better approach using hashing
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n= nums.size();
        map<int,int> mpp;

        for(int i=0; i<n; i++){
            mpp[nums[i]]++;
        }

        for(auto it: mpp){
            if(it.second> n/2)
            return it.first;
        }
        return 0;
    }
};








/////////////////////////Moores voting algorithm
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele;
        int cnt=0;
        int n= nums.size();
        for(int i=0; i<n; i++){

            if(cnt==0){
                ele= nums[i];
                cnt=1;
            }
            else if(nums[i]== ele )
            cnt++;

            else
            cnt--;

        }

        int cntcheck=0;
        for(int i=0; i<n; i++){
            if(nums[i]==ele)
            cntcheck++;
        }

        if(cntcheck > n/2) 
        return ele;
        return 0;
    }

};