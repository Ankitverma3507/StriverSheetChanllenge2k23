#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    TreeNode* f(int low, int high, vector<int>&nums){
        if(low>high) return NULL;

        int mid= (low+high)>>1;
        TreeNode* root= new TreeNode(nums[mid]);
        root->left= f(low, mid-1,nums);
        root->right= f(mid+1,high,nums);

        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return f(0, nums.size()-1, nums);
    }
};