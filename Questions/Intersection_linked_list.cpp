/*
Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.

Follow up: Could you write a solution that runs in O(m + n) time and use only O(1) memory?

Approach:
1. Find the length of both the linked lists.
2. Move the pointer of the longer list by the difference of the lengths of both the lists.
3. Now move both the pointers simultaneously until they meet.

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
    Node* getIntersectionNode(Node* headA, Node* headB){
        int lenA = 0, lenB = 0;
        Node* tempA = headA;
        Node* tempB = headB;
        while(tempA != NULL){
            lenA++;
            tempA = tempA->next;
        }
        while(tempB != NULL){
            lenB++;
            tempB = tempB->next;
        }
        tempA = headA;
        tempB = headB;
        if(lenA > lenB){
            int diff = lenA - lenB;
            while(diff--){
                tempA = tempA->next;
            }
        }
        else{
            int diff = lenB - lenA;
            while(diff--){
                tempB = tempB->next;
            }
        }
        while(tempA != NULL && tempB != NULL){
            if(tempA == tempB){
                return tempA;
            }
            tempA = tempA->next;
            tempB = tempB->next;
        }
        return NULL;
    }

    Node* getIntersectionNodeUsingSet(Node* headA, Node* headB){
        unordered_set<Node*> s;
        Node* tempA = headA;
        Node* tempB = headB;
        while(tempA != NULL){
            s.insert(tempA);
            tempA = tempA->next;
        }
        while(tempB != NULL){
            if(s.find(tempB) != s.end()){
                return tempB;
            }
            tempB = tempB->next;
        }
        return NULL;
    }
};