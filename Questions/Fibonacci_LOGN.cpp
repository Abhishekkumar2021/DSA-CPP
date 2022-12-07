#include<bits/stdc++.h>
using namespace std;


vector<vector<int>> mul(vector<vector<int>> a, vector<vector<int>> b){
	int p,q,r;
	p = a.size();
	q = b.size();
	r = b[0].size();

	vector<vector<int>> ans(p,vector<int>(r,0));
	for(int i=0; i<p; i++){
		for(int j=0; j<r; j++){
			for(int k = 0; k<q; k++){
				ans[i][j]+=a[i][k]*b[k][j];
			}
		}
	}
	return ans;
}

vector<vector<int>> identity(int n){
	vector<vector<int>> ans(n,vector<int>(n,0));
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			if(i==j)
				ans[i][j] = 1;

	return ans;
}
// Matrix exponentiation
vector<vector<int>> exp(vector<vector<int>> m, int n){
	if(n==1) return m;
	if(n==0) return identity(m.size());
	vector<vector<int>> half = exp(m,n/2);
	vector<vector<int>> sqr = mul(half,half);
	if(n&1) return mul(m,sqr);
	return sqr;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<vector<int>>m = {
			{1,1},
			{1,0}
		};

		if(n==0){
			cout<<0<<" ";
			continue;
		}
		vector<vector<int>> ans = exp(m,n-1);
		cout<<ans[0][0]<<" ";
	}
	



}