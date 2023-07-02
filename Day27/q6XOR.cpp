#include <bits/stdc++.h>
using namespace std;
struct Node
{
    Node *links[2];

    bool iscontainkey(int bit)
    {
        return (links[bit] != NULL);
    }

    Node *get(int bit)
    {
        return links[bit];
    }

    void put(int bit, Node *node)
    {
        links[bit] = node;
    }
};

class Trie
{
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(int num)
    {
        Node *node = root;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1; // imp

            if (!node->iscontainkey(bit))
            {
                node->put(bit, new Node());
            }

            node = node->get(bit);
        }
    }

    int getmax(int num)
    {
        Node *node = root;
        int maxno = 0;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;

            if (node->iscontainkey(1 - bit))
            {
                maxno = maxno | (1 << i);
                node = node->get(1 - bit);
            }
            else
            {
                node = node->get(bit);
            }
        }
        return maxno;
    }
};

class Solution
{
public:
    int findMaximumXOR(vector<int> &nums)
    {
        Trie trie;
        for (auto &it : nums)
        {
            trie.insert(it);
        }

        int maxi = 0;
        for (auto &it : nums)
            maxi = max(maxi, trie.getmax(it));

        return maxi;
    }
};