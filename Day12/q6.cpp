#include <bits/stdc++.h> 
using namespace std;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        if(nums.size()==1 and k==1) {
            ans.push_back(nums[0]);
            return ans;
        }
        unordered_map<int,int>mp;
        for(auto i: nums){
            mp[i]++;
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(auto it: mp){

            pq.push({it.second, it.first});

            if(pq.size()>k){
                pq.pop();
            }

        }

        while(!pq.empty()){
            int temp= pq.top().second;
            ans.push_back(temp);
            pq.pop();

        }

        return ans;
    }
};