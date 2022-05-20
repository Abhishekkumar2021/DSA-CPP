#include<bits/stdc++.h>
using namespace std;

class RBTNode{
    public:
    char color;
    int data;
    RBTNode *leftChild;
    RBTNode *rightChild;
    RBTNode *parent;
    RBTNode(){
        color=' ';
        data = 0;
        leftChild = NULL;
        rightChild = NULL;
        parent = NULL;
    }
    RBTNode(int data,char color){
        this->color=color;
        this->data = data;
        leftChild = NULL;
        rightChild = NULL;
        parent = NULL;
    }
    ~RBTNode(){
        delete leftChild;
        delete rightChild;;
        cout<<this->data<<" of "<<this->color<<" is deleted!";
    }
};

class RBT{
    RBTNode *NIL = new RBTNode(-1,'B');
    RBTNode *root = NIL;
    void preOrderHelper(RBTNode *root){
        if(root==NIL){
            return;
        }
        cout<<root->data<<" ";
        preOrderHelper(root->leftChild);
        preOrderHelper(root->rightChild);
    }
    void inOrderHelper(RBTNode *root){
        if(root==NIL){
            return;
        }
        inOrderHelper(root->leftChild);
        cout<<root->data<<" ";
        inOrderHelper(root->rightChild);
    }
    void postOrderHelper(RBTNode *root){
        if(root==NIL){
            return;
        }
        postOrderHelper(root->rightChild);
        cout<<root->data<<" ";
        postOrderHelper(root->leftChild);   
    }
     RBTNode* minimumHelper(RBTNode* root){
        if(root==NIL){
            return root;
        }
        if(root->leftChild==NIL){
            return root;
        }
        return minimumHelper(root->leftChild);
    }
    RBTNode* maximumHelper(RBTNode* root){
        if(root==NIL){
            return root;
        }
        if(root->rightChild==NIL){
            return root;
        }
        return maximumHelper(root->rightChild);
    }
    RBTNode* searchHelper(RBTNode* root, int value){
        if(root== NIL){
            return root;
        }
        if(root->data==value){
            return root;
        }
        if(value>root->data){
            return searchHelper(root->rightChild,value);
        }
        if(value<root->data){
            return searchHelper(root->leftChild,value);
        }
    }
    public:
    void preOrder(){
        preOrderHelper(this->root);
    }
    void inOrder(){
        inOrderHelper(this->root);
    }
    void postOrder(){
        postOrderHelper(this->root);
    }
    RBTNode* minimum(){
        return minimumHelper(this->root);
    }
    RBTNode* maximum(){
        return maximumHelper(this->root);
    }
    RBTNode* search(int value){
        return searchHelper(this->root,value);
    }
    RBTNode* succesor(int k){
        RBTNode *node = search(k);
        if (node == NIL){
            return node;
        }
        if (node->rightChild != NIL){
            return minimumHelper(node->rightChild);
        }
        if (node->parent->leftChild == node){
            return node->parent;
        }
        RBTNode *par = node->parent;
        while (par!=NULL && par->rightChild == node){
            node = par;
            par = node->parent;
        }
        return par;
    }
    RBTNode* predecessor(int k){
        RBTNode *node = search(k);
        if (node == NIL){
            return root;
        }
        if (node->leftChild != NIL){
            return maximumHelper(node->rightChild);
        }
        if (node->parent->rightChild == node){
            return node->parent;
        }
        RBTNode *par = node->parent;
        while (par!=NULL && par->leftChild == node ){
            node = par;
            par = node->parent;
        }
        return par;
    }
    void leftRotate(RBTNode *x){
        RBTNode *y = x->rightChild;
        if(x->leftChild != NIL){
            y->leftChild->parent = x;
        }
        y->parent = x->parent;
        if(x->parent==NULL){
            this->root=y;
        }
        else if(x==x->parent->leftChild){
            x->parent->leftChild = y;
        }
        else{
            x->parent->rightChild = y;
        }
    }

};
