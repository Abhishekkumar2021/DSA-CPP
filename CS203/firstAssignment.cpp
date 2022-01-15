#include <bits/stdc++.h>
using namespace std;
class BST
{
public:
    int data;
    BST *leftChild;
    BST *rightChild;
    BST *parent;
    BST(int data)
    {
        this->data = data;
        leftChild = NULL;
        rightChild = NULL;
        parent = NULL;
    }
    ~BST()
    {
        delete leftChild;
        delete rightChild;
    }
};

int height(BST *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int max = (height(root->leftChild) > height(root->rightChild)) ? height(root->leftChild) : height(root->rightChild);
    return 1 + max;
}
BST *insert(BST *root, int data)
{
    if (root == NULL)
    {
        root = new BST(data);
        return root;
    }
    if (root->data > data)
    {
        root->leftChild = insert(root->leftChild, data);
        root->leftChild->parent = root;
    }
    if (root->data <= data)
    {
        root->rightChild = insert(root->rightChild, data);
        root->rightChild->parent = root;
    }
    return root;
}

BST *addressof(BST *root, int data)
{
    if (root == NULL)
    {
        return root;
    }
    if (data == root->data)
    {
        return root;
    }
    if (data < root->data)
    {
        return addressof(root->leftChild, data);
    }
    if (data > root->data)
    {
        return addressof(root->rightChild, data);
    }
}

int numNodes(BST *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftNodes = numNodes(root->leftChild);
    int rightNodes = numNodes(root->rightChild);
    return 1 + leftNodes + rightNodes;
}

BST *lowestCommonAncestor(BST *root, int a, int b)
{
    if (root == NULL)
        return NULL;
    int large = (a > b) ? a : b;
    int small = (a < b) ? a : b;
    if (small <= root->data && large >= root->data)
        return root;
    if (small <= root->data && large <= root->data)
    {
        return lowestCommonAncestor(root->leftChild, a, b);
    }
    if (small >= root->data && large >= root->data)
    {
        return lowestCommonAncestor(root->rightChild, a, b);
    }
    return NULL;
}

int main()
{
    BST *root = NULL;
    int numOfElements;
    cin >> numOfElements;
    for (int i = 0; i < numOfElements; i++)
    {
        int element;
        cin >> element;
        root = insert(root, element);
    }
    int first, second;
    cin >> first;
    cin >> second;
    int subtreeNumber;
    cin >> subtreeNumber;
    int heightOfTree = height(root);
    BST *addressOfSubtreeNode = addressof(root, subtreeNumber);
    int nodeCount = numNodes(addressOfSubtreeNode);
    BST *commonAncestor = lowestCommonAncestor(root, first, second);
    int commonAncestorNumber = commonAncestor->data;
    cout << heightOfTree << " " << commonAncestorNumber << " " << nodeCount << "\n";
    delete root;
}