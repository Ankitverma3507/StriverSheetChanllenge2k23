#include <bits/stdc++.h>
using namespace std;

vector<int> dNums(vector<int> &A, int k)
{
    vector<int> ans;
    int n = A.size();
    if (k > A.size())
        return ans;

    map<int, int> mpp;

    int i = 0;
    int j = 0;
    while (i != k)
    {
        mpp[A[i]]++;
        i++;
    }

    ans.push_back(mpp.size());

    for (int i = k; i < n; i++)
    {
        mpp[A[i]]++;
        mpp[A[j]]--;

        if (mpp[A[j]] == 0)
            mpp.erase(A[j]);

        j++;
        ans.push_back(mpp.size());
    }

    return ans;
}
