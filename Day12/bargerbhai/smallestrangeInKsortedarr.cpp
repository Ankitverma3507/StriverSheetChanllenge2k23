#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    int row;
    int col;

    node(int data, int row, int col)
    {
        this->data = data;
        this->row = row;
        this->col = col;
    }
};

class compare
{
public:
    bool operator()(node *a, node *b)
    {
        return a->data > b->data;
    }
};

int kSorted(vector<vector<int>> &a, int k, int n)
{
    // Write your code here.
    int mini = INT_MAX;
    int maxi = INT_MIN;

    priority_queue<node *, vector<node *>, compare> pq;

    for (int i = 0; i < k; i++)
    {
        mini = min(mini, a[i][0]);
        maxi = max(maxi, a[i][0]);
        pq.push(new node(a[i][0], i, 0));
    }

    int start = mini;
    int end = maxi;

    while (!pq.empty())
    {
        node *temp = pq.top();
        pq.pop();

        mini = temp->data;
        if (maxi - mini < end - start)
        {
            end = maxi;
            start = mini;
        }

        if (temp->col + 1 < n)
        {
            maxi = max(maxi, a[temp->row][temp->col + 1]);
            node *temp = new node(a[temp->row][temp->col + 1], temp->row, temp->col + 1);
            pq.push(temp);
        }

        else
        {
            break;
        }
    }

    return (end - start + 1);
}