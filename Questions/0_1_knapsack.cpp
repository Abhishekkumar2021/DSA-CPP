#include<bits/stdc++.h>
using namespace std;
#define vi vector<int> 
#define vvi vector<vi> 

int f(vi &weight,vi  &value, int idx,int w){
	
	//base case
	if(idx==0){
		if(weight[idx]<=w) return value[idx];
		else return 0;
	}

	// do all stuff
	int not_pick = f(weight,value,idx-1,w);

	int pick = INT_MIN;
	if(w>=weight[idx]) pick = value[idx] + f(weight,value,idx-1,w-weight[idx]);

	// return maximum of both
	return max(pick,not_pick);
}

int main(){
	int n,w;
	cin>>n>>w;
	vi value(n),weight(n); 
	for(int i=0; i<n; i++){
		cin>>weight[i];
		cin>>value[i]; 
	}
	
}