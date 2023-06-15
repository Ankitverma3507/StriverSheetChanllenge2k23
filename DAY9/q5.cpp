#include <bits/stdc++.h>

using namespace std;
///////////////////////////////optimal force

class Solution
{
public:
    void f(int ind, string s, vector<vector<string>> &ans, vector<string> &path)
    {
        if (ind == s.length())
        {
            ans.push_back(path);
            return;
        }

        for (int i = ind; i < s.length(); i++)
        {
            if (isPalindrome(s, ind, i))
            {
                path.push_back(s.substr(ind, i - ind + 1));
                f(i + 1, s, ans, path);
                path.pop_back();
            }
        }
    }

    bool isPalindrome(string s, int st, int end)
    {
        while (st <= end)
        {
            if (s[st] != s[end])
                return false;
            st++;
            end--;
        }
        return true;
    }
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> ans;
        vector<string> path;
        f(0, s, ans, path);
        return ans;
    }
};