#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node *next;

    Node(T data)
    {
        next = NULL;
        this->data = data;
    }

    ~Node()
    {
        if (next != NULL)
        {
            delete next;
        }
    }
};

#include <bits/stdc++.h>

class compare
{
public:
    bool operator()(Node<int> *a, Node<int> *b)
    {
        return a->data > b->data;
    }
};

Node<int> *mergeKLists(vector<Node<int> *> &listArray)
{
    // Write your code here.
    priority_queue<Node<int> *, vector<Node<int> *>, compare> pq;
    int n = listArray.size();
    if (n == 0)
        return NULL;

    for (int i = 0; i < n; i++)
    {
        if (listArray[i] != NULL)
        {
            pq.push(listArray[i]);
        }
    }

    Node<int> *head = NULL;
    Node<int> *tail = NULL;

    while (pq.size() > 0)
    {
        Node<int> *temp = pq.top();
        pq.pop();

        if (temp->next != NULL)
        {
            pq.push(temp->next);
        }
        if (head == NULL)
        {
            head = temp;
            tail = temp;
        }

        else
        {
            tail->next = temp;
            tail = temp;
        }
    }

    return head;
}
