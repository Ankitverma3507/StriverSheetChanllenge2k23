#include <bits/stdc++.h>
using namespace std;
//////////////////////////////////////////app1 approach
class MinStack
{
    stack<pair<int, int>> st;

public:
    MinStack()
    {
    }
    void push(int x)
    {
        int mini;
        if (st.empty())
        {
            mini = x;
        }

        else
        {
            mini = min(x, st.top().second);
        }
        st.push({x, mini});
    }

    void pop()
    {
        st.pop();
    }

    int top()
    {
        return st.top().first;
    }

    int getMin()
    {
        return st.top().second;
    }
};





/////////////optimised SC= O(n);

class MinStack
{
    stack<long long> st;
    long long mini;

public:
    MinStack()
    {
        while (st.empty() == false)
            st.pop();
        mini = INT_MAX;
    }
    void push(int x)
    {
        long long val = x;
        if (st.empty())
        {
            mini = val;
            st.push(val);
        }

        else
        {
            if (val < mini)
            {
                st.push((2 * val) - mini);
                mini = val;
            }
            else
            {
                st.push(val);
            }
        }
    }

    void pop()
    {
        if (st.empty())
            return;

        long long elem = st.top();
        st.pop();
        if (elem < mini)
        {
            mini = 2 * mini - elem;
        }
    }

    int top()
    {
        if (st.empty())
            return -1;
        long long elem = st.top();
        if (elem < mini)
            return mini;
        return elem;
    }

    int getMin()
    {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */