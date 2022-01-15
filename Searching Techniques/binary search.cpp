#include<bits/stdc++.h>
using namespace std; 
int binarysearch(int arr[], int l, int r, int x){
    if (r >= l) {
        int mid =l + (r-1) / 2;
 
        // If the element is present at the middle
        // itself
        if (arr[mid] == x)
            return mid;
 
        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (arr[mid] > x)
            return binarysearch(arr, l, mid - 1, x);
 
        // Else the element can only be present
        // in right subarray
        return binarysearch(arr, mid + 1, r, x);
    }
 
    // We reach here when element is not
    // present in array
    return -1;
}
int main()
{   
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int size;
    cin>>size;
     int array[size];
    for(int i=0; i<size; i++){
        cin>>array[i];
    }
    int n;
    cin>>n;
    cout<<binarysearch(array,0,size-1,n);

    return 0;
}
