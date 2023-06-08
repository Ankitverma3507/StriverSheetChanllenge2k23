#include <bits/stdc++.h>
using namespace std;
//////////////////////////////////////Iterative Way

template <typename T>
class LinkedListNode
{
public:
    T data;
    LinkedListNode<T> *next;
    LinkedListNode(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head)
{
    // Write your code here
    if (head == NULL or head->next == NULL)
        return head;

    LinkedListNode<int> *prev = NULL;
    LinkedListNode<int> *curr = head;
    LinkedListNode<int> *forward = NULL;

    while (curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;

        prev = curr;
        curr = forward;
    }

    return prev;
}

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//////////////////////////////////////Recursive Way

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (head == NULL or head->next == NULL)
            return head;

        ListNode *newnode = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;

        return newnode;
    }
};