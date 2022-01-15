#include<bits/stdc++.h>
using namespace std;
void mergesort(int arr[], int size){
    if(size==0 || size==1)
    return;
    mergesort(arr,size/2);
    mergesort(arr+size/2,size-size/2);
    int newarr[size];
    int x=0;
    int i=0,j=size/2;; 
    while(i<size/2 &&  j<size){
    
            if(arr[i]>arr[j]){
                newarr[x++]=arr[j++];
            }
            else{
                newarr[x++] = arr[i++];
            }
        }
    for (int i = 0; i < size ; i++){
        arr[i] = newarr[i];
    
    }
}
int main(){
 #ifndef ONLINE_JUDGE
    freopen("inputf.in","r",stdin);
    freopen("outputf.in","w",stdout);
 #endif
 int arr[10];
 for(int i=0; i<10; i++){
    cin>>arr[i];
 }
 mergesort(arr,10);
 for (int i = 0; i < 10; i++){
     cout<< arr[i]<<" ";
 }
}
