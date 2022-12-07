#include<bits/stdc++.h>
using namespace std;
const int m = 1e9+7;

int power(int x,int n){
	if(n==1) return x;
	if(n==0) return 1;
	int half = power(x,n/2);
	int sqr = (half%m*half%m + m)%m;
	if(n  & 1) return  (x*sqr+ m)%m;
	return sqr;
}

int main(){
	int n,x;
	cin>>x>>n;
	cout<<power(x,n)<<"\n";
	
}