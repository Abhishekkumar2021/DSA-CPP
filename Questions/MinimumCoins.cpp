#include<bits/stdc++.h>
using namespace std;
#define vi vector<int> 
#define vvi vector<vi> 

int f(vi &coin,int target,int idx, vvi &dp){
    // base case
    if(idx==0){
        if(target%coin[idx]==0) return target/coin[idx];
        else return INT_MAX;
    }
    if(dp[idx][target]!=-1) return dp[idx][target];

    //do all stuffs

    int not_pick = f(coin,target,idx-1,dp);
    int pick = INT_MAX;
    if(coin[idx]<=target) pick =1+ f(coin,target-coin[idx],idx,dp);
    return dp[idx][target] = min(pick,not_pick);
}
int main(){
	int n,target;
	cin>>n>>target;
	vi coin(n);
	for(int i=0; i<n; i++) cin>>coin(i);
	vvi dp(n,vi(target+1,-1)) ;
    cout<<f(coin,n-1,target,dp);
}