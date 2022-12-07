#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>

int f(vvi &cost, int row, int col, int n,int m){
	if(row==0) return cost[row][col];
	if(col<0 || col>=m) return -1e7;

	int straight = cost[row][col] + f(cost,row-1,col,n,m);
	int leftDig = cost[row][col] + f(cost,row-1,col-1,n,m);
	int rightDig = cost[row][col] + f(cost,row-1,col+1,n,m);

	return max(straight,max(leftDig,rightDig));

}

int main(){
	int n,m;
	cin>>n>>M;

}