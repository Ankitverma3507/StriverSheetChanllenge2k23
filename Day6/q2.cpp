#include <bits/stdc++.h>
using namespace std;
////////////////////////////////////////////////////---better approach
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if (head == NULL or head->next == NULL)
            return false;
        unordered_set<ListNode *> st;

        ListNode *temp = head;
        while (temp != NULL)
        {
            if (temp->next == NULL)
                return false;
            if (st.find(temp) != st.end())
            {
                return true;
            }
            st.insert(temp);
            temp = temp->next;
        }

        return false;
    }
};



#include <bits/stdc++.h>
using namespace std;
////////////////////////////////////////////////////---optimal approach
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL or head->next==NULL) return false;
        ListNode *slow= head;
        ListNode *fast= head;

        while(fast->next and fast->next->next){
            slow= slow->next;
            fast= fast->next->next;

            if(slow==fast) return true;
        }
        return false;

    }
};