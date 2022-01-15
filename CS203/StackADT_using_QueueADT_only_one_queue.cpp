#include <bits/stdc++.h>
#include "Queue_as_ADT_template.h"
using namespace std;

template <typename T>
class StackADT
{
    QueueADT<T> queue;
public:
    void createNewStack(int capacity){
        queue.createNewQueue(capacity);
    }
    bool isEmpty(){
        return queue.isEmpty();
    }
    bool isFull(){
        return queue.isFull();
    }
    void push(T item){
        queue.Add(item);
    }
    T pop(){
      int size = queue.size();
      for(int count = 0; count<size-1; ++count){
         queue.Add(queue.Delete());
      }
      T answer = queue.Delete();
      return answer;
    
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    StackADT<int> stack;
    stack.createNewStack(5);
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(50);
    stack.push(60);
    cout << stack.pop() << endl;
    cout << stack.pop() << endl;
    cout << stack.pop() << endl;
    cout << stack.pop() << endl;
    cout << stack.pop()<< endl;
    cout << stack.pop()<< endl;
    cout << stack.pop()<< endl;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(50);
    stack.push(60);
    cout << stack.pop() << endl;
    cout << stack.pop() << endl;
    cout << stack.pop() << endl;
    cout << stack.pop() << endl;
    cout << stack.pop() << endl;
    cout << stack.pop() << endl;
    cout << stack.pop() << endl;
    return 0;
}