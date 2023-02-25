/*
Given a singly linked list, remove all the nodes which have a greater value on their right side.

Example 1:

Input:
LinkedList = 12->15->10->11->5->6->2->3
Output: 15 11 6 3
Explanation: Since, 12, 10, 5 and 2 are
the elements which have greater elements
on the following nodes. So, after deleting
them, the linked list would like be 15,
11, 6, 3.
Example 2:

Input:
LinkedList = 10->20->30->40->50->60
Output: 60
Your Task:
The task is to complete the function compute() which should modify the list as required and return the head of the modified linked list. The printing is done by the driver code,

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ size of linked list ≤ 1000
1 ≤ element of linked list ≤ 1000
Note: Try to solve the problem without using any extra space.

Hint:
Traverse the list from right to left and keep track of maximum till now. If you find a node whose value is less than maximum, then delete the node.
*/

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int x){
        data = x;
        next = NULL;
    }
};

class Solution
{
    public:
    Node *compute(Node *head)
    {
        Node* curr = head;
        Node *next = head->next;
        Node *prev = NULL;

        while(next != NULL){
            if(curr->data < next->data){
                if(prev == NULL){
                    head = next;
                    curr = next;
                    next = next->next;
                }
                else{
                    prev->next = next;
                    curr = next;
                    next = next->next;
                }
            }
            else{
                prev = curr;
                curr = next;
                next = next->next;
            }
        }
        return head;
        
    }
};

