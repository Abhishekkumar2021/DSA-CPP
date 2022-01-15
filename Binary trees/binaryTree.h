#include <bits/stdc++.h>
using namespace std;
template <typename T>
class binaryTree
{
public:
    T data;
    binaryTree *leftChild;
    binaryTree *rightChild;
    binaryTree(T data) : data(data)
    {
        leftChild = NULL;
        rightChild = NULL;
    }
    ~binaryTree()
    {
        delete leftChild;
        delete rightChild;
        cout << data << " Deleted" << endl;
    }
};

void printTreeRecursive(binaryTree<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << "Childs of " << root->data << " are : ";
    if (root->leftChild)
    {
        cout << "Left child : " << root->leftChild->data << " | ";
    }
    else
        cout << "No left child"
             << " | ";
    if (root->rightChild)
    {
        cout << "Right child : " << root->rightChild->data << endl;
    }
    else
        cout << "No right child" << endl;
    printTree(root->leftChild);
    printTree(root->rightChild);
}

void printTree(binaryTree<int> *root)
{
    if (root == NULL)
        return;
    queue<binaryTree<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        binaryTree<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Childs of " << front->data << " are : ";
        if (front->leftChild)
        {
            cout << "Left child : " << front->leftChild->data << " | ";
            pendingNodes.push(front->leftChild);
        }
        else
            cout << "No left child"
                 << " | ";
        if (front->rightChild)
        {
            cout << "Right child : " << front->rightChild->data << endl;
            pendingNodes.push(front->rightChild);
        }
        else
            cout << "No right child" << endl;
    }
}
binaryTree<int> *createTreeRecursive()
{
    cout << "Enter data : ";
    int data;
    cin >> data;
    if (data == -1)
    {
        return NULL;
    }
    binaryTree<int> *root = new binaryTree<int>(data);
    root->leftChild = createTree();
    root->rightChild = createTree();
    return root;
}
int countNodes(binaryTree<int> *root)
{
    if (root == NULL)
        return 0;
    int left = countNodes(root->leftChild);
    int right = countNodes(root->rightChild);
    return left + right + 1;
}

binaryTree<int> *createTree()
{
    cout << "Enter root data : ";
    int rootData;
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    binaryTree<int> *root = new binaryTree<int>(rootData);
    queue<binaryTree<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        binaryTree<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter left child data of " << front->data << " : ";
        int leftChildData;
        cin >> leftChildData;
        if (leftChildData != -1)
        {
            binaryTree<int> *left = new binaryTree<int>(leftChildData);
            front->leftChild = left;
            pendingNodes.push(left);
        }
        cout << "Enter right child data of " << front->data << " : ";
        int rightChildData;
        cin >> rightChildData;
        if (rightChildData != -1)
        {
            binaryTree<int> *right = new binaryTree<int>(rightChildData);
            front->rightChild = right;
            pendingNodes.push(right);
        }
    }
    return root;
}

void inOrder(binaryTree<int> *root)
{
    if (root == NULL)
        return;
    inOrder(root->leftChild);
    cout << root->data << " ";
    inOrder(root->rightChild);
}

binaryTree<int> *buildTreeHelper(int *in, int *pre, int inS, int inE, int prS, int prE)
{
    if (inS > inE)
        return NULL;
    int rootData = pre[prS];
    int rootIndex = 0;
    for (int i = inS; i <= inE; i++)
    {
        if (rootData == in[i])
            rootIndex = i;
        break;
    }
    int linS = inS;
    int linE = rootIndex - 1;
    int lprS = prS + 1;
    int lprE = linE - linS + lprS;
    int rinS = rootIndex + 1;
    int rinE = inE;
    int rprS = lprE + 1;
    int rprE = prE;
    class binaryTree<int> *root = new binaryTree<int>(rootData);
    root->leftChild = buildTreeHelper(pre, in, linS, linE, lprS, lprE);
    root->rightChild = buildTreeHelper(pre, in, rinS, rinE, rprS, rprE);
    return root;
}

binaryTree<int> *buildTree(int *in, int *pre, int size)
{
    return buildTreeHelper(in, pre, 0, size - 1, 0, size - 1);
}

pair<int, int> heightDiameter(binaryTree<int> *root)
{
    if (root = NULL)
    {
        pair<int, int> result;
        result.first = 0;
        result.second = 0;
        return result;
    }
    pair<int, int> resultLeft = heightDiameter(root->leftChild);
    pair<int, int> resultRight = heightDiameter(root->rightChild);
    int height = 1 + max(resultLeft.first, resultRight.first);
    int diameter = max(resultLeft.first + resultRight.first, max(resultLeft.second, resultRight.second));
    pair<int, int> resultFinal;
    resultFinal.first = height;
    resultFinal.second = diameter;
    return resultFinal;
}

void printRange(binaryTree<int> *root, int min, int max)
{
    if (root == NULL)
        return;
    if (root->data >= min && root->data <= max)
        cout << root->data << " ";
    printRange(root->leftChild, min, max);
    printRange(root->rightChild, min, max);
}
int minValue(binaryTree<int> *root)
{
    if (root == NULL)
        return INT_MAX;
    return min(root->data, min(minValue(root->leftChild), minValue(root->rightChild)));
}
int maxValue(binaryTree<int> *root)
{
    if (root == NULL)
        return INT_MIN;
    return max(root->data, max(maxValue(root->leftChild), maxValue(root->rightChild)));
}