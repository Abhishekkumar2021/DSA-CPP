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
    int getMin()
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
            if (pq[parentIndex] > pq[childIndex])
            {
                swap(pq[childIndex], pq[parentIndex]);
            }
            else
                break;
            childIndex = parentIndex;
        }
    }
    int removeMin()
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
            int minIndex = parentIndex;
            if (pq[minIndex] > pq[leftChildIndex])
                minIndex = leftChildIndex;
            if (pq[minIndex] > pq[rightChildIndex] && rightChildIndex < pq.size())
                minIndex = rightChildIndex;
            if (minIndex == parentIndex)
                break;
            swap(pq[minIndex], pq[parentIndex]);
            parentIndex = minIndex;
            leftChildIndex = 2 * parentIndex + 1;
            rightChildIndex = 2 * parentIndex + 2;
        }
        return ans;
    }
};