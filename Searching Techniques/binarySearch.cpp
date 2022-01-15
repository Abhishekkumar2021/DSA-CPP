#include<iostream>
using namespace std;
int binarysearch(int arr[],int left,int right,int search){
	int mid = (left+right)/2;
	if(arr[mid] == search) return mid;
	int ans;
	if(arr[mid] < search)
		 ans = binarysearch(arr,mid+1,right,search);
	else 
		 ans = binarysearch(arr,left,mid,search);
	return ans;
}
int main(){
	int arr[] = {1,2,3,4,5,6,7,8,9,0};
	cout<<binarysearch(arr,0,9,5);
}