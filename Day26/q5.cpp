#include <bits/stdc++.h>
using namespace std;
// memoization -    IT WILL GIVE TLE
class Solution
{
public:
    int solve(int e, int f, vector<vector<int>> &dp)
    {
        if (f == 0 or f == 1)
            return f;
        if (e == 1)
            return f;
        if (dp[e][f] != -1)
            return dp[e][f];
        int mini = INT_MAX;
        for (int k = 1; k <= f; k++)
        {
            int temp = 1 + max(solve(e - 1, k - 1, dp), solve(e, f - k, dp)); // THIS MAX IS BEACUSE WE WANT WORST CASE
            mini = min(mini, temp);
        }

        return dp[e][f] = mini;
    }

    int superEggDrop(int e, int f)
    {
        vector<vector<int>> dp(e + 1, vector<int>(f + 1, -1));
        return solve(e, f, dp);
    }
};

// tabulation
class Solution
{
public:
    int superEggDrop(int e, int f)
    {
        if (f == 0 or f == 1)
            return f;
        if (e == 1)
            return f;

        vector<vector<int>> dp(e + 1, vector<int>(f + 1, 0));
        for (int i = 0; i <= e; i++)
            dp[i][0] = 0, dp[i][1] = 1; // Filling from base case as if N==0 ans=0 , N==1 ans=1
        for (int i = 0; i <= f; i++)
            dp[0][i] = 0, dp[1][i] = i; // Filling from base case as if K==0 ans=0 , K==1 ans=N, number of current floor (i)

        for (int i = 2; i < e + 1; i++)
        {
            for (int j = 2; j < f + 1; j++)
            {
                int l = 1, h = j, temp = 0, ans = 100000;
                while (l <= h)
                {
                    int mid = (l + h) / 2;
                    int left = dp[i - 1][mid - 1]; // egg broken check for down floors of mid
                    int right = dp[i][j - mid];    // not broken check for up floors of mid
                    temp = 1 + max(left, right);   // store max of both
                    if (left < right)
                    {                // since right is more than left and we need more in worst case
                        l = mid + 1; // so l=mid+1 to gain more temp for worst case : upward
                    }
                    else // left > right so we will go downward
                    {
                        h = mid - 1;
                    }
                    ans = min(ans, temp); // store minimum attempts
                }
                dp[i][j] = ans;
            }
        }
        return dp[e][f];
    }
};

// OPTIMISED memoization -    IT WILL NOT GIVE TLE AS WE HAVE USED BINARY SEARCH

class Solution
{
public:
    int solve(int e, int f, vector<vector<int>> &dp)
    {
        if (f == 0 or f == 1)
            return f;
        if (e == 1)
            return f;
        if (dp[e][f] != -1)
            return dp[e][f];
        int mini = INT_MAX;
        int l = 1;
        int r = f;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            int broke = solve(e - 1, mid - 1, dp);
            int notbroke = solve(e, f - mid, dp);

            int temp = 1 + max(broke, notbroke);
            if (broke < notbroke) // IF NOTBROKE IS HIGHER SO WE WILL CHECK IN NOT BROKE ARE BEACUSE WE WANT HIHGER VALUES TO MAKE WORST CASE
                l = mid + 1;

            else
                r = mid - 1;

            mini = min(mini, temp);
        }

        return dp[e][f] = mini;
    }

    int superEggDrop(int e, int f)
    {
        vector<vector<int>> dp(e + 1, vector<int>(f + 1, -1));
        return solve(e, f, dp);
    }
};
