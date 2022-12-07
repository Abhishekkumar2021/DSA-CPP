#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>

// always pass array as refrence
int f(vvi &cost,int row,int col, vvi &dp){
	//base cases
	if(row==0 && col==0) return cost[i][j];

	// out of the boundary
	if(row<0 || col<0) return INT_MAX;

	if(dp[row][col]!=-1) return dp[row][col];
	// do all stuffs
	int top = f(maze, row-1,col,dp);
	int left = f(maze, row,col-1,dp);

	// count total
	return dp[row][col] = cost[row][col] + min(left,top);

}

int main(){
	int n,m;
	cin>>n>>m;
	vvi cost(n,vi(m));
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin>>cost[i][j];
		}
	}
	vvi dp(n,vi(m,-1));
	cout<<f(cost,n-1,m-1,dp);
	// cout<<f_space(n,m);


}