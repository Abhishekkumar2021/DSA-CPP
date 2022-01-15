#include<iostream>
using namespace std;

class Stack{
    int *array;
    int top;
    int capacity;
    public:
    Stack(){
        top=0;
        array=NULL;
        capacity=0;
    }
    void createNewStack(int capacity){
        array = new int[capacity];
        this->capacity = capacity;
    }
    void reverse(){
        for(int i=0; i<top/2; i++){
            int temp =  array[i];
            array[i]=array[top-1-i];
            array[top-1-i] = temp;
            
        }
           
    }

    void push(int data){
        if(top==capacity){
            cout<<"Stack is full :( \n";
            return;
        }
        this->reverse();
        array[top]=data;
        top++;
    }
    int pop(){
        if(top==0)
            return -1;
        int element = array[top];
        top--;
        this->reverse();
        return element;
    }
    void printStack(){
        cout<<top<<" elements : ";
        for(int i=0; i<top; i++){
            cout<<array[i]<<" ";
        }
        cout<<"\n";
    }
    
};

int main(){
    int totalLines = 19;
    int commands = 0;
    Stack stack;
    int code;
    cin>>code;
    commands++;
    if(code==1){
        int size;
        cin>>size;
        stack.createNewStack(5);
        commands++;
    }
   
    while(commands<totalLines){
        int nextCode;
        cin>>nextCode;
        switch(nextCode){
            case 2 : {
                int element;
                cin>>element;
                stack.push(element);
                commands+=2;
            }
            break;
            case 3 : {
                int poppedElement = stack.pop();
                commands++;
            }
            break;
            case 7 : {
                stack.printStack();
                commands++;
            }
            break;
            default : cout<<"Sorry! I didn't understand your input :(\n";
        }
    }
   
}