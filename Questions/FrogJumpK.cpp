#include<bits/stdc++.h>
using namespace std;
int f(vector<int> cost,int idx,int k){
	if(idx==0) return 0;

	int mini = INT_MAX;
	for(int i=1; i<=k; i++){
		if(idx-i>=0)
			mini = min(mini,f(cost,idx-i,k) + abs(cost[idx]-cost[idx-i]));
	}
	return mini;	
}

int main(){
	int n,k;
	cin>>n>>k;
	vector<int> cost(n);
	for(int i=0; i<n; i++) cin>>cost[i];
	cout<<f(cost,n-1,k);
}