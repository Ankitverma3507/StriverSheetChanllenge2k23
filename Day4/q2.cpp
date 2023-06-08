 namespace std;/////////////////////////////best apporoach#include <bits/stdc++.h>
using
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    // Write your code here
    int n= nums.size();
    set<vector<int>>st;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            set<long long> hashset;
            for(int k=j+1; k<n; k++){
                long long sum= nums[i] + nums[j];
                sum+=  nums[k];
                long long fourth= target- sum;

                if(hashset.find(fourth) != hashset.end()){
                    vector<int> temp= {nums[i], nums[j], nums[k], (int)fourth};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                    
                }
                
                hashset.insert(nums[k]);

            }
        }
    }
    vector<vector<int>>ans(st.begin(),st.end());
    return ans;


}






#include <bits/stdc++.h>
using namespace std;/////////////////////////////optimal apporoach 2 pointer approach
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    // Write your code here
        int n= nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i=0; i<n; i++){
            if(i>0 and nums[i]== nums[i-1]) continue;
            for(int j= i+1; j<n; j++){
                if(j != i+1 and nums[j]== nums[j-1]) continue;
                int lo= j+1; int hi= n-1;
                while(lo<hi){
                long long sum= nums[i];
                sum+= nums[j]; 
                sum+= nums[lo];
                sum+= nums[hi];
                    if( sum== target){
                        vector<int>temp= {nums[i], nums[j], nums[lo], nums[hi]};
                        ans.push_back(temp);

                        lo++; hi--;
                        while(lo<hi and nums[lo]== nums[lo-1])
                        lo++;

                        while(lo<hi and nums[hi]== nums[hi+1])
                        hi--;

                    }
                    
                    else if(sum< target) lo++;
                    else hi--;
                }
            }
        }
        return ans;
}