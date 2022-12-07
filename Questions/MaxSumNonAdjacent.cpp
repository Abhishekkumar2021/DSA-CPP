#include<bits/stdc++.h>
using namespace std;
int f(vector<int> arr, int idx){
	if(idx==0) return arr[idx];
	if(idx<0) return 0;

	int pick = arr[idx] + f(arr,idx-2);
	int not_pick = 0 + f(arr,idx-1);
	return max(pick,not_pick);

}

int f2(vector<int> arr){
	int n = arr.size();
	vector<int> dp(n);
	dp[0] = arr[0];
	dp[1] = max(arr[0],arr[1]);

	for(int i=2; i<n; i++){
		int take = arr[i] + dp[i-2];
		int not_take = 0 + dp[i-1];
		dp[i] = max(take.not_take);
	}
	return dp[n-1];
} 


int main(){
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0; i<n; i++) cin>>arr[i];
}