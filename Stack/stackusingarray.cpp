#include <iostream>
using namespace std;
class stack
{
private:
    int *data;
    int nextindex;
    int capacity;

public:
    stack(int actualsize)
    {
        data = new int[actualsize];
        nextindex = 0;
        capacity = actualsize;
    }
    int size()
    {
        return nextindex;
    }
    bool isempty()
    {
        return nextindex == 0;
    }
    void push(int element)
    {
        if (nextindex == capacity)
        {
            cout << "\nSorry, stack is full!";
            return;
        }
        data[nextindex++] = element;
    }
    int pop()
    {
        if (isempty())
        {
            cout << "\nSorry, stack is empty";
            return -1;
        }
        else
            return data[--nextindex];
    }
    int top()
    {
        if (nextindex != 0)
            return data[nextindex - 1];
    }
};
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    stack s(10);
    if (s.isempty())
    {
        cout << "stack is empty!";
    }
    s.pop();
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    s.push(70);
    s.push(80);
    s.push(90);
    s.push(100);
    s.push(110);
    cout << endl;
    cout << s.top();
}