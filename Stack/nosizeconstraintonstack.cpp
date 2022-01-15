#include <iostream>
using namespace std;
class stack
{
private:
    int *data;
    int nextindex;
    int capacity=10;

public:
    stack()
    {
        data = new int[capacity];
        nextindex = 0;
        
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
            int *newdata = new int[2*capacity];
            for(int i = 0; i < capacity; i++){
                newdata[i] = data[i];
            }
            capacity = 2*capacity;
            delete[] data;
            data = newdata;
           
        }
        data[nextindex++] = element;
    }
    int pop()
    {
        if (isempty())
        {
            cout << "\nSorry, stack isempty";
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
    stack s;
    if (s.isempty()){
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
    s.push(120);
    s.push(130);
    s.push(140);
    s.push(150);
    cout<<endl<<s.size();
    cout << endl<< s.top();
}