#include <bits/stdc++.h>
using namespace std;
////////////////////////////////////////////////////---Brute force approach
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
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (k == 0 or head == NULL or head->next == NULL)
            return head;

        for (int i = 1; i <= k; i++)
        {
            ListNode *temp = head;
            while (temp->next->next != NULL)
                temp = temp->next;

            ListNode *tail = temp->next;

            temp->next = NULL;
            tail->next = head;
            head = tail;
        }

        return head;
    }
};








#include <bits/stdc++.h>
using namespace std;
////////////////////////////////////////////////////---Optimal approach
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(k==0 or head==NULL or head->next==NULL) return head;
        ListNode *temp=head;
        int len=1;
        while(temp->next != NULL){
            temp= temp->next;
            len++;
        }
         k= k%len;
        temp->next= head; 

        for(int i=1; i<= len-k; i++){
            temp= temp->next;
        }

        head= temp->next;
        temp->next= NULL;
        return head;
    }
};