/*
Given a Binary Tree, convert it to Binary Search Tree in such a way that keeps the original structure of Binary Tree intact.
 

Example 1:

Input:
      1
    /   \
   2     3
Output: 1 2 3

Example 2:

Input:
          1
       /    \
     2       3
   /        
 4       
Output: 1 2 3 4
Explanation:
The converted BST will be

        3
      /   \
    2     4
  /
 1

Hint: 
1. Do inorder traversal of the given binary tree and store result in an array. This step takes O(n) time.
2. Sort the above created array in increasing order. This step takes O(nLogn) time.
3. Again do inorder traversal of the binary tree and copy array elements to binary tree nodes one by one. This step takes O(n) time.

*/

#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left, *right;
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

class Solution{
  public:
    // The given root is the root of the Binary Tree
    // Return the root of the generated BST
    void storeInorder(Node* root, vector<int> &inorder){
        if(root==NULL) return;
        storeInorder(root->left, inorder);
        inorder.push_back(root->data);
        storeInorder(root->right, inorder);
    }
    
    void changeTree(Node* &root, vector<int> &inorder, int &idx){
        if(root==NULL) return;
        changeTree(root->left, inorder, idx);
        root->data = inorder[idx];
        idx++;
        changeTree(root->right, inorder, idx);
    }
    Node *binaryTreeToBST (Node *root)
    {
        //Your code goes here
        vector<int> inorder;
        storeInorder(root, inorder);
        sort(inorder.begin(), inorder.end());
        int idx = 0;
        changeTree(root, inorder, idx);
        return root;
        
    }
};
