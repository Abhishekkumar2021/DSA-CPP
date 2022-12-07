#include<bits/stdc++.h>
using namespace std;
#define vi vector<int> 
#define vvi vector<vi> 

int f(vi &cost, int idx,int target){
	//base case : if we have achieved the target or there is no more elements
	if(target==0 ) return 1;
	if(idx==0) return (cost[idx]==target);  

	// do all stuff for that idx
	int pick = 0;
	if(cost[idx]<=target) pick = f(cost,idx-1,target-cost[idx]);
	int not_pick = f(cost,idx-1,target);

	// return count
	return pick + not_pick;
}
int main(){
	int n,target;
	cin>>n>>target;
	vi cost(n); 
	int sum = 0;
	for(int i=0; i<n; i++){
		cin>>cost[i];
		sum+=cost[i];
	}
	if((sum-target)&1){
		cout<<0; 
		return 0;
	} 

	cout<<f(cost,n-1,(sum-target)/2);
	
}