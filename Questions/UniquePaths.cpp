#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>

// always pass dp as refrence
int f(int row,int col, vvi &dp){
	if(row==0 && col==0) return 1;

	// out of the boundary
	if(row<0 || col<0) return 0;

	if(dp[row][col]!=-1) return dp[row][col];
	// do all stuffs
	int top = f(row-1,col,dp);
	int left = f(row,col-1,dp);

	// count total
	return dp[row][col] = left+top;

}

int f_tabulation(int n,int m){
	vvi dp(n,vi(m));

	// base case
	dp[0][0] = 0;

	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(i==0 && j==0) continue;
			int top = 0,left = 0;
			if(i>0) top = dp[i-1][j];
			if(j>0) left = dp[i][j-1];
			dp[i][j] = top + left;
		}
	}
	return dp[n-1][m-1];

}

int f_space(int n, int m){
	vi prev(m,0);

	for(int i=0; i<n; i++){
		vi temp(m,0);
		for(int j=0; j<m; j++){
			if(i==0 && j==0) temp[j] = 1;
			else{
				int top = 0,left = 0;
				if(i>0) top = prev[j];
				if(j>0) left = temp[j-1];
				temp[j] = top + left;
			}
			
		}
		prev = temp;
	}
	return prev[m-1];
}

int main(){
	int n,m;
	cin>>n>>m;
	
	vvi dp(n,vi(m,-1));
	// cout<<f(n-1,m-1,dp);
	cout<<f_space(n,m);


}