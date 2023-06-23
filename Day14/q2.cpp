#include <bits/stdc++.h>
using namespace std;
class LRUCache
{
public:
    class node
    {
    public:
        int key;
        int value;
        node *next;
        node *prev;

        node(int _key, int _value)
        {
            key = _key;
            value = _value;
        }
    };

    node *head = new node(-1, -1);
    node *tail = new node(-1, -1);

    int cap;
    unordered_map<int, node *> mp;
    LRUCache(int capacity)
    {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addNode(node *newnode)
    {
        node *temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }

    void delNode(node *delnode)
    {
        node *delnext = delnode->next;
        node *delprev = delnode->prev;
        delprev->next = delnext;
        delnext->prev = delprev;
    }

    int get(int key)
    {
        if (mp.find(key) != mp.end())
        {
            node *resnode = mp[key];
            int res = resnode->value;
            mp.erase(key);
            delNode(resnode);
            addNode(resnode);
            mp[key] = head->next;
            return res;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (mp.find(key) != mp.end())
        {
            node *resnode = mp[key];
            mp.erase(key);
            delNode(resnode);
        }

        if (mp.size() == cap)
        {
            mp.erase(tail->prev->key);
            delNode(tail->prev);
        }

        addNode(new node(key, value));
        mp[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */