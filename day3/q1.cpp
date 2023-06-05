/////////////////////////optimal approach using binary search
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int target) {
        if(arr.empty()) return false;
        int st=0; 
        int n= arr.size();
        int m= arr[0].size();
        int end= (m*n)-1;
        while(st<= end){
            int mid= (st+end)/2;
            if(arr[mid/m][mid%m]== target) return true;

            if(target > arr[mid/m][mid%m]){
                st= mid+1;
            }

            else
            {
                end= mid-1;
            }
        }
        return false;

    }
};