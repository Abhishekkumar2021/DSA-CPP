#include<bits/stdc++.h>
#include"BST_class.h"
using namespace std;
int main(){
    // BST<int>* root = createTree();
    // printTree(root);
    // printRange(root,10,60);
    // BST<int>* max = maximum(root);
    // cout<<endl;
    // cout<<"Max = "<<max->data<<endl;
    // BST<int> *min = minimum(root);
    // cout << "Min = " << min->data << endl;
    // triplet ans = isBST(root);
    // cout<<"Is BST = " << _isBST(root) << endl;
    // cout<<"Max value = "<<maxValue(root) <<endl;
    // cout<<"Min value = "<<minValue(root) <<endl;
    // int arr[] = {1,2,3,4,5,6,7,8,9,10};
    // BST<int>*newRoot = createBST(arr,0,9);
    // printTree(newRoot);
    // pair<node*, node*> ans = createLinkList(newRoot);  //not working
    // node* head = ans.first;
    // cout<<head->data;
    // delete head;
    // vector<int>* path = getRootToNodePath(newRoot,7);
    // for(int i=0; i<path->size(); i++){
    //     cout<<path->at(i)<<" ";
    // }
    // cout<<endl;

    // delete newRoot;
    BinarySearchTree b;
    // b.takeInput();
    b.insert(5);
    b.insert(6);
    b.insert(7);
    b.insert(8);
    b.insert(9);  
    b.insert(2); 
    b.insert(10);
    b.insert(-1);
    b.print();
    b.deleteElement(7);
    b.print();
    return 0;
}
//40 20 60 10 30 50 70-1 -1 -1 -1 -1 -1 -1 -1 -1