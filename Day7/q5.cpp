#include<bits/stdc++.h>

using namespace std;
////////////////////////////////////////////////////-brute approach

int removeDuplicates(int arr[], int n) {
  set < int > set;
  for (int i = 0; i < n; i++) {
    set.insert(arr[i]);
  }
  int k = set.size();
  int j = 0;
  for (int x: set) {
    arr[j++] = x;
  }
  return k;
}
int main() {
  int arr[] = {1,1,2,2,2,3,3};
  int n = sizeof(arr)/sizeof(arr[0]);
  int k = removeDuplicates(arr, n);
  cout << "The array after removing duplicate elements is " << endl;
  for (int i = 0; i < k; i++) {
    cout << arr[i] << " ";
  }
}






////////////////////////////////////////////////////-optimal approach

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0; 
        int n= nums.size();
        for(int j=1; j<n; j++){
            if(nums[i] != nums[j])
            {
                nums[i+1]= nums[j];
                i++;
            }
        }
        return i+1;
    }
};