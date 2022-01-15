#include<bits/stdc++.h>
using namespace std;
int main(){
	int arr[] = {1,2,3,4,5,6,7,8,9,0,-10,-4};
	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int inversionsInBubbleSort = 0;
    for(int i=0; i<12; i++){
    	for(int j=0; j<12-i; j++){
    		if(arr[j]>arr[j+1]){
    			swap(arr[j],arr[j+1]);
    			inversionsInBubbleSort++;
    		}
    	}
    }
    for(int i=0; i<12; i++)
    	cout<<arr[i]<<" ";
    cout<<"\nNo of inversions  = "<<inversionsInBubbleSort;
}