#include<bits/stdc++.h>
using namespace std;

int f(int n,int dp[]){
	if(n<=1) return n;
	if(dp[n]!=-1) return dp[n];
	return dp[n]=f(n-1,dp)+f(n-2,dp);
}
int f_bottom_up(int n){
	int dp[n+1];
	dp[0] = 0;
	dp[1] = 1;
	for(int i=2; i<=n; i++) dp[i] = dp[i-1] + dp[i-2];
	return dp[n];
}

int main(){
	int n;
	cin>>n;
	int dp[n+1];
	memset(dp,-1,sizeof dp);
	cout<<f(n,dp);
	cout<<f_bottom_up(n);
}