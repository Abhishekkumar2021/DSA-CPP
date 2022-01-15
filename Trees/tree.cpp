#include<bits/stdc++.h>
#include"tree.h"
using namespace std;

int main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    treeNode<int> *root;
    root = createTree();
    // printTree(root);
    // cout<<"Number of nodes in the tree = "<<numNodes(root)<<endl;
    // cout<<"The height of the tree = "<<height(root)<<endl;
    // printAtLevel_K(root,1);
    // cout<<endl;
    // cout<<"Number of leaf nodes in the tree = "<<numOfLeafNodes(root);
    preOrder(root);
    cout<<endl;
    postOrder(root);
    // deleteTree(root);
    delete root;

}

//input : 10 3 20 30 40 2 50 60 2 70 80 2 90 100 1 110 1 120 1 130 1 140 1 150 1 160 0 0 0 0 0 0 