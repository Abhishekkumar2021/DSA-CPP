#include <bits/stdc++.h>
using namespace std;
class PriorityQueue
{
    vector<int> pq;

public:
    bool isEmpty()
    {
        return pq.size() == 0;
    }
    int getSize()
    {
        return pq.size();
    }
    int getMax()
    {
        if (pq.size() == 0)
            return 0; // priority queue is empty
        return pq.front();
    }
    void insert(int data)
    {
        pq.push_back(data);
        int childIndex = pq.size() - 1;
        while (childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2;
            if (pq[parentIndex] < pq[childIndex])
            {
                swap(pq[childIndex], pq[parentIndex]);
                childIndex = parentIndex;
            }
            else
                break;
        }
    }
    int removeMax()
    {
        if (pq.size() == 0)
            return -1;
        int ans = pq.front();
        int lastIndex = pq.size() - 1;
        swap(pq[0], pq[lastIndex]);
        pq.pop_back();
        // down Heapify
        int parentIndex = 0;
        int leftChildIndex = 2 * parentIndex + 1;
        int rightChildIndex = 2 * parentIndex + 2;
        while (leftChildIndex < pq.size())
        {
            int maxIndex = parentIndex;
            if (pq[maxIndex] < pq[leftChildIndex])
                maxIndex = leftChildIndex;
            if (pq[maxIndex] < pq[rightChildIndex] && rightChildIndex < pq.size())
                maxIndex = rightChildIndex;
            if (maxIndex == parentIndex)
                break;
            swap(pq[maxIndex], pq[parentIndex]);
            parentIndex = maxIndex;
            leftChildIndex = 2 * parentIndex + 1;
            rightChildIndex = 2 * parentIndex + 2;
        }
        return ans;
    }
    void replace(int current, int newValue)
    {
        int i;
        for (i = 0; i < pq.size(); i++)
        {
            if (pq[i] == current)
            {
                break;
            }
        }
        pq[i] = newValue;
        // now it may be the case that this value is greater than its parent value. So we have to upHeapify here.
        int childIndex = i;
        while (childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2;
            if (pq[parentIndex] >= pq[childIndex])
                break;
            else
            {
                swap(pq[parentIndex], pq[childIndex]);
                childIndex = parentIndex;
            }
        }
    }
    int getIndex(int num)
    {
        for (int i = 0; i < pq.size(); i++)
        {
            if (pq[i] == num)
                return i;
        }
        return -1;
    }
    void printChilds(int num)
    {
        for (int i = 0; i < this->pq.size(); i++)
        {
            if (this->pq[i] == num)
            {
                if (2 * i + 1 < this->pq.size())
                    cout << "--> Left child: " << this->pq[2 * i + 1] << endl;
                else
                    cout << "--> No left child\n";
                if (2 * i + 2 < this->pq.size())
                    cout << "--> Right child: " << this->pq[2 * i + 2] << endl;
                else
                    cout << "--> No right child\n";
            }
        }
    }
    void print()
    {
        queue<int> pending;
        pending.push(pq[0]);
        while (!pending.empty())
        {
            int front = pending.front();
            pending.pop();
            cout << "Node : " << front << "\n";
            printChilds(front);
            int index = getIndex(front);
            if (2 * index + 1 < this->pq.size())
                pending.push(pq[2 * index + 1]);
            if (2 * index + 2 < this->pq.size())
                pending.push(pq[2 * index + 2]);
        }
    }
};