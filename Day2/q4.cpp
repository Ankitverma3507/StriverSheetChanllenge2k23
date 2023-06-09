#include <bits/stdc++.h>
using namespace std;
///////////////////////////////////////better 
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n= nums.size();
        vector<int> freq(n+1,0);
        for(int i=0;i<n; i++){
            if(freq[nums[i]]==0)
            freq[nums[i]]++;

            else return nums[i];
        }
        return 0;
    }
};








#include <bits/stdc++.h>
using namespace std;
///////////////////////////////////////Optimal approach in which we use linked list cycle detection technique 
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow= nums[0];
        int fast= nums[0];

        do{
            slow= nums[slow];
            fast= nums[nums[fast]];
        } while (slow!= fast);

        fast= nums[0];
        while(slow!= fast){
            slow= nums[slow];
            fast= nums[fast];
        }

        return slow;
    }
};