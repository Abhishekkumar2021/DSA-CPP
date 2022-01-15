#include <bits/stdc++.h>
#include "Heaps.h"
using namespace std;
int main()
{
    vector<int> heap = {27, 17, 3, 16, 13, 10, 1, 5, 7, 12, 4, 8, 9, 0};
    // maxHeapify_iterative(heap, 2);
    // buildMaxHeap(heap);
    heapSort(heap);
    // for (auto element : heap)
    //     cout
    //         << element << " ";
    // cout << endl;

    // vector<int> leaves = getLeaves(heap);
    // for (auto leaf : leaves)
    // {
    //     cout << leaf << " ";
    // }
}