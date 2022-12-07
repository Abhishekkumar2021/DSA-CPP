#include<bits/stdc++.h>
using namespace std;

class Queue{
    int arr[100];
    int front;
    int rear;
    public:
    Queue(){
        front = -1;
        rear = -1;
    }
    void push(int data){
        if(rear == 99){
            cout << "Queue Overflow" << endl;
            return;
        }
        rear++;
        arr[rear] = data;
        if(front == -1){
            front++;
        }
    }
    void pop(){
        if(front == -1){
            cout << "Queue Underflow" << endl;
            return;
        }
        front++;
        if(front > rear){
            front = -1;
            rear = -1;
        }
    }
    int Front(){
        if(front == -1){
            cout << "Queue Underflow" << endl;
            return -1;
        }
        return arr[front];
    }
    bool empty(){
        return front == -1;
    }
};

int main(){
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);
    q.push(9);
    q.push(10);
    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    q.push(16);
    q.push(17);
    q.push(18);
    q.push(19);
    q.push(20);
    q.push(21);
    while(!q.empty()){
        cout << q.Front() << " ";
        q.pop();
    }
    cout << endl;
    return 0;
}