#include <bits/stdc++.h>
using namespace std;
class KthLargest {
    priority_queue<int , vector<int>, greater<int>>pq;
    int k1;
public:
    KthLargest(int k, vector<int>& nums) {
        for(int i=0; i<nums.size(); i++){
            pq.push(nums[i]);
        }
        k1=k;
    }
    
    int add(int val) {
        pq.push(val);

        while(pq.size()>k1){
            pq.pop();
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */