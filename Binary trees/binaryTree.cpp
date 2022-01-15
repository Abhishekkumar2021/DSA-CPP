#include<bits/stdc++.h>
#include"binaryTree.h"
using namespace std;
int main() {
//   binaryTree<int>* root = new binaryTree<int>(1);
//   binaryTree<int>*node1 = new binaryTree<int>(2);
//   binaryTree<int>*node2 = new binaryTree<int>(3);
//   root->leftChild = node1;
//   root->rightChild = node2;
  int in[]={40,20,50,10,60,30,70};
  int pre[]={10,20,40,50,30,60,70};
  binaryTree<int>* root = createTree();
  // binaryTree<int> *root = buildTree(in,pre,7);  //pending...
  printTree(root);
  cout<<"Number of nodes : "<<countNodes(root);
  cout<<endl;
  // inOrder(root);
  delete root;
  return 0;
}
//20 30 40 -1 -1 50 -1 -1 60 70 -1 -1 80 -1 -1 --- recursion case
//20 30 40 50 60 70 80 -1 -1 -1 -1 -1 -1 -1 -1 