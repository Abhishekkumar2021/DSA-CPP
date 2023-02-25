/*
Given the root of a binary tree. Check whether it is a BST or not.
Note: We are considering that BSTs can not contain duplicate Nodes.
A BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:

Input:
   2
 /    \
1      3
Output: 1 
Explanation: 
The left subtree of root node contains node
with key lesser than the root nodes key and 
the right subtree of root node contains node 
with key greater than the root nodes key.
Hence, the tree is a BST.
Example 2:

Input:
  2
   \
    7
     \
      6
       \
        5
         \
          9
           \
            2
             \
              6
Output: 0 
Explanation: 
Since the node with value 7 has right subtree 
nodes with keys less than 7, this is not a BST.

Approach:
1. Check if the left subtree is BST and the right subtree is BST.
2. Check if the left subtree is less than the root and the right subtree is greater than the root.
3. Check if the left subtree is less than the root and the right subtree is less than the root.
4. Check if the left subtree is greater than the root and the right subtree is greater than the root.

*/

#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
};
    


class Solution
{
    public:
    //Function to check whether a Binary Tree is BST or not.

    int maximum(Node* root)
    {
        if(!root)
        return INT_MIN;
        return max({maximum(root->left),maximum(root->right),root->data});
    }

    int minimum(Node* root)
    {
        if(!root)
        return INT_MAX;
        return min({minimum(root->left),minimum(root->right),root->data});
    }

    bool isBST(Node* root) 
    {
        if(!root)
        return true;
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            Node* temp=q.front();
            q.pop();
            if(temp->left)
            {
                if(temp->left->data>=temp->data || maximum(temp->left)>=temp->data)
                return false;
                q.push(temp->left);
            }
            if(temp->right)
            {
                if(temp->right->data<=temp->data || minimum(temp->right)<=temp->data)
                return false;
                q.push(temp->right);
            }
        }
        return true;
    }
};