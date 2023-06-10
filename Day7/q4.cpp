#include<bits/stdc++.h>
using namespace std;
////////////////////////////////////////////////////-Better approach
int trap(vector < int > & arr) {
  int n = arr.size();
  int prefix[n], suffix[n];
  prefix[0] = arr[0];
  for (int i = 1; i < n; i++) {
    prefix[i] = max(prefix[i - 1], arr[i]);
  }
  suffix[n - 1] = arr[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    suffix[i] = max(suffix[i + 1], arr[i]);
  }
  int waterTrapped = 0;
  for (int i = 0; i < n; i++) {
    waterTrapped += min(prefix[i], suffix[i]) - arr[i];
  }
  return waterTrapped;
}

int main() {
  vector < int > arr;
  arr = {0,1,0,2,1,0,1,3,2,1,2,1};
  cout << "The water that can be trapped is " << trap(arr) << endl;
}





#include<bits/stdc++.h>
using namespace std;
////////////////////////////////////////////////////-most optimal approach
class Solution {
public:
    int trap(vector<int>& height) {
        int n= height.size();
        int l= 0;
        int r= n-1; int leftmax=0 , rightmax=0;
        int ans=0;

        while(l<=r){
            if(height[l]<= height[r]){
                if(height[l]>= leftmax)
                leftmax= height[l];

                else
                ans += leftmax-height[l];

                l++;
            }

            else{
                if(height[r]>= rightmax)
                rightmax= height[r];

                else
                ans += rightmax-height[r];

                r--;
            }
        }

        return ans;
    }
};