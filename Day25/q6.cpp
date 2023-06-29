#include <bits/stdc++.h>
using namespace std;
// memoization
class Solution
{

    int f(int ind, int prevind, int arr[], int n, vector<vector<int>> &dp)
    {
        if (ind == n)
            return 0;

        if (dp[ind][prevind + 1] != -1)
            return dp[ind][prevind + 1];

        int nottake = 0 + f(ind + 1, prevind, arr, n, dp);
        int take = INT_MIN;
        if (prevind == -1 or arr[ind] > arr[prevind])
            take = arr[ind] + f(ind + 1, ind, arr, n, dp);

        return dp[ind][prevind + 1] = max(take, nottake);
    }

public:
    int maxSumIS(int arr[], int n)
    {
        // Your code goes here
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return f(0, -1, arr, n, dp);
    }
};

#include <bits/stdc++.h>
using namespace std;
// tabulation
class Solution
{

public:
    int maxSumIS(int arr[], int n)
    {
        // Your code goes here
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int prevind = ind - 1; prevind >= -1; prevind--)
            {

                int nottake = 0 + dp[ind + 1][prevind + 1];
                int take = INT_MIN;
                if (prevind == -1 or arr[ind] > arr[prevind])
                    take = arr[ind] + dp[ind + 1][ind + 1];

                dp[ind][prevind + 1] = max(take, nottake);
            }
        }

        return dp[0][-1 + 1];
    }
};
