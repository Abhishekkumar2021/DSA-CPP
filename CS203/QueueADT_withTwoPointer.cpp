#include<bits/stdc++.h>
#include "Array_as_ADT_template.h"
using namespace std;

template <typename T>
class QueueADT{
    ArrayADT<T> Array;
    int front;
    int end;
    public:
    QueueADT(){
        front = 0;
        end = 0;
    }

    void createNewQueue(int capacity){   //Theta(1)
        Array.createNewArray(capacity);
    } 

    void Add(T value){            //Theta(1)
       if (!Array.isFull()){
           Array.storeValue(value, end);
           end++;
        }
        else
            cout << "Cannot push!\n";
    }

    T Delete(){                       //Theta(1)
         if(Array.isEmpty()){
            cout<<"Cannot pop!\n";
            return -1;
        }
        else {
            T ans = Array.accessValue(front);
            front++;
            Array.decreaseSize();
            return ans;
        }
    }

     bool isFull() {           //Theta(1)
        return Array.isFull();
    }

    bool isEmpty() {           //Theta(1)
        return Array.isEmpty();
    }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  QueueADT<int> queue;
  queue.createNewQueue(5);
  cout<<queue.Delete()<<endl; 
  queue.Add(10);
  queue.Add(20);
  queue.Add(30);
  queue.Add(40);
  queue.Add(50);
  queue.Add(60);
  queue.Add(70);
  queue.Add(80);
  cout << queue.Delete()<<endl;
  cout << queue.Delete()<<endl;
  cout << queue.Delete()<<endl;
  cout << queue.Delete()<<endl;
  cout << queue.Delete()<<endl;
  cout << queue.Delete()<<endl;
  cout << queue.Delete()<<endl;
  cout << queue.Delete()<<endl;
  cout << queue.Delete()<<endl;
  queue.Add(30);
  queue.Add(40);
  queue.Add(50);
  queue.Add(60);
  queue.Add(70);
  queue.Add(80);
  queue.Add(90);
  queue.Add(100);
  queue.Add(10);
  queue.Add(20);
  queue.Add(30);
  queue.Add(40);
  queue.Add(50);
  queue.Add(60);
  queue.Add(70);
  queue.Add(80);
  cout << queue.Delete() << endl;
  cout << queue.Delete() << endl;
  cout << queue.Delete() << endl;
  cout << queue.Delete() << endl;
  cout << queue.Delete() << endl;
  cout << queue.Delete() << endl;
  cout << queue.Delete() << endl;
  cout << queue.Delete() << endl;
  cout << queue.Delete() << endl;
  queue.Add(30);
  queue.Add(40);
  queue.Add(50);
  queue.Add(60);
  queue.Add(70);
  queue.Add(80);
  queue.Add(90);
  queue.Add(100);
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


