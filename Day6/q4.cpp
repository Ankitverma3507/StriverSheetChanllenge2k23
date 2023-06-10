#include <bits/stdc++.h>
using namespace std;
////////////////////////////////////////////////////---optimal approach
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
private:
    ListNode *midpoint(ListNode *head)
    {
        if (head == NULL)
        {
            return head;
        }
        if (head->next == NULL || head->next->next == NULL)
        {
            return head;
        }

        ListNode *slow = head;
        ListNode *fast = head->next;

        while (fast != NULL && fast->next != NULL)
        {
            // fast=fast->next;
            // if(fast!=NULL)
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    ListNode *reverselinkedlist(ListNode *head)
    {

        ListNode *curr = head;
        ListNode *prev = NULL;
        ListNode *forward = NULL;
        while (curr != NULL)
        {
            forward = curr->next;

            curr->next = prev;

            prev = curr;
            curr = forward;
        }
        return prev;
    }

public:
    bool isPalindrome(ListNode *head)
    {
        // Write your code here
        if (head == NULL || head->next == NULL)
        {
            return true;
        }
        ListNode *mid = midpoint(head);

        ListNode *temp = mid->next;
        mid->next = reverselinkedlist(temp);

        ListNode *head1 = head;
        ListNode *head2 = mid->next;

        while (head2 != NULL)
        {
            if (head1->val != head2->val)
            {
                return false;
                break;
            }
            else
            {
                head1 = head1->next;
                head2 = head2->next;
            }
        }
        temp = mid->next;
        mid->next = reverselinkedlist(temp);

        return true;
    }
};