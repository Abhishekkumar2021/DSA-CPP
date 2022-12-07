#include<bits/stdc++.h>
using namespace std;
int f(int idx,vector<int> &A,int m){
	if(idx==0) return A[0]%m==0;

	int pick = 
}
int solution(vector<int> &A, int m){
	int n = A.size();
	int cnt = 0;
	


}

void solve(){
	int n;
	cin>>n;
	vector<int> v(n);
	int m;
	cin>>m;
	for(int i=0; i<n; i++) cin>>v[i];
	cout<<solution(v,m);

}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}