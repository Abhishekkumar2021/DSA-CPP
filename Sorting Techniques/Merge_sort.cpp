#include <iostream>
using namespace std;

void mergesort(int arr[],int l,int r){
if(l>=r)
    return;
int mid = (l+r)/2;
mergesort(arr,l,mid);
mergesort(arr,mid+1,r);
int left = mid-l+1;
int right = r-mid;
int L[left],R[right];
for(int i=0; i<left; i++)
    L[i]=arr[i+l];
for(int i=0; i<right; i++)
    R[i]=arr[l+left+i];
int i=0, j=0,x=0;
while(i<left && j<right){

    if(L[i]<=R[j]){
     arr[l+x]=L[i];
     i++;

    }
    else{
     arr[l+x]=R[j];
     j++;

    }
     x++;
  }
  while(i<left){
    arr[l+x]=L[i];
     i++;
     x++;
  }
  while(j<right){
    arr[l+x]=R[j];
     j++;
     x++;
  }

}
int main()
{   
    
    int size;
    cin>>size;
     int array[size];
    for(int i=0; i<size; i++){
        array[i]=size-i;
    }
    mergesort(array,3,7);
    for(int i=0; i<size; i++){
        cout<<array[i]<<" ";
    }
    return 0;
}
