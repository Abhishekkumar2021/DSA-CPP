#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>

// always pass dp as refrence
int f(vvi maze,int row,int col, vvi &dp){
	//base cases
	if(row>=0 && col>=0 && maze[row][col]==-1) return 0;
	if(row==0 && col==0) return 1;

	// out of the boundary
	if(row<0 || col<0) return 0;

	if(dp[row][col]!=-1) return dp[row][col];
	// do all stuffs
	int top = f(maze, row-1,col,dp);
	int left = f(maze, row,col-1,dp);

	// count total
	return dp[row][col] = left+top;

}

int main(){
	int n,m;
	cin>>n>>m;
	vvi maze(n,vi(m));
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin>>maze[i][j];
		}
	}
	vvi dp(n,vi(m,-1));
	cout<<f(maze,n-1,m-1,dp);
	// cout<<f_space(n,m);


}