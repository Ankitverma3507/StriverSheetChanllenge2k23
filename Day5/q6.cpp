
#include <bits/stdc++.h>
using namespace std;
    // THIS QUESTION HAS ONLY ONE APPROACH/
////////////////////////////////////////////////////---optimal approach

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution
{
public:
    void deleteNode(ListNode *node)
    {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};