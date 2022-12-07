#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>

// This problem is different from all that we have done till now
// Here we have only a fixed point and varible ending point
// so as there may be many ending point so we will start our
// recursion call from the starting point

int f(vvi &cost, int row, int col, int n){
	 if(row==n-1) return cost[row][col];

	 // explore all the paths
	 int down = cost[row][col] + f(cost,row+1,col,n);
	 int diag = cost[row][col] + f(cost,row+1,col+1,n);
	 return max(down,diag);

} 

int tabulation(vvi &cost,int n){
	vvi dp(n,vi(n,0));

	// base case
	for(int i=0; i<n; i++) dp[n-1][i] = cost[n-1][i];

	for(int i=n-2; i>=0; i--){
		for(int j=i; j>=0; j--){
			int down = cost[i][j] + dp[i+1][j];
	 		int diag = cost[i][j] + dp[i+1][j+1];
	 		dp[i][j] = max(down,diag);
		}
	}
	return dp[0][0];
}

int main(){
	int n;
	cin>>n;
	vvi cost(n);
	for(int i=0; i<n; i++){
		cost[i].resize(i+1);
		for(int j=0; j<=i; j++){
			cin>>cost[i][j];
		}
	}
	cout<<f(cost,0,0,n);
}