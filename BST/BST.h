#include <bits/stdc++.h>
using namespace std;
template <typename T>
class BST
{
public:
    T data;
    BST *left;
    BST *right;
    BST(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~BST()
    {
        delete left;
        delete right;
        cout << data << " Deleted" << endl;
    }
};

BST<int> *search(BST<int> *root, int data)
{
    if (root == NULL)
        return NULL;
    if (data = root->data)
        return root;
    if (data > root->data)
        return search(root->right, data);
    return search(root->right, data);
}

void printRange(BST<int> *root, int min, int max)
{
    if (root == NULL)
        return;
    if (root->data >= min && root->data <= max)
        cout << root->data << " ";
    printRange(root->left, min, max);
    printRange(root->right, min, max);
} // print not in order
void printRange(BST<int> *root, int min, int max)
{
    if (root == NULL)
        return;
    if (root->data > min)
        printRange(root->left, min, max);
    if (root->data >= min && root->data <= max)
        cout << root->data << " ";
    printRange(root->right, min, max);
} // prints in order

void printTree(BST<int> *root)
{
    if (root == NULL)
        return;
    queue<BST<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        BST<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Childs of " << front->data << " are : ";
        if (front->left)
        {
            cout << "Left child : " << front->left->data << " | ";
            pendingNodes.push(front->left);
        }
        else
            cout << "No left child"
                 << " | ";
        if (front->right)
        {
            cout << "Right child : " << front->right->data << endl;
            pendingNodes.push(front->right);
        }
        else
            cout << "No right child" << endl;
    }
}
BST<int> *createTree()
{
    cout << "Enter root data : ";
    int rootData;
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    BST<int> *root = new BST<int>(rootData);
    queue<BST<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        BST<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter left child data of " << front->data << " and it should be less than or equal to " << front->data << " : ";
        int leftChildData;
        cin >> leftChildData;
        if (leftChildData != -1)
        {
            BST<int> *left = new BST<int>(leftChildData);
            front->left = left;
            pendingNodes.push(left);
        }
        cout << "Enter right child data of " << front->data << " and it should be greater than or equal to " << front->data << " : ";
        int rightChildData;
        cin >> rightChildData;
        if (rightChildData != -1)
        {
            BST<int> *right = new BST<int>(rightChildData);
            front->right = right;
            pendingNodes.push(right);
        }
    }
    return root;
}

BST<int> *maximum(BST<int> *root)
{
    if (root == NULL)
        return root;
    if (root->right == NULL)
        return root;
    return maximum(root->right);
}

BST<int> *minimum(BST<int> *root)
{
    if (root == NULL)
        return root;        // ege case
    if (root->left == NULL) // base case
        return root;
    return minimum(root->left);
}
int minValue(BST<int> *root)
{
    if (root == NULL)
        return INT_MAX;
    return min(root->data, min(minValue(root->left), minValue(root->right)));
}
int maxValue(BST<int> *root)
{
    if (root == NULL)
    {
        return INT_MIN;
    }
    return max(root->data, max(maxValue(root->left), maxValue(root->right)));
}

class triplet
{
public:
    int max;
    int min;
    bool isBST;
};

triplet isBST(BST<int> *root)
{
    if (root == NULL)
    {
        triplet ans;
        ans.min = INT_MAX;
        ans.max = INT_MIN;
        ans.isBST = true;
        return ans;
    }
    triplet leftOutput = isBST(root->left);
    triplet rightOutput = isBST(root->right);
    int overallMin = min(min(leftOutput.min, rightOutput.min), root->data);
    int overallMax = max(max(leftOutput.max, rightOutput.max), root->data);
    bool overallBST = leftOutput.isBST && rightOutput.isBST && (leftOutput.max <= root->data && rightOutput.min >= root->data);
    triplet finalAnswer;
    finalAnswer.min = overallMin;
    finalAnswer.max = overallMax;
    finalAnswer.isBST = overallBST;
    return finalAnswer;
}

