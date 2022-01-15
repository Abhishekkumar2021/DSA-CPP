#include<iostream>
using namespace std;


class doublyLinkedList{
 public:
     int data;
     doublyLinkedList *next, *prev;
     doublyLinkedList(){
        next = NULL;
        prev = NULL;
        data = 0;
     } 
};
doublyLinkedList* addBegin(doublyLinkedList *head,doublyLinkedList *tail, int data){
  if(head == NULL){
    doublyLinkedList* newNode = new doublyLinkedList;
    newNode->data = data;
    head = newNode;
    tail = newNode;
    return head;
  }
}

int main(){
    doublyLinkedList *head, *tail;
    head = NULL;
    tail = NULL;
    head = addBegin(head,tail,10);
    cout<<head->data;
    return 0;
}
