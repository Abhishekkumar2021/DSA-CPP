#include <bits/stdc++.h>
#include "Array_as_ADT_template.h"
using namespace std;
template <typename T>
class QueueADT{
    ArrayADT<T> Array;
    int top;
    public:
    QueueADT(){
        top = 0;
    }
    void createNewQueue(int capacity) {
        Array.createNewArray(capacity);
    }
    void Add(T value) {
        if (!Array.isFull()){
            Array.storeValue(value, top);
            top++;
        }
        else
            cout << "Cannot push!\n";
    }
    int size(){
        return Array.getSize();
    }
    T Delete() {              //This function is of Theta(n);
         if(Array.isEmpty()){
            cout<<"Cannot pop!\n";
            return -1;
            }
            else {
                int ans = Array.accessValue(0);
                top--;
                Array.decreaseSize();
                for (int i = 0; i < top; i++){
                    Array.storeValue(Array.accessValue(i+1),i); 
                }
     
                return ans;
            }
    }
    bool isFull() {
        return Array.isFull();
    }
    bool isEmpty() { 
        return Array.isEmpty();
    }
    void transferAll(QueueADT target) {
        while(!isEmpty()){
            T ans = Delete();
            target.Add(ans);
        }
    }
    void transferAllButOne(QueueADT target){
        while(!isEmpty()){
           T ans = Delete();
           if(isEmpty()){
               Add(ans);
               return;
           }
           else 
           target.Add(ans);
       
        }
    }
};