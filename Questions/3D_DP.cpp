#include<bits/stdc++.h>
using namespace std;
int f(vector<vector<int>> &cost, int row, int n,int m,int alice,int bob){

	//base case
	if(alice<0 || alice>=m || bob<0 || bob>=m) return -1e8;
	if(row==n-1){
		if(alice==bob) return cost[row][alice];
		else{
			return cost[row][alice] + cost[row][bob];
		}
	}

	//do all stuff
	int maxi = -1e8;
	for(int i=-1; i<=1; i++){
		for(int j=-1; j<=1; j++){
			if(alice!=bob)
			maxi = max(maxi,cost[row][alice]+cost[row][bob]+f(cost,row+1,n,m,alice+i,bob+j));
			else
			maxi = max(maxi,cost[row][alice]+f(cost,row+1,n,m,alice+i,bob+j));
		}
	}


	//return maximum
	return maxi;
}
int main(){
	vector<vector<int>> &cost

	
}