#include <bits/stdc++.h>
using namespace std;
////////////////////////////////////using 2 stacks
class MyQueue
{
    stack<int> s1;
    stack<int> s2;

public:
    MyQueue()
    {
    }

    void push(int x)
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }

        s1.push(x);

        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int pop()
    {
        int ans = s1.top();
        s1.pop();
        return ans;
    }

    int peek()
    {
        return s1.top();
    }

    bool empty()
    {
        if (s1.empty())
            return true;
        else
            return false;
    }
};





#include <bits/stdc++.h>
using namespace std;
////////////////////////////////////optimised
class MyQueue
{
    stack<int> input;
    stack<int> output;

public:
    MyQueue()
    {
    }

    void push(int x)
    {
        input.push(x);
    }

    int pop()
    {

        if (output.empty())
        {
            while (!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
        }

        int ans = output.top();
        output.pop();
        return ans;
    }

    int peek()
    {
        if (output.empty())
        {
            while (!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
        }
        return output.top();
    }

    bool empty()
    {
        if (output.empty() and input.empty())
            return true;
        else
            return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */