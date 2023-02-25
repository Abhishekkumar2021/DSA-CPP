/*
Given a linked list of N nodes such that it may contain a loop.

A loop here means that the last node of the link list is connected to the node at position X(1-based index). If the link list does not have any loop, X=0.

Remove the loop from the linked list, if it is present, i.e. unlink the last node which is forming the loop.


Example 1:

Input:
N = 3
value[] = {1,3,4}
X = 2
Output: 1
Explanation: The link list looks like
1 -> 3 -> 4
     ^    |
     |____|
A loop is present. If you remove it
successfully, the answer will be 1.

Example 2:

Input:
N = 4
value[] = {1,8,3,4}
X = 0
Output: 1
Explanation: The Linked list does not
contains any loop.

Example 3:

Input:
N = 4
value[] = {1,2,3,4}
X = 1
Output: 1
Explanation: The link list looks like
1 -> 2 -> 3 -> 4
     |_________|
A loop is present.
If you remove it successfully,
the answer will be 1.

Your Task:
You don't need to read input or print anything. Your task is to complete the function removeLoop() which takes the head of the linked list as the input parameter. Simply remove the loop in the list (if present) without disconnecting any nodes from the list.
Note: The generated output will be 1 if your submitted code is correct.


Expected time complexity: O(N)
Expected auxiliary space: O(1)


Constraints:
1 ≤ N ≤ 10^4

Hint:
1) Use two pointers, fast and slow. Move slow pointer one node at a time and fast pointer two nodes at a time.
2) When they collide, move slow pointer to head and keep fast pointer at the collision point.
3) Move both pointers one node at a time until they collide again. This is the loop starting point.
4) Get pointer to the last node and make next of it as NULL.

*/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
     int data;
     Node *next;
     Node(int x)
     {
          data = x;
          next = NULL;
     }
};

class Solution{
     public:
     //Function to remove a loop in the linked list.
     void removeLoop(Node* head)
     {
          // code here
          // just remove the loop without losing any nodes
          Node *slow = head;
          Node *fast = head;
          while(slow && fast && fast->next){
               slow = slow->next;
               fast = fast->next->next;
               if(slow == fast){
                   if(slow==head){
                       while(fast->next != slow) fast = fast->next;
                       fast->next = NULL;
                       break;
                   }
                    slow = head;
                    while(slow->next != fast->next){
                         slow = slow->next;
                         fast = fast->next;
                    }
                    fast->next = NULL;
                    break;
               }
          }
     }
};

