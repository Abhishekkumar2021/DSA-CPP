#include <bits/stdc++.h>
#include "MaxHeap.h"
using namespace std;
int main()
{
    PriorityQueue pq;
    for (int i = 1; i <= 7; i++)
    {
        pq.insert(i);
    }
    pq.print();
    pq.replace(3, 10);
    cout << "-------After replacing----" << endl;
    pq.print();

    // heap sort
    //  PriorityQueue sort;
    //  int arr[] = {10,9,8,7,6,6,6,6,6,5,4,3,2,1};
    //  //first insertion
    //  for(int i=0; i<14; i++){
    //      sort.insert(arr[i]);
    //  }
    //  for(int i=0; i<14; i++){
    //      cout<<sort.removeMax()<<" ";
    //  }
}

// self implement the Max heap