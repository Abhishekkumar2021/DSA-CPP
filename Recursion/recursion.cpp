#include<bits/stdc++.h>
using namespace std;
bool check(int a[],int n){
	if(n==0 || n==1){
		return true;
	}
	if(a[0]>a[1]){
		return false;
	}
	bool x = check(a+1,n-1);
	return x;
}
int main(){
	int arr[10];
	for(int i=0; i<10; i++){
		cin>>arr[i];
	}
    cout<<check(arr,10);
    return 0;
}
// checking the first index of a number using recursion.
int firstindex(int arr[],int size,int x){
	if(size == 0)
		return -1;
	if(arr[0]==x){
		return 0;
	}
	int ans = firstindex(arr+1,size-1,x);
    if(ans==-1)
    	return ans;
    else
    	return ans+1;
	

}
int main(){
int arr[10];
	for(int i=0; i<10; i++){
		cin>>arr[i];
	}
    cout<<firstindex(arr,10,6);
}
// checking the last index of a number using recursion.
int lastindex(int A[],int size,int x){
	if(size==0)
		return -1;
	int ans = lastindex(A+1,size-1,x);
	if(ans ==-1){
	    if(x==A[0])
		 return 0;
		else 
		 return -1;
	    }
	 else
		return ans+1;
}
int main(){
int arr[10];
	for(int i=0; i<10; i++){
		cin>>arr[i];
	}
    cout<<lastindex(arr,10,9);
}
int allindex(int A[],int size,int x,int output[]){
	if(size==0)
		return 0;
    int ans=allindex(A+1,size-1,x,output);
    if(ans==0){

    }
}
//finding size of an character array....
int length(char str[]){ 
	if(str[0]=='\0')
		return 0;
	int smallstringlength=length(str+1);
	return smallstringlength+1;
}
int main(){
	char arr[100];
    cin>>arr;
    cout<<length(arr);
}
//removing a particular character from the string...
void remove(char str[]){
	if(str[0]=='\0')
		return;
	if(str[0]!='\0')
		length(str+1);
	else
		for(int i=0; str[i]!='\0'; i++){

		}
}