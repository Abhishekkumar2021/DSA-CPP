#include<bits/stdc++.h>
#include"Queue_as_ADT_template.h"
using namespace std;


template <typename T>
class StackADT{
    QueueADT<T> firstQueue;
    QueueADT<T> secondQueue;
    public:
    void createNewStack(int capacity) {
      firstQueue.createNewQueue(capacity);
      secondQueue.createNewQueue(capacity);
    }
    bool isEmpty() {
      return firstQueue.isEmpty();
    }
    bool isFull() {
      return firstQueue.isFull();
    }
    void push(T item) {
      firstQueue.Add(item);
    }
    void pop() {
      firstQueue.transferAllButOne(secondQueue);
      firstQueue.Delete();
      secondQueue.transferAll(firstQueue);

    }

};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  StackADT<int> stack;
  stack.createNewStack(5);
  stack.pop();
  return 0;
}