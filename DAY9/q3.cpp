
#include <bits/stdc++.h>

using namespace std;
///////////////////////////////recursion only
class Solution
{
public:
    void f(int ind, vector<int> &arr, int target, vector<vector<int>> &ans,
           vector<int> vect)
    {
        int n = arr.size();
        if (ind == n)
        {
            if (target == 0)
                ans.push_back(vect);
            return;
        }

        if (arr[ind] <= target)
        {
            vect.push_back(arr[ind]);
            f(ind, arr, target - arr[ind], ans, vect);
            vect.pop_back();
        }

        f(ind + 1, arr, target, ans, vect);
    }
    vector<vector<int>> combinationSum(vector<int> &arr, int target)
    {
        // int sum=0;
        vector<vector<int>> ans;
        vector<int> vect;
        f(0, arr, target, ans, vect);

        return ans;
    }
};