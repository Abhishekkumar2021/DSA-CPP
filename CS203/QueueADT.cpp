#include <bits/stdc++.h>
#include "Array_as_ADT_template.h"
#include"Queue_as_ADT_template.h"
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    QueueADT<int> queue;
    queue.createNewQueue(5);
    cout<<queue.isEmpty()<<endl;
    queue.Delete();
    queue.Add(2);
    queue.Delete() ;
    queue.Delete() ;
    queue.Delete() ;
    queue.Delete() ;
}