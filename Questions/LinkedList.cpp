#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        next = NULL;
    }
};

class LinkedList{
public:
    Node* head;
    LinkedList(){
        head = NULL;
    }
    void insert(int data){
        Node* temp = new Node(data);
        if(head == NULL){
            head = temp;
            return;
        }
        Node* curr = head;
        while(curr->next != NULL){
            curr = curr->next;
        }
        curr->next = temp;
    }
    void print(){
        Node* curr = head;
        while(curr != NULL){
            cout<<curr->data<<" ";
            curr = curr->next;
        }
        cout<<endl;
    }
    void reverse(){
        Node* curr = head;
        Node* prev = NULL;
        Node* next = NULL;
        while(curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    
};


void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertAtHead(Node* &head, int data){
    Node* n = new Node(data);
    n->next = head;
    head = n;
}

void insertAtTail(Node* &head, int data){
    if(head == NULL){
        insertAtHead(head, data);
        return;
    }
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    Node* n = new Node(data);
    temp->next = n;
}

void insertAtMiddle(Node* &head, int data, int pos){
    if(head == NULL || pos == 0){
        insertAtHead(head, data);
        return;
    }
    else if(pos > length(head)){
        insertAtTail(head, data);
        return;
    }
    else{
        int jump = 1;
        Node* temp = head;
        while(jump <= pos-1){
            temp = temp->next;
            jump++;
        }
        Node* n = new Node(data);
        n->next = temp->next;
        temp->next = n;
    }
}

int length(Node* head){
    int len = 0;
    Node* temp = head;
    while(temp != NULL){
        temp = temp->next;
        len++;
    }
    return len;
}

void deleteAtHead(Node* &head){
    if(head == NULL){
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
}

void deleteAtTail(Node* &head){
    if(head == NULL){
        return;
    }
    Node* temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    Node* toDelete = temp->next;
    temp->next = NULL;
    delete toDelete;
}

void deleteAtMiddle(Node* &head, int pos){
    if(head == NULL){
        return;
    }
    else if(pos == 0){
        deleteAtHead(head);
        return;
    }
    else if(pos >= length(head)){
        deleteAtTail(head);
        return;
    }
    else{
        int jump = 1;
        Node* temp = head;
        while(jump <= pos-1){
            temp = temp->next;
            jump++;
        }
        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }
}

int main(){
    Node* head = NULL;
    insertAtHead(head, 5);
    insertAtHead(head, 4);
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    insertAtTail(head, 6);
    insertAtMiddle(head, 7, 3);
    print(head);
    deleteAtHead(head);
    deleteAtTail(head);
    deleteAtMiddle(head, 2);
    print(head);
    return 0;
}

/*
Dry Run - 
1 2 3 7 4 5 6
2 7 4 5
*/

