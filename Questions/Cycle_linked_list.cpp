#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};

class List{
    private:
        Node* head;
        Node* tail;
    public:
        List(){
            head = NULL;
            tail = NULL;
        }
        void insert(int data){
            Node* temp = new Node(data);
            if(head == NULL){
                head = temp;
                tail = temp;
            }
            else{
                tail->next = temp;
                tail = temp;
            }
        }
        void print(){
            Node* temp = head;
            while(temp != NULL){
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
        void makeCycle(int pos){
            Node* temp = head;
            Node* startNode;
            int count = 1;
            while(temp->next != NULL){
                if(count == pos){
                    startNode = temp;
                }
                temp = temp->next;
                count++;
            }
            tail->next = startNode;
        }
        bool detectCycle(){
            Node* slow = head;
            Node* fast = head;
            while(fast != NULL && fast->next != NULL){
                slow = slow->next;
                fast = fast->next->next;
                if(slow == fast){
                    return true;
                }
            }
            return false;
        }
        int getEntry(){
            Node* slow = head;
            Node* fast = head;
            while(fast != NULL && fast->next != NULL){
                slow = slow->next;
                fast = fast->next->next;
                if(slow == fast){
                    break;
                }
            }
            slow = head;
            while(slow != fast){
                slow = slow->next;
                fast = fast->next;
            }
            return slow->data;
        }
};

int main(){
    List l;
    l.insert(1);
    l.insert(2);
    l.insert(3);
    l.insert(4);
    l.insert(5);
    l.insert(6);
    l.insert(7);
    l.insert(8);
    l.insert(9);
    l.insert(10);
    l.print();
    l.makeCycle(5);
    cout << l.detectCycle() << endl;
    cout << l.getEntry() << endl; 
    return 0;
}

/*
How to get the starting node of the cycle?
1. Detect the cycle using Floyd's cycle detection algorithm.
2. If cycle is detected, initialize slow pointer to head and move both slow and fast pointers one node at a time.
3. When slow pointer and fast pointer meet at a node, they are at the start of the cycle.
*/