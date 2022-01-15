#include <iostream>
using namespace std;
template <typename T>
class stack
{
private:
    T *data;
    int nextindex;
    int capacity;

public:
    stack(int actualsize)
    {
        data = new T[actualsize];
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
    void push(T element)
    {
        if (nextindex == capacity)
        {
            cout << "\nSorry, stack is full!";
            return;
        }
        data[nextindex++] = element;
    }
    T pop()
    {
        if (isempty())
        {
            cout << "\nSorry, stack is empty";
            return 0;
        }
        else
            return data[--nextindex];
    }
    T top()
    {
        if (nextindex != 0)
            return data[nextindex - 1];
    }
};
int main()
{

    stack<string> s(10);
    if (s.isempty())
    {
        cout << "stack is empty!";
    }
    string str = "Abhishek";
    s.pop();
    s.push(str);
    s.push(str);
    s.push(str);
    s.push(str);
    s.push(str);
    s.push(str);
    s.push(str);
    s.push(str);
    s.push(str);
    s.push(str);
    s.push(str);
    s.push(str);
    cout << endl
         << s.top();
}