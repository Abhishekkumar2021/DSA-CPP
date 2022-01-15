#include<bits/stdc++.h>
#include"Array_as_ADT_template.h"
using namespace std;
template <typename T>
class stackADT{
    ArrayADT <T> Array;
    int top;
    public:
    stackADT(){
        top = 0;
    }
        createNewStack(int capacity){            //Theta(1)
            Array.createNewArray(capacity);
        }
        void push(T value){               //Theta(1)
            if(!Array.isFull()){
                Array.storeValue(value, top);
                top++;
            }
            else 
            cout<<"Cannot push!\n";
        }
        T pop() {                        //Theta(1)
            if(Array.isEmpty()){
            cout<<"Cannot pop!\n";
            return -1;
            }
            else {
                top--;
                Array.decreaseSize();
                return Array.accessValue(top);
            }
        }
        bool isFull(){                   //Theta(1)
            return Array.isFull();
        }
        bool isEmpty(){              //Theta(1)
            return  Array.isEmpty();
        }
};
