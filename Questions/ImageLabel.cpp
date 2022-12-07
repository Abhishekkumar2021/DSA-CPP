#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
double f(int idx, int m, vi &p){
	// base case
	if(idx==0) return

	// try out all possibilities


	//return minimum
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		vi p(n);
		for(int i=0; i<n; i++) cin>>p[i];
		double ans = f(n-1,m,p);
	}
}