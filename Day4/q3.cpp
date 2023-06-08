#include <bits/stdc++.h>
using namespace std;/////////////////////////////brute force
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        sort(nums.begin(), nums.end());
        int ans=1;
        int prev= nums[0];
        int cnt=1;
        for(int i=1; i<nums.size(); i++){
            if(nums[i]== prev+1)
            cnt++;

            else if(nums[i] != prev)
            cnt=1;

            prev=nums[i];
            ans= max(ans,cnt);
        }
        return ans; 

    }
};







#include <bits/stdc++.h>
using namespace std;/////////////////////////////optimal apprach
class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        set<int> hashset;
    for(auto num: arr){
        hashset.insert(num);
    }

    int longeststreak=0;
    for( auto num:arr){
        if(!hashset.count(num-1))
        {
            int currnum = num;
            int currlen= 1;

            while(hashset.count(currnum+1)){
                currnum+=1;
                currlen +=1;
            }

            longeststreak= max(longeststreak,currlen);
        }
    }
    return longeststreak;

    }
};