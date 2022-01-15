#include<bits/stdc++.h>
using namespace std; 
void bubblesort(int arr[],int size){
    for(int i=0;i<size-1;i++){
      for(int j=0;j<size-i-1;j++){
         if(arr[j]>arr[j+1]){
            int temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
         }
      }
    }
    for(int i=0;i<size; i++)
        cout<<arr[i]<<" ";
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
    bubblesort(array,size);
    return 0;
}
