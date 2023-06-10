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
    ListNode *getIntersectionNode(ListNode *l1, ListNode *l2)
    {
        unordered_set<ListNode *> st;
        while (l1 != NULL)
        {
            st.insert(l1);
            l1 = l1->next;
        }

        while (l2 != NULL)
        {
            if (st.find(l2) != st.end())
            {
                return l2;
            }
            l2 = l2->next;
        }

        return NULL;
    }
};


#include <bits/stdc++.h>
using namespace std;
////////////////////////////////////////////////////---OPTIMISE approach1 BUT IT IS LENGTHY TO CODE
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {

 private:
 int getDifference(ListNode* head1,ListNode* head2) {
     int len1 = 0,len2 = 0;
        while(head1 != NULL || head2 != NULL) {
            if(head1 != NULL) {
                ++len1; head1 = head1->next;
            }
            if(head2 != NULL) {
                ++len2; head2 = head2->next;
            }
            
        }
        return len1-len2;//if difference is neg-> length of list2 > length of list1 else vice-versa
}

public:
    ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {
        int diff = getDifference(head1,head2);
        if(diff < 0) 
            while(diff++ != 0) head2 = head2->next; 
        else while(diff-- != 0) head1 = head1->next;
        while(head1 != NULL) {
            if(head1 == head2) return head1;
            head2 = head2->next;
            head1 = head1->next;
        }
        return head1;
    }
};




#include <bits/stdc++.h>
using namespace std;
////////////////////////////////////////////////////---OPTIMISE approach2 
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
    ListNode *getIntersectionNode(ListNode *l1, ListNode *l2) {
        ListNode *d1= l1;
        ListNode *d2= l2;

        while(d1!= d2 ){
            if(d1==NULL) 
            d1= l2;
            else d1=d1->next;

            if(d2==NULL) 
            d2=l1;
            else
            d2=d2->next;
        }

        return d1;


    }
};