#include<bits/stdc++.h>
using namespace std;
class BST{
public:
    int data;
    BST *leftChild;
    BST *rightChild;
    BST *parent;
    BST(int data){
        this->data = data;
        leftChild = NULL;
        rightChild = NULL;
        parent = NULL;
    }
    ~BST(){
        delete leftChild;
        delete rightChild;
        cout<<this->data<<" deleted."<<endl;
    }

};

void preOrder(BST* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->leftChild);
    preOrder(root->rightChild);
}
void inOrder(BST* root){
    if(root==NULL){
        return;
    }
    inOrder(root->leftChild);
    cout<<root->data<<" ";
    inOrder(root->rightChild);
}

void deOrder(BST* root){
    if(root==NULL){
        return;
    }
    deOrder(root->rightChild);
    cout<<root->data<<" ";
    deOrder(root->leftChild);
}

BST* insert(BST* root,int data){
    if(root==NULL){
        root = new BST(data);
        return root;
    }
    if(root->data>=data){
        root->leftChild = insert(root->leftChild,data);
        root->leftChild->parent = root;
    }
    if(root->data<data){
        root->rightChild = insert(root->rightChild,data);
        root->rightChild->parent = root;
    }
    return root;
}

BST* minimum(BST* root){
    if(root==NULL)
    return root;
    if(root->leftChild==NULL)
    return root;
    return minimum(root->leftChild);
}
BST* maximum(BST* root){
    if(root==NULL)
    return root;
    if(root->rightChild==NULL)
    return root;
    return maximum(root->rightChild);
}
bool isPresent(BST* root,int data){
    if(root==NULL){
        return false;
    }
    if(data==root->data){
        return true;
    }
    if(data<root->data){
        return isPresent(root->leftChild,data);
    }
    if(data>root->data){
        return isPresent(root->rightChild,data);
    }
}
void printTree(BST* root){
    if(root==NULL)
    return;
    cout<<root->data<<" : \n";
    if(root->leftChild){
        cout << root->leftChild->data << "\n";
         if(root->rightChild){
            cout << root->rightChild->data << "\n";
         }
        printTree(root->leftChild);
        printTree(root->rightChild);
    }
}
BST* addressof(BST* root,int data){
     if(root==NULL){
        return root;
    }
    if(data==root->data){
        return root;
    }
    if(data<root->data){
        return addressof(root->leftChild,data);
    }
    if(data>root->data){
        return addressof(root->rightChild,data);
    }
}

BST* succesor(BST* root,int data){
    if(root==NULL){
        return root;
    }
    BST *node = addressof(root,data);
    if(node==NULL){
        return NULL;
    }
    if(node->rightChild!=NULL){
       return minimum(node->rightChild);
    }
    if(node->parent->leftChild==node){
        return node->parent;
    }
    BST* par = node->parent;
    while(par!=NULL && par->rightChild == node ){
        node = par;
        par = node->parent;
    }
    return par;
}

BST* predeccesor(BST* root,int data){
    if(root==NULL){
        return root;
    }
    BST *node = addressof(root,data);
    if(node==NULL){
        return NULL;
    }
    if(node->leftChild!=NULL){
       return maximum(node->leftChild);
    }
    if(node->parent->rightChild==node){
        return node->parent;
    }
    BST* par = node->parent;
    while(par!=NULL &&par->leftChild == node){
        node = par ;
        par = node->parent;
    }
    return par;


}
// void inOrderSecond(BST* root){
//     if(root==NULL)
//     return;
//     BST*min = minimum(root);
//     cout<<min->data<<" ";
//     BST *next = succesor(root, min->data);
//      while (next!= NULL){
//         cout<<next->data<<" ";
//         next = succesor(root,next->data);
//     }
// }