#include <bits/stdc++.h>
using namespace std;
////////////////////////////////////////////////////--brute approach
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int ans =0;
        for (int i=0; i<nums.size(); i++){
            ans= ans ^ nums[i];
        }
        return ans;
    }
};



#include <bits/stdc++.h>
using namespace std;
////////////////////////////////////////////////////--optimal approach
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        

        int low=0; int high= nums.size()-2;
        while(low<= high){
            int mid= low+high>>1;
            if(nums[mid] == nums[mid^1])
            low= mid+1;

            else
            high= mid-1;
        }
        return nums[low];
    

        }
};