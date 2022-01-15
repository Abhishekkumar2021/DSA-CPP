#include<iostream>
#include"BST.h"
using namespace std;
class BinarySearchTree{
    BST<int> *root; 
    public:
    void insert(int data){
        root = insertElement(root,data);
    }
    bool isPresent(int data){
       return hasData(data, root);
    }
    void takeInput(){
        root = createTree();
    }
    void deleteElement(int data){
        root = Delete(root,data);
    }
    void print(){
        printTree(root);
    }
    BinarySearchTree(){
        root = NULL;
    }
    ~BinarySearchTree(){
        delete root;
    }
};