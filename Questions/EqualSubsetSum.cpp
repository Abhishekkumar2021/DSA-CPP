#include<bits/stdc++.h>
using namespace std;
#define vi vector<int> 
#define vvi vector<vi> 



bool f(vi &cost, int idx,int target){
	//base case : if we have achieved the target or there is no more elements
	if(target==0 ) return true;
	if(idx==0) return (cost[idx]==target);  

	// do all stuff for that idx
	bool pick = false;
	if(cost[idx]<=target)
	pick = f(cost,idx-1,target-cost[idx]);
	bool not_pick = f(cost,idx-1,target);

	// return yes/no
	return pick || not_pick;
}

int main(){
	int n;
	cin>>n;
	vi cost(n);
	int sum = 0;
	for(int i=0; i<n; i++){
		cin>>cost[i];
		sum+=cost[i];
	} 	
	if(sum&1){
		cout<<"We cannot do equal partition\n";
	}
	else{
		int exist = f(cost,n-1,sum/2);
		if(exist) cout<<"Equal partition is possible\n";
		else cout<<"We cannot do equal partition\n";
	} 
}