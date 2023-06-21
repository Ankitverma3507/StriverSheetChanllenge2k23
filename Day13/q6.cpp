#include <bits/stdc++.h>
using namespace std;
////////////////////////////////////in this quetio we only want to tell the next greater element on the right instead of cylinderical arr
class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        stack<int> st;
        unordered_map<int, int> mp;
        int n = nums2.size();
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() and st.top() < nums2[i])
            {
                st.pop();
            }

            int res = st.empty() ? -1 : st.top();
            mp.insert({nums2[i], res});
            st.push(nums2[i]);
        }

        vector<int> ans;
        for (auto it : nums1)
        {
            ans.push_back(mp[it]);
        }
        return ans;
    }
};

#include <bits/stdc++.h>
using namespace std;
////////////////////////////////////////////for cylinderical one
class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> nge(n, -1);
        stack<int> st;
        for (int i = 2 * n - 1; i >= 0; i--)
        {
            while (!st.empty() && st.top() <= nums[i % n])
            {
                st.pop();
            }

            if (i < n)
            {
                if (!st.empty())
                    nge[i] = st.top();
            }
            st.push(nums[i % n]);
        }
        return nge;
    }
};
int main()
{
    Solution obj;
    vector<int> v{5, 7, 1, 2, 6, 0};
    vector<int> res = obj.nextGreaterElements(v);
    cout << "The next greater elements are" << endl;
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
}