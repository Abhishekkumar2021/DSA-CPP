#include<bits/stdc++.h>
using namespace std;
bool sortedcheck(int a[],int n){
	if(n==0 || n==1){
		return true;
	}
	if(a[0]>a[1]){
		return false;
	}
	bool x = sortedcheck(a+1,n-1);
	return x;
}
int main(){
	int arr[10];
	for(int i=0; i<10; i++){
		cin>>arr[i];
	}
    cout<<sortedcheck(arr,10);
    return 0;
}