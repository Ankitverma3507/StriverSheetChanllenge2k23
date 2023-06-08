#include <bits/stdc++.h> 
using namespace std;
/////////////////////////////better approach but give tle
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi= -1e9;
        
        for(int i=0; i<nums.size(); i++){
            int sum=0;
            for(int j=i; j<nums.size(); j++){
                sum += nums[j];
                maxi= max(maxi,sum);
            }
        }
        return maxi;
    }
};









///////////////////////kadane's algo
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi= -1e9;
        int sum=0;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            maxi= max(maxi,sum);
           
            if(sum<0){
                sum=0;
                
            }

        }
        
        int maxima= -1e9;
        if(maxi<0)
        {
            for(int i=0; i<nums.size(); i++)
            {maxima= max(maxima,nums[i]);}
            maxi= maxima;
        }
        return maxi;
    }
};









// if we want to print the subarr
#include <bits/stdc++.h>
using namespace std;

long long maxSubarraySum(int arr[], int n) {
    long long maxi = LONG_MIN; // maximum sum
    long long sum = 0;

    int start = 0;
    int ansStart = -1, ansEnd = -1;
    for (int i = 0; i < n; i++) {

        if (sum == 0) start = i; // starting index

        sum += arr[i];

        if (sum > maxi) {
            maxi = sum;

            ansStart = start;
            ansEnd = i;
        }

        // If sum < 0: discard the sum calculated
        if (sum < 0) {
            sum = 0;
        }
    }

    //printing the subarray:
    cout << "The subarray is: [";
    for (int i = ansStart; i <= ansEnd; i++) {
        cout << arr[i] << " ";
    }
    cout << "]n";

    // To consider the sum of the empty subarray
    // uncomment the following check:

    //if (maxi < 0) maxi = 0;

    return maxi;
}

int main()
{
    int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    long long maxSum = maxSubarraySum(arr, n);
    cout << "The maximum subarray sum is: " << maxSum << endl;
    return 0;
}