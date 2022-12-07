#include<bits/stdc++.h>
using namespace std;

int f(vector<vector<int>> &m,int idx,int last,vector<vector<int>> &dp){
	if(idx==0){
		int maxi = INT_MIN;
		for(int i=0; i<=2; i++){
			if(i!=last)
			maxi = max(maxi,m[0][i]);
		}
		return maxi;
	}
	if(dp[idx][last]!=-1) return dp[idx][last];
	int maxi = INT_MIN;
	for(int i=0; i<=2; i++){
		if(i!=last)
		maxi = max(maxi,m[idx][i] + f(m,idx-1,i,dp));
	}
	return dp[idx][last] = maxi;

}
int f_iterative(vector<vector<int>> &m){
	int n = m.size();
	vector<vector<int>> dp(n,vector<int>(4,-1));

	// corresponding to the base case

	dp[0][0] = max(m[0][1],m[0][2]);
	dp[0][1] = max(m[0][0],m[0][2]);
	dp[0][2] = max(m[0][1],m[0][0]);
	dp[0][3] = max(m[0][0],max(m[0][1],m[0][2]));


	for(int day = 1; day<n; day++){
		for(int last = 0; last<=3; last++){
			int maxi = INT_MIN;
			for(int i=0; i<=2; i++){
				if(i!=last)
				maxi = max(maxi,m[day][i] + dp[day-1][i]);
			}
			dp[day][last] = maxi;
		}
	}
	return dp[n-1][3];
}

//space optimisation
int f_space(vector<vector<int>> &m){
	int n = m.size();
	vector<int> dp(4);

	// corresponding to the base case

	dp[0] = max(m[0][1],m[0][2]);
	dp[1] = max(m[0][0],m[0][2]);
	dp[2] = max(m[0][1],m[0][0]);
	dp[3] = max(m[0][0],max(m[0][1],m[0][2]));


	for(int day = 1; day<n; day++){
		vector<int> temp(4);

		for(int last = 0; last<=3; last++){
			int maxi = INT_MIN;
			for(int i=0; i<=2; i++){
				if(i!=last)
				maxi = max(maxi,m[day][i] + dp[i]);
			}
			temp[last] = maxi;
		}
		dp = temp;
	}
	return dp[3];
}

int main(){
	int n;
	cin>>n;
	vector<vector<int>> m(n,vector<int>(3));
	for(int i=0; i<n; i ++)
		for(int j=0; j<3; j++)
			cin>>m[i][j];

	vector<vector<int>> dp(n,vector<int>(4,-1));
	// cout<<f(m,n-1,3,dp);
	cout<<f_space(m);

} 