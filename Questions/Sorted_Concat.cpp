#include<bits/stdc++.h>
using namespace std;
// some macros
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> pii; 
typedef long long ll;
#define loop(i,s,e) for(int i=s; i<e; i++)

int f(int n, int m,vi a,vi b){
	// base case
	if(n==0 || m==0) return 0;

	// do some stuff

	// a)if they match
	if(a[n-1]==b[m-1]) return 1+ f(n-1,m-1,a,b);
	// b) if the doesn't match
	return max(f(n,m-1,a, ),f(n-1,m,a,b));

}
int mem(vi a,vi b){
	int n = a.size();
	int m = b.size();
	vvi dp(n+1, vi(m+1,0));
	loop(i,1,n+1)
		loop(j,1,m+1)
			if(a[i-1]==b[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
			else dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
	return dp[n][m];
}
vi LCS(vi a,vi b){
	int n = a.size();
	int m = b.size();
	vvi dp(n+1, vi(m+1,0));
	loop(i,1,n+1)
		loop(j,1,m+1)
			if(a[i-1]==b[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
			else dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
	// finding the array

	int i = n,j=m;
	vi ans;	
	while(i>0 && j>0){
		if(a[i-1]==b[j-1]){
			ans.push_back(a[i-1]);
			i--;
			j--;
		}
		else if(dp[i][j-1]>dp[i-1][j]){
			j--;
		}else{
			i--;
		} 

	}
	reverse(ans.begin(),ans.end());
	return ans;

}

void solve(){
	int n,m; 
	cin>>n>>m;
	vi a(n),b(m);
	for(int i=0; i<n; i++) cin>>a[i];
	for(int i=0; i<m; i++) cin>>b[i];
	// int ans = f(n,m,a,b);
	// int ans = mem(a,b);
	vi ans = LCS(a,b);
	// cout<<ans<<"\n";
	for(int x:ans) cout<<x<<" ";

}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
