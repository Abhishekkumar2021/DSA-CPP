#include<bits/stdc++.h>
using namespace std; 

void shift(int arr[], int target, int min){
    int minimum = arr[min];
    for(int i=min; i>target; i--){
        arr[i] = arr[i-1];
    }
    arr[target] = minimum;
}
void selectionsort(int arr[],int size){
 
	for(int i=0; i<size; i++){
		 int minindex=i;
        for(int j=i+1; j<size; j++){
            if(arr[j]<arr[minindex])
            	minindex=j;
        }
        // int temp =  arr[minindex];
        // arr[minindex] = arr[i];
        // arr[i] = temp;
        shift(arr,i,minindex);
	} 
}
int main(){   
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int size;
    cin>>size;
     int array[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 23, 24};
    // for(int i=0; i<size; i++){
    //     array[i]=size-i;
    //  }
    selectionsort(array,13);
    for(int i=0; i<13; i++){
        cout<<array[i]<<" ";
    }
    return 0;
}
