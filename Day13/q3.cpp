#include <bits/stdc++.h>
using namespace std;
////////////////////////////////////using 2 queues
class MyStack
{
    queue<int> q1;
    queue<int> q2;

public:
    MyStack()
    {
    }

    void push(int x)
    {
        q2.push(x);
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }

        swap(q1, q2);
    }

    int pop()
    {
        int ans = q1.front();
        q1.pop();
        return ans;
    }

    int top()
    {
        return q1.front();
    }

    bool empty()
    {
        if (q1.empty())
            return true;
        else
            return false;
    }
};










////////////////////////////////////using 1 queues

class MyStack
{
    queue<int> q1;

public:
    MyStack()
    {
    }

    void push(int x)
    {
        q1.push(x);
        for (int i = 0; i < q1.size() - 1; i++)
        {
            q1.push(q1.front());
            q1.pop();
        }
    }

    int pop()
    {
        int ans = q1.front();
        q1.pop();
        return ans;
    }

    int top()
    {
        return q1.front();
    }

    bool empty()
    {
        if (q1.empty())
            return true;
        else
            return false;
    }
};
