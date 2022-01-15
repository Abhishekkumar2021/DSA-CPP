#include <bits/stdc++.h>
using namespace std;
class CBT
{
    vector<int> data;

public:
    int getIndex(int num)
    {
        for (int i = 0; i < data.size(); i++)
        {
            if (data[i] == num)
                return i;
        }
        return -1;
    }
    int getLeftChild(int num)
    {
        int index = getIndex(num);
        if (index != -1)
        {
            if (2 * index + 1 < this->data.size())
                return data[2 * index + 1];
        }
        return NULL;
    }
    int getRightChild(int num)
    {
        int index = getIndex(num);
        if (index != -1)
        {
            if (2 * index + 2 < this->data.size())
                return data[2 * index + 2];
        }
        return NULL;
    }
    void printChilds(int num)
    {
        for (int i = 0; i < this->data.size(); i++)
        {
            if (this->data[i] == num)
            {
                if (2 * i + 1 < this->data.size())
                    cout << "--> Left child: " << this->data[2 * i + 1] << endl;
                else
                    cout << "--> No left child\n";
                if (2 * i + 2 < this->data.size())
                    cout << "--> Right child: " << this->data[2 * i + 2] << endl;
                else
                    cout << "--> No right child\n";
            }
        }
    }
    void printParent(int data)
    {
        for (int i = 0; i < this->data.size(); i++)
        {
            if (this->data[0] == data)
            {
                cout << "It is root so no parent" << endl;
                return;
            }
            if (this->data[i] == data)
            {
                if ((i - 1) / 2 >= 0)
                    cout << "Parent: " << this->data[(i - 1) / 2] << endl;
                return;
            }
        }
    }
    void insert(int data)
    {
        this->data.push_back(data);
    }
    void Delete(int data)
    {
        for (int i = 0; i < this->data.size(); i++)
        {
            if (this->data[i] == data)
            {
                this->data.erase(this->data.begin() + i);
                return;
            }
        }
    }
    void print()
    {
        queue<int> pending;
        pending.push(data[0]);
        while (!pending.empty())
        {
            int front = pending.front();
            pending.pop();
            cout << "Node : " << front << "\n";
            printChilds(front);
            int index = getIndex(front);
            if (2 * index + 1 < this->data.size())
                pending.push(data[2 * index + 1]);
            if (2 * index + 2 < this->data.size())
                pending.push(data[2 * index + 2]);
        }
    }
};

int main()
{
    CBT cbt;
    for (int i = 1; i <= 3; i++)
    {
        cbt.insert(i);
    }
    // cbt.printParent(2);

    cbt.print();
    return 0;
}