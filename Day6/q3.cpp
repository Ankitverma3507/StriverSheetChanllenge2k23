
#include <bits/stdc++.h>
using namespace std;
////////////////////////////////////////////////////---optimal approach(THE ONLY APPROACH)
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (head == NULL or k == 1)
            return head;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *pre = dummy, *curr = dummy, *nex = dummy;
        int cnt = 0;

        while (curr->next != NULL)
        {
            curr = curr->next;
            cnt++;
        }

        while (cnt >= k)
        {
            curr = pre->next;
            nex = curr->next;

            for (int i = 1; i < k; i++)
            {
                curr->next = nex->next;
                nex->next = pre->next;
                pre->next = nex;
                nex = curr->next;
            }
            cnt -= k;
            pre = curr;
        }

        return dummy->next;
    }
};