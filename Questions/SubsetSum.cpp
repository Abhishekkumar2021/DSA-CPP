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
void targetSum(vi &cost, int n,int target, vvi &dp){

	// first consider all the base case
	for(int i=0; i<n; i++) dp[i][0] = 1;
	if(cost[0]<=target) dp[0][cost[0]] = 1;

	for(int i=1; i<n; i++){
		for(int j=1; j<=target; j++){
			int not_pick = dp[i-1][j];
			int pick = 0;
			if(cost[i]<=j) pick = dp[i-1][j-cost[i]];
			dp[i][j] = pick || not_pick;
		}
	}

		
}

int func(int start,int n,int k ,vector<int>&arr,vector<vector<int>>&dp)// n is the last index value
{ 
	//Base case
	if(k==0) return 1;
	if(start>n) return 0;
	if(k<0) return 0;
	if(dp[start][k] !=-1)
	  	return dp[start][k];
    
	int pick = func(start+1,n,k-arr[start],arr,dp);
	int non_pick = func(start+1,n,k,arr,dp);
	return dp[start][k] = pick+non_pick;
}
int findWays(vector<int> &num, int k)
{
    int n = num.size();
    vector<vector<int>>dp(n,vector<int>(k+1,-1));
    return func(0,n-1,k,num,dp);
}
int main(){
	int n,target;
	cin>>n>>target;
	vi cost(n);
	for(int i=0; i<n; i++) cin>>cost[i];
	// cout<<f(cost,n-1,target);
	vvi dp(n,vi(target+1,0));
	targetSum(cost,n,target,dp);
}