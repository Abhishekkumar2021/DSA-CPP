/*
Given preorder traversal of a binary search tree, construct the BST.
Note: You may assume that duplicates do not exist in the tree. For example, given
preorder = [8,5,1,7,10,12]
Return the following binary search tree:
    8
   / \
  5  10
 / \   \
1   7   12

Approach:
1. Create a node with the first element of the preorder array.
2. Push the node into the stack.
3. Iterate from the second element to the last element of the preorder array.
4. If the current element is less than the top element of the stack, then create a node with the current element and make it the left child of the top element of the stack.
5. Else, pop the top element of the stack until the top element of the stack is greater than the current element.
6. Create a node with the current element and make it the right child of the popped element.
7. Push the current element into the stack.
8. Return the root node.
*/


#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};

Node* constructBST(int preorder[], int n){
    Node* root = new Node(preorder[0]);
    stack<Node*> s;
    s.push(root);
    for(int i=1; i<n; i++){
        Node* temp = NULL;
        if(preorder[i]<s.top()->data){
            temp = new Node(preorder[i]);
            s.top()->left = temp;
            s.push(temp);
        }
        else{
            while(!s.empty() && preorder[i]>s.top()->data){
                temp = s.top();
                s.pop();
            }
            temp->right = new Node(preorder[i]);
            s.push(temp->right);
        }
    }
    return root;
}


int main()
{
    int n;
    cin>>n;
    int preorder[n];
    for(int i=0; i<n; i++){
        cin>>preorder[i];
    }
    Node* root = constructBST(preorder, n);
    return 0;
}
