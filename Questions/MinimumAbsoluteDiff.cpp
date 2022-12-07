#include<bits/stdc++.h>
using namespace std;
#define vi vector<int> 
#define vvi vector<vi> 
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

int main(){
	int n;
	cin>>n;
	vi cost(n);
	int sum = 0; 
	for(int i=0; i<n; i++){
		cin>>cost[i];
		sum+=cost[i];
	}

	vvi dp(n,vi(sum+1,0));
	targetSum(cost,n,sum+1,dp);
	int miniDiff = INT_MAX;
	for(int target=0; target<=sum; target++){
		if(dp[n-1][target]) miniDiff = min(miniDiff,abs(sum-2*target));
	}
	cout<<"miniDiff = "<<miniDiff<<"\n";

}