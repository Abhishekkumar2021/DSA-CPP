#include<bits/stdc++.h>
using namespace std;

template <typename T>
class Queue{
    T *data;
    int capacity;
    int head;
    int tail;
    public:
    Queue(int capacity){
        data = new T[capacity];
        head = 0;
        tail = 0;
        this->capacity = capacity;
    }
    bool isEmpty(){
        return head == tail;
    }
    bool isFull(){
        return (circularAddition(tail) == head);
    }
    int circularAddition(int index){
        if(index==capacity)
        return 0;
        else 
        return index+1;
    }
    void  Add(T value){
        if(isFull())
        cout<<"Queue is full!\n";
        else{
            data[tail] = value;
            tail = circularAddition(tail);
        }
    }
    T Delete() {
        if(isEmpty()){
           cout<<"Queue is empty!\n";
           return 0;;
        }
        else{
            T ans = data[head];
            head = circularAddition(head);
            return ans;
        }
    }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  Queue<int> queue(10);
  cout<<queue.Delete()<<endl;
  queue.Add(10);
  queue.Add(20);
  queue.Add(30);
  queue.Add(40);
  queue.Add(50);
  queue.Add(60);
  queue.Add(70);
  queue.Add(80);
  queue.Add(90);
  queue.Add(100);
  queue.Add(110);
  cout << queue.Delete()<<endl;
  cout << queue.Delete()<<endl;
  cout << queue.Delete() << endl;
  cout << queue.Delete() << endl;
  cout << queue.Delete() << endl;
  cout << queue.Delete() << endl;
  cout << queue.Delete() << endl;
  cout << queue.Delete() << endl;
  cout << queue.Delete() << endl;
  cout << queue.Delete() << endl;
  cout << queue.Delete() << endl;
  cout << queue.Delete() << endl;
  cout << queue.Delete() << endl;
  cout << queue.Delete() << endl;
  cout << queue.Delete() << endl;
  cout << queue.Delete() << endl;
  cout << queue.Delete() << endl;
  cout << queue.Delete() << endl;
  cout << queue.Delete() << endl;
  cout << queue.Delete() << endl;
  return 0;
}