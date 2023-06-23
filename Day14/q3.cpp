#include <bits/stdc++.h>
#include <list>
using namespace std;
struct node
{
    int key, value, cnt;
    node *next;
    node *prev;

    node(int key, int value)
    {
        this->key = key;
        this->value = value;
        cnt = 1;
    }
};

struct List
{
    int size;
    node *head;
    node *tail;

    List()
    {
        head = new node(0, 0);
        tail = new node(0, 0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    void addFront(node *newnode)
    {
        node *temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
        size++;
    }

    void removeNode(node *delnode)
    {
        node *delnext = delnode->next;
        node *delprev = delnode->prev;
        delprev->next = delnext;
        delnext->prev = delprev;
        size--;
    }
};

class LFUCache
{

    map<int, node *> keynode;
    map<int, List*> freqlistMap;
    int maxSizeCache;
    int minFreq;
    int curSize;

public:
    LFUCache(int capacity)
    {
        maxSizeCache = capacity;
        minFreq = 0;
        curSize = 0;
    }

    void updateFreqListMap(node *temp)
    {
        keynode.erase(temp->key);
        freqlistMap[temp->cnt]->removeNode(temp);
        if (temp->cnt == minFreq and freqlistMap[temp->cnt]->size == 0)
        {
            minFreq++;
        }

        List *nexthigherfreqList = new List();
        if (freqlistMap.find(temp->cnt + 1) != freqlistMap.end())
        {
            nexthigherfreqList = freqlistMap[temp->cnt + 1];
        }
        temp->cnt += 1;
        nexthigherfreqList->addFront(temp);
        freqlistMap[temp->cnt] = nexthigherfreqList;
        keynode[temp->key] = temp;
    }

    int get(int key)
    {
        if (keynode.find(key) != keynode.end())
        {
            node *newnode = keynode[key];
            int val = newnode->value;
            updateFreqListMap(newnode);
            return val;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (maxSizeCache == 0)
            return;

        if (keynode.find(key) != keynode.end())
        {
            node *newnode = keynode[key];
            newnode->value = value;
            updateFreqListMap(newnode);
        }

        else
        {
            if (curSize == maxSizeCache)
            {
                List *newlist = freqlistMap[minFreq];
                keynode.erase(newlist->tail->prev->key);
                freqlistMap[minFreq]->removeNode(newlist->tail->prev);
                curSize--;
            }
            curSize++;
            minFreq = 1;
            List *listfreq = new List();
            if (freqlistMap.find(minFreq) != freqlistMap.end())
            {
                listfreq = freqlistMap[minFreq];
            }
            node *newnode = new node(key, value);
            listfreq->addFront(newnode);
            keynode[key] = newnode;
            freqlistMap[minFreq] = listfreq;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */