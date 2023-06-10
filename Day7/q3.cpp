#include <bits/stdc++.h>
using namespace std;
////////////////////////////////////////////////////-MOST OPTIMAL approach

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n= nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>>ans;
        for(int i=0; i<n-2; i++){
            if(i==0 or (i>0 and nums[i] != nums[i-1]))
            {int left= i+1;
            int right= n-1;
            int sum= 0 - nums[i];
            while(left< right){
                if(nums[left] + nums[right]==sum){
                    vector<int> vect;
                    vect.push_back(nums[i]);
                    vect.push_back(nums[left]);
                    vect.push_back(nums[right]);
                    ans.push_back(vect);

                    while(left<right and nums[left] == nums[left+1])
                    left++;

                    while(left< right and nums[right] == nums[right-1])
                    right--;

                    left++;
                    right--;

                }

                else if(nums[left] + nums[right]< sum){
                    left++;
                }

                else{
                    right--;
                }
            }}
        }

        return ans;
    }
};