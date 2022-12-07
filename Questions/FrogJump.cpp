#include<bits/stdc++.h>
using namespace std;

//useful macros
#define vi vector<int>
#define vvi vector<vector<int>>
#define loop(a,b) for(int i=a; i<(int)b; i++)

//useful typedefs
typedef long long int ll;

int f(vi cost,int idx,vi dp){
	//base case
	if(idx==0) return 0;
	if(idx==1) return abs(cost[1]-cost[0]);
	if(dp[idx]!=-1) return dp[idx];
	//do all stuffs on that idx
	int left = f(cost,idx-1,dp) + abs(cost[idx]-cost[idx-1]);
	int right = f(cost,idx-2,dp) + abs(cost[idx]-cost[idx-2]);
	return dp[idx] = min(left,right);
}

int main(){
	int n;
	cin>>n;
	vi cost(n);
	loop(0,n) cin>>cost[i];
	vi dp(n,-1);
	cout<<f(cost,n-1,dp);
}

