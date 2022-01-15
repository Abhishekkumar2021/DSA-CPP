#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* next;
};

node *insertBeg(node* head,int value){
    if(head==NULL){
       node* newNode = new node;
       newNode->data = value;
       newNode->next = NULL;
       head = newNode;
       return head;
    }
    node* newNode = new node;
    newNode->data = value;
    newNode->next = head;
    head = newNode;
    return head;
}
void print(node* head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}
node* evenFirst(node* head){
    if(head==NULL){
        return head;
    }
    node* prev = NULL;
    node* curr = head;
    node* nextEven = NULL;
    if(head->data%2==0){
        prev = head;
        curr = head->next;
        nextEven = head;
    }
    while(curr!=NULL){
        node* current = curr;
        node* previous = prev;
        prev = curr;
        curr = curr->next;
        if(current->data%2==0){
            prev = previous;
            previous->next = current->next;
            if(nextEven==NULL){
                current->next = head;
                nextEven = current;
                head = current;
            }
            else{
                current->next = nextEven->next;
                nextEven->next = current;
                nextEven = current;
            }
        }
    }
    return head;
}
int main() {
    node* head = NULL;
    for(int i=5; i>=2; i--){
        head = insertBeg(head,i);
    }
    print(head);
    head = evenFirst(head);
    cout<<"\n";
    print(head);
}