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

class Solution
{
public:
    int widthOfBinaryTree(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int width = 0;
        queue<pair<TreeNode *, int>> q;
        q.push({root, 0});
        while (!q.empty())
        {
            int size = q.size();
            int mini = q.front().second;
            int first, last;
            for (int i = 0; i < size; i++)
            {
                long long crrID = q.front().second - mini;
                TreeNode *node = q.front().first;
                q.pop();

                if (i == 0)
                    first = crrID;
                if (i == size - 1)
                    last = crrID;

                if (node->left)
                {
                    q.push({node->left, crrID * 2 + 1});
                }

                if (node->right)
                {
                    q.push({node->right, crrID * 2 + 2});
                }
            }
            width = max(width, last - first + 1);
        }
        return width;
    }
};