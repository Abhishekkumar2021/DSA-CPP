#include <bits/stdc++.h>
using namespace std;

vector<int> getLeaves(vector<int> &heap)
{
    vector<int> leaves;
    for (int i = (heap.size() + 1) / 2; i < heap.size(); i++)
    {
        leaves.push_back(heap[i]);
    }
    return leaves;
}
// this function is usedto make the heap subrooted at i a max heap .It assumes that both the heaps having left and rightof i as
// their root are already max heap.
void maxHeapify(vector<int> &heap, int i)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;
    if (left < heap.size() && heap[largest] < heap[left])
        largest = left;
    if (right < heap.size() && heap[largest] < heap[right])
        largest = right;
    if (largest != i)
    {
        swap(heap[largest], heap[i]);
        maxHeapify(heap, largest);
    }
}
// this function is usedto make the heap subrooted at i a max heap .It assumes that both the heaps having left and rightof i as
// their root are already min heap.
void minHeapify(vector<int> &heap, int i)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int smallest = i;
    if (left < heap.size() && heap[smallest] > heap[left])
        smallest = left;
    if (right < heap.size() && heap[smallest] > heap[right])
        smallest = right;
    if (smallest != i)
    {
        swap(heap[smallest], heap[i]);
        minHeapify(heap, smallest);
    }
}

void maxHeapify_iterative(vector<int> &heap, int i)
{
    while (1)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;
        if (left < heap.size() && heap[largest] < heap[left])
            largest = left;
        if (right < heap.size() && heap[largest] < heap[right])
            largest = right;
        if (largest != i)
        {
            swap(heap[largest], heap[i]);
            i = largest;
        }
        else
            return;
    }
}
void buildMaxHeap(vector<int> &heap)
{
    for (int i = heap.size() / 2; i >= 0; i--)
    {
        maxHeapify(heap, i);
    }
}

void printHeap(vector<int> &heap)
{
    for (auto element : heap)
        cout
            << element << " ";
}
void heapSort(vector<int> &heap)
{
    buildMaxHeap(heap);
    vector<int> arr = heap;
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        heap[i] = arr[0];
        swap(arr[i], arr[0]);
        arr.pop_back();
        maxHeapify(arr, 0);
        // cout << "for i = " << i << ": \n";
        // cout << "Heap: ";
        // printHeap(heap);
        // cout << endl;
        // cout << "arr: ";
        // printHeap(arr);
        // cout << endl;
    }
}
