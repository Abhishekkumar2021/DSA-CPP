#include <bits/stdc++.h>
#include "linkedList.h"
using namespace std;
int main()
{
    linkedList list;
    list.addValues(3); // taking input as 30 40 50
    list.print();
    list.insertAtBeg(10);
    list.insertAtBeg(20);
    list.insertAtEnd(60);
    list.insertAtEnd(70);
    list.print();
    list.insert(80, 2);
    list.print();
    list.removeFromBeg();
    list.removeFromBeg();
    list.print();
    list.removeFromEnd();
    list.removeFromEnd();
    list.remove(1);
    list.print();
    list.mergeSort();
    list.print();
    cout << list.midElement();
}