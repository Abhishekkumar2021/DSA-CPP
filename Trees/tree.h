#include <bits/stdc++.h>
using namespace std;
template <typename T>
class treeNode
{
public:
    T data;
    vector<treeNode *> children;
    treeNode(T data)
    {
        this->data = data;
    }
    // ~treeNode(){
    //     cout<<data<<" Deleted"<<endl;
    // }
    ~treeNode()
    {
        for (int i = 0; i < children.size(); i++)
            delete children[i];
        cout << data << " Deleted" << endl;
    }
};
void printTreeRecursive(treeNode<int> *root)
{
    if (root == NULL)
        return; // this is not a base case it is an edge case which will run only at max one time i.e at the starting time only.
    cout << "Childrens of " << root->data << " are : " << endl;
    for (int i = 0; i < root->children.size(); i++)
    {
        cout << i + 1 << ". " << root->children[i]->data << endl;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        printTreeRecursive(root->children[i]);
    }
}

treeNode<int> *createTreeRecursive()
{
    cout << "Enter a tree node : ";
    int rootData;
    cin >> rootData;
    treeNode<int> *root = new treeNode<int>(rootData);
    cout << "Enter number of childrens of " << root->data << " : ";
    int number;
    cin >> number;
    for (int i = 0; i < number; i++)
    {
        cout << "Enter child " << i + 1 << " of " << root->data << " : ";
        int data;
        cin >> data;
        treeNode<int> *child = new treeNode<int>(data);
        root->children.push_back(child);
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        root->children[i] = createTreeRecursive();
    }
}

treeNode<int> *createTree()
{
    cout << "Enter root data : ";
    int rootData;
    cin >> rootData;
    treeNode<int> *root = new treeNode<int>(rootData);
    queue<treeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        treeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter number of childrens of " << front->data << " : ";
        int numberOfChildren;
        cin >> numberOfChildren;
        for (int i = 0; i < numberOfChildren; i++)
        {
            cout << "Enter child " << i + 1 << " of " << front->data << " : ";
            int data;
            cin >> data;
            treeNode<int> *child = new treeNode<int>(data);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

void printTree(treeNode<int> *root)
{
    if (root == NULL)
        return;
    queue<treeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        treeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Childrens of " << front->data << " are : " << endl;
        int count = 0;
        for (int i = 0; i < front->children.size(); i++)
        {
            cout << i + 1 << ". " << front->children[i]->data << endl;
            pendingNodes.push(front->children[i]);
            count++;
        }
        if (count == 0)
            cout << "No children !" << endl;
    }
}

int numNodes(treeNode<int> *root)
{
    if (root == NULL)
        return -1;
    int count = 0;
    for (int i = 0; i < root->children.size(); i++)
    {
        count += numNodes(root->children[i]);
    }
    return count + 1;
}

int height(treeNode<int> *root)
{
    if (root == NULL)
        return -1;
    int maxHeight = 0;
    for (int i = 0; i < root->children.size(); i++)
    {
        maxHeight = max(maxHeight, height(root->children[i]));
    }
    return maxHeight + 1;
}

void printAtLevel_K(treeNode<int> *root, int k)
{
    if (root == NULL)
        return; // not a base case, this is an edge case.
    if (k == 0)
    {
        cout << root->data << " ";
        return;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        printAtLevel_K(root->children[i], k - 1);
    }
}

int numOfLeafNodes(treeNode<int> *root)
{
    if (root->children.size() == 0)
        return 1;
    int count = 0;
    for (int i = 0; i < root->children.size(); i++)
    {
        count += numOfLeafNodes(root->children[i]);
    }
    return count;
}

void preOrder(treeNode<int> *root)
{
    cout << root->data << " ";
    for (int i = 0; i < root->children.size(); i++)
    {
        preOrder(root->children[i]);
    }
}
void postOrder(treeNode<int> *root)
{
    for (int i = 0; i < root->children.size(); i++)
    {
        postOrder(root->children[i]);
    }
    cout << root->data << " ";
}

void deleteTree(treeNode<int> *root)
{
    for (int i = 0; i < root->children.size(); i++)
    {
        deleteTree(root->children[i]);
    }
    delete root;
}

/////////////////////////////////////////////////////////////////////////////////////////////
// TreeNode<int>* takeInput_better(){
// 	int RootData ;
// 	cout<<"Enter Root Data : ";
// 	cin>>RootData;
// 	TreeNode<int> *root = new TreeNode<int>(RootData);
// 	queue<TreeNode<int>*> pendingNodes;
// 	pendingNodes.push(root);
// 	while(pendingNodes.size()!=0){
// 		TreeNode<int> *front =  pendingNodes.front();
// 		pendingNodes.pop();
// 		cout<<"Enter the number of childrens you want to have for "<<front->data<<" : ";
// 		int n;
// 		cin>>n;
// 		for(int i=0; i<n; i++){
// 			int childData;
// 			cout<<"Enter the child number -> "<<i+1<<" of "<<front->data<<" : ";
// 			cin>>childData;
// 			TreeNode<int> *child = new TreeNode<int>(childData);
// 			front->children.push_back(child);
// 			pendingNodes.push(child);
// 		}
// 	}
// 	return root;

// }

// void print_better(TreeNode<int> *root){
// 	queue<TreeNode<int>*> pendingNodes;
// 	pendingNodes.push(root);
// 	while(pendingNodes.size()!=0){
// 		TreeNode<int> *front =  pendingNodes.front();
// 		pendingNodes.pop();
// 		cout<<front->data<<" : ";
// 		for(int i=0; i<front->children.size(); i++){
// 			cout<<front->children[i]->data<<" ";
// 			pendingNodes.push(front->children[i]);

// 		}
// 		cout<<"\n";
// 	}
// }

// TreeNode<int>* takeInput(){
// 	int RootData ;
// 	cout<<"Enter Data : ";
// 	cin>>RootData;
// 	TreeNode<int> *root = new TreeNode<int>(RootData);
// 	int n;
// 	cout<<"Enter the number of childrens you want to have for "<<RootData<<" :"<<endl;
// 	cin>>n;
// 	for(int i=0; i<n; i++){
// 		TreeNode<int> *child = takeInput();
// 		root->children.push_back(child);
// 	}
// 	return root;
// }

// void printTree(TreeNode<int>* root){
// 	if(root == NULL){
// 		return;
// 	}
// 	cout<<root->data<<" : " ;
// 	for(int i=0; i<root->children.size(); i++){
// 		cout<<root->children[i]->data<<" ";
// 	}
// 	cout<<endl;
// 	for(int i=0; i<root->children.size(); i++){
// 		printTree(root->children[i]);
// 	}
// }

// int numNodes(TreeNode<int> * root){
// 	int ans = 1;
// 	for(int i=0; i<root->children.size(); i++){
// 		ans+=numNodes(root->children[i]);
// 	}
// 	return ans;
// }

// void printLevel_K(TreeNode<int> * root,int level){
// 	if(level == 1){
// 		cout<< root->data<<" ";
// 	}
// 	for(int i=0; i<root->children.size(); i++){
//        printLevel_K(root->children[i],level-1);
// 	}
// }

// int height_tree(TreeNode<int> * root){
// 	int max = 0;
// 	int *arr = new int[root->children.size()];
// 	for(int i=0; i<root->children.size(); i++){
//        arr[i] = height_tree(root->children[i]);
//        if(arr[i]>max)
//        	max = arr[i];
// 	}
// 	return max+1;
// }

// int num_leafnode(TreeNode<int> * root){

// 	if(root->children.size() == 0)
// 		return 1;
// 	int sum = 0;
// 	for(int i=0; i<root->children.size(); i++){
// 		sum+=num_leafnode(root->children[i]);
// 	}
// 	return sum;

// }
