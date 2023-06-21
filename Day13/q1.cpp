#include <iostream>
using namespace std;

class stack
{
    int size;
    int top;
    int *arr;

public:
    stack()
    {
        top = -1;
        size = 1000;
        arr = new int[size];
    }

    void push(int element)
    {
        top++;
        arr[top] = element;
    }

    int pop()
    {
        int x = arr[top];
        top--;
        return x;
    }

    int Top()
    {
        return arr[top];
    }

    int Size()
    {
        return top + 1;
    }
};
int main()
{

    stack s;
    s.push(9);
    s.push(2);
    s.push(5);
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.Size();

    return 0;
}