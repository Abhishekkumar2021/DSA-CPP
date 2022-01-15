#include<bits/stdc++.h>
using namespace std;

int binarySearch(int *array,int left,int right,int value) {
	//assumption : array should be sorted in ascending order.
	if(left>right) 
		return -1;
	int mid = (left + right)/2;
	if(array[mid]==value) 
		return mid;
	if (array[mid]<value) 
		return binarySearch(array,mid+1,right,value);
	else 
		return binarySearch(array,left,mid-1,value);

}
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int array[100];
	int size;
	cin>>size;
	for(int i=0; i<size; i++)
		cin>>array[i];
	cout<<binarySearch(array,0,11,70);
}