// top to bottom approach
bool _isBST(BST<int> *root, int minimum = INT_MIN, int maximum = INT_MAX)
{
    if (root == NULL)
    {
        return true;
    }
    if (root->data < minimum || root->data > maximum)
        return false;
    bool isLeftOK = _isBST(root->left, minimum, root->data);
    bool isRightOK = _isBST(root->right, root->data, maximum);
    return isLeftOK && isRightOK;
}

BST<int> *createBST(int *arr, int left, int right)
{
    if (left > right)
        return NULL;
    int mid = (left + right) / 2;
    BST<int> *root = new BST<int>(arr[mid]);
    root->left = createBST(arr, left, mid - 1);
    root->right = createBST(arr, mid + 1, right);
}

class node
{
public:
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        next = NULL;
    }
    ~node()
    {
        delete next;
        cout << "Deleted " << data << endl;
    }
};

pair<node *, node *> createLinkList(BST<int> *root)
{
    if (root = NULL)
    {
        pair<node *, node *> ans;
        ans.first = NULL;
        ans.second = NULL;
        return ans;
    }
    node *mid = new node(root->data);
    pair<node *, node *> leftAns;
    pair<node *, node *> rightAns;
    leftAns.first = NULL;
    leftAns.second = NULL;
    rightAns.first = NULL;
    rightAns.second = NULL;
    if (root->left != NULL)
    {
        leftAns = createLinkList(root->left);
        leftAns.second->next = mid;
    }
    if (root->right != NULL)
    {
        rightAns = createLinkList(root->right);
        mid->next = rightAns.first;
    }

    pair<node *, node *> finalAnswer;
    finalAnswer.first = leftAns.first;
    finalAnswer.second = rightAns.second;
    return finalAnswer;
}

vector<int> *getRootToNodePath(BST<int> *root, int data)
{
    if (root == NULL)
        return NULL;
    if (root->data == data)
    {
        vector<int> *output = new vector<int>();
        output->push_back(root->data);
        return output;
    }
    vector<int> *leftOutput = getRootToNodePath(root->left, data);
    if (leftOutput != NULL)
    {
        leftOutput->push_back(root->data);
        return leftOutput;
    }
    vector<int> *rightOutput = getRootToNodePath(root->right, data);
    if (rightOutput != NULL)
    {
        rightOutput->push_back(root->data);
        return rightOutput;
    }
    return NULL;
}
bool hasData(int data, BST<int> *root)
{
    if (root == NULL)
        return false;
    if (data == root->data)
        return true;
    if (data > root->data)
    {
        return hasData(data, root->right);
    }
    else
    {
        return hasData(data, root->left);
    }
}
BST<int> *insertElement(BST<int> *root, int data)
{
    if (root == NULL)
    {
        BST<int> *node = new BST<int>(data);
        root = node;
        return root;
    }
    if (root->data <= data)
    {
        root->right = insertElement(root->right, data);
        return root;
    }
    else
    {
        root->left = insertElement(root->left, data);
        return root;
    }
}

BST<int> *Delete(BST<int> *root, int data)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data < data)
    {
        root->right = Delete(root->right, data);
        return root;
    }
    else if (data < root->data)
    {
        root->left = Delete(root->left, data);
        return root;
    }
    else if (root->data == data)
    {
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        else if (root->right == NULL && root->left != NULL)
        {
            BST<int> *left = root->left;
            root->left == NULL;
            delete root;
            return left;
        }
        else if (root->right != NULL && root->left == NULL)
        {
            BST<int> *right = root->right;
            root->right = NULL;
            delete root;
            return right;
        }
        else
        {
            root->data = minValue(root->right);
            root->right = Delete(root->right, root->data);
            return root;
        }
    }
}

// BST<int>* makeAVL(BST<int>* root){
//     if(root==NULL)
//     return NULL;
//     if()
// }
