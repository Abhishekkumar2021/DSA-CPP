/*
You are given a linked list, you have to reverse the linked list.
*/

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int x){
        data = x;
        next = NULL;
    }
};

class Solution{
    public:
    Node* reverseList(Node* head){
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;
        while(curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};