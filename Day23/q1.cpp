#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution
{
public:
    Node *dfs(Node *currnode, unordered_map<Node *, Node *> &mpp)
    {
        vector<Node *> cloneNode;
        Node *clone = new Node(currnode->val);
        mpp[currnode] = clone;

        for (auto it : currnode->neighbors)
        {
            if (mpp.find(it) != mpp.end())
            {
                cloneNode.push_back(mpp[it]);
            }

            else
            {
                cloneNode.push_back(dfs(it, mpp));
            }
        }
        clone->neighbors = cloneNode;
        return clone;
    }
    Node *cloneGraph(Node *node)
    {

        if (node == NULL)
            return NULL;
        Node *newnode;
        unordered_map<Node *, Node *> mpp;

        if (node->neighbors.size() == 0)
        {
            Node *clone = new Node(node->val);
            return clone;
        }
        else
            return dfs(node, mpp);
    }
};