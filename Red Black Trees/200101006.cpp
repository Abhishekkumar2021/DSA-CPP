#include <iostream>
using namespace std;
class node{
    public:
    int data;
    node *parent;
    char color;
    node *leftChild;
    node *rightChild;
    node(int data){
        this->data = data;
        this->leftChild = NULL;
        this->rightChild = NULL;
        this->color = 'r';
    }
};

class RBT{
    node *root;
    node *p;
public:
    RBT(){
        p = NULL;
        root = NULL;
    }
    void rightrotate(node *p){
        if (p->leftChild == NULL)
            return;
        else{
            node *y = p->leftChild;
            if (y->rightChild != NULL){
                p->leftChild = y->rightChild;
                y->rightChild->parent = p;
            }
            else
                p->leftChild = NULL;
            if (p->parent != NULL)
                y->parent = p->parent;
            if (p->parent == NULL)
                root = y;
            else{
                if (p == p->parent->leftChild)
                    p->parent->leftChild = y;
                else
                    p->parent->rightChild = y;
            }
            y->rightChild = p;
            p->parent = y;
        }
    }
    void leftrotate(node *p){
        if (p->rightChild == NULL)
            return;
        else{
            node *y = p->rightChild;
            if (y->leftChild != NULL){
                p->rightChild = y->leftChild;
                y->leftChild->parent = p;
            }
            else
                p->rightChild = NULL;
            if (p->parent != NULL)
                y->parent = p->parent;
            if (p->parent == NULL)
                root = y;
            else{
                if (p == p->parent->leftChild)
                    p->parent->leftChild = y;
                else
                    p->parent->rightChild = y;
            }
            y->leftChild = p;
            p->parent = y;
        }
    }
    void fixTreeAfterInsertion(node *t){
        node *u;
        if (root == t){
            t->color = 'b';
            return;
        }
        while (t->parent != NULL && t->parent->color == 'r'){
            node *g = t->parent->parent;
            if (g->leftChild == t->parent){
                if (g->rightChild != NULL){
                    u = g->rightChild;
                    if (u->color == 'r')
                    {
                        t->parent->color = 'b';
                        u->color = 'b';
                        g->color = 'r';
                        t = g;
                    }
                }
                else{
                    if (t->parent->rightChild == t)
                    {
                        t = t->parent;
                        leftrotate(t);
                    }
                    t->parent->color = 'b';
                    g->color = 'r';
                    rightrotate(g);
                }
            }
            else{
                if (g->leftChild != NULL){
                    u = g->leftChild;
                    if (u->color == 'r'){
                        t->parent->color = 'b';
                        u->color = 'b';
                        g->color = 'r';
                        t = g;
                    }
                }
                else{
                    if (t->parent->leftChild == t){
                        t = t->parent;
                        rightrotate(t);
                    }
                    t->parent->color = 'b';
                    g->color = 'r';
                    leftrotate(g);
                }
            }
            root->color = 'b';
        }
    }
    void insert(int data){
        int i = 0;
        node *p, *q;
        node *t = new node(data);
        p = root;
        q = NULL;
        if (root == NULL){
            root = t;
            t->parent = NULL;
        }
        else{
            while (p != NULL){
                q = p;
                if (p->data < t->data)
                    p = p->rightChild;
                else
                    p = p->leftChild;
            }
            t->parent = q;
            if (q->data < t->data)
                q->rightChild = t;
            else
                q->leftChild = t;
        }
        fixTreeAfterInsertion(t);
    }
    void preOrderHelper(node *root,int n){
        if (root == NULL)
            return;
            if(n == 0){
                cout<<root->data<<"\n";
            }else{
                cout << root->data << " ";
            }
        preOrderHelper(root->leftChild,n-1);
        preOrderHelper(root->rightChild,n-2);
    }
    void preOrder(int n){
        preOrderHelper(root,n);
    }
};



int main(){
    RBT tree;
    int numOfElements;
    cin >> numOfElements;
    for (int i = 0; i < numOfElements; i++)
    {
        int element;
        cin >> element;
        tree.insert(element);
    }
    tree.preOrder(numOfElements);
}