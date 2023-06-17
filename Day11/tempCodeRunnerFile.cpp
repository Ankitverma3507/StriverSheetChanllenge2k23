#include <bits/stdc++.h>
// using namespace std;
// bool isValid(vector<int>&arr, int cows, int dist){
//     int cowind= arr[0];
//     int cowcnt= 1;

//     for(int i=1; i<arr.size(); i++){
//         if(arr[i]- cowind >= dist){
//             cowind= arr[i];
//             cowcnt++;
//         }

//     }

//         if(cowcnt>= cows) return true;
//     return false;
// }
// int ans(vector<int> &arr, int cows){
//     sort(arr.begin() , arr.end());
//     int n= arr.size();
//     int low=1; 
//     int high= arr[n-1]- arr[0];

//     while(low<=high){
//         int mid= (low+high)>>1;
//         if(isValid(arr,cows,mid)){
//             low= mid+1;
//         }

//         else{
//             high= mid-1;
//         }
//     }
//     return high;
// }


// int main(){
//     vector<int> arr= {1,2,8,4,9};
//     int cows=3;

//     return ans(arr,3);
// }



