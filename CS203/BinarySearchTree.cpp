#include<bits/stdc++.h>
#include "BinarySearchTree.h"
using namespace std;
int main() {
    BST *root = NULL;
    // root = insert(root,10);
    // root = insert(root, 20);
    // root = insert(root,5);
    // root = insert(root, 50);
    // root = insert(root, 0);
    // root = insert(root, -5);
    for(int i=10; i<=200; i+=10){
        root= insert(root,i);
    }
    // inOrder(root);
    // cout<<root->leftChild->parent->data;
    // BST *min = minimum(root);
    // cout<<min->data<<endl;
    // BST *max = maximum(root);
    // cout << max->data<<endl;
    // delete root;
    // inOrder(root);
    // cout<<endl;
    // deOrder(root);
    // cout<<endl;
    // preOrder(root);
    // cout<<addressof(root,10);
    // printTree(root);
    // cout<<succesor(root,-5)->data<<endl;
    // cout<<predeccesor(root,-5)->data<<endl;
    
}