#include <bits/stdc++.h>
using namespace std;
///////////////////////////////brute force approach
class Solution
{
public:
    void GetMax(vector<int> nums, int l, int r, vector<int> &arr)
    {
        int i;
        int maxi = INT_MIN;
        for (i = l; i <= r; i++)
        {
            maxi = max(maxi, nums[i]);
        }
        arr.push_back(maxi);
    }
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        int left = 0, right = 0;

        vector<int> arr;
        while (right < k - 1)
        {
            right++;
        }
        while (right < nums.size())
        {
            GetMax(nums, left, right, arr);
            left++;
            right++;
        }
        return arr;
    }
};










#include <bits/stdc++.h>
using namespace std;
//////////////////////////////////////////optimised approach
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        vector<int> ans;
        int n= nums.size();
        for(int i=0; i<n; i++){
            if(!dq.empty() and dq.front()== i-k)// as when we reach no of element greater than k we have to pop front so that we can only store k element in our deque ds. so we will pop front.
            dq.pop_front();

            while(!dq.empty() and nums[dq.back()] < nums[i]){
                dq.pop_back();
            }

            dq.push_back(i);
            if(i>=k-1) ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};