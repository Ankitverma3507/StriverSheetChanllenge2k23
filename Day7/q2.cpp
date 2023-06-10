#include <bits/stdc++.h>
using namespace std;
////////////////////////////////////////////////////---Brute force approach
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*>st;
        Node * temp= head;
        while(temp != NULL){
            Node *copied= new Node(temp->val);
            st[temp]= copied;
            temp= temp->next;
        }


        Node* t = head;
//second iteration for linking next and random pointer as given question.
    while(t != NULL) {
        Node* node = st[t];
        node->next = (t->next != NULL) ? st[t->next]:NULL;
        node->random = (t->random != NULL) ? st[t->random]:NULL;
        t = t->next;
    }
    return st[head];
    }
};





////////////////////////////////////////////////////-MOST OPTIMAL approach

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node * temp=head;
        while(temp !=NULL){
            Node *copied= new Node(temp->val);
            copied->next= temp->next? temp->next: NULL;
            temp->next= copied;
            temp=temp->next->next;
        }

        Node* itt= head;
        while(itt !=NULL){
            itt->next->random= itt->random? itt->random->next: NULL;
            itt= itt->next->next;
        }

        Node *dummy= new Node(0);
        itt=head;
        temp= dummy;
        Node *fast;
        while(itt != NULL){
            fast= itt->next->next;
            temp->next= itt->next;
            itt->next= fast;
            temp= temp->next;
            itt= fast;
        }

        return dummy->next;

        
    }
};