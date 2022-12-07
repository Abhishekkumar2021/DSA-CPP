#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define loop(s,e) for(int i=(s); i<(e); i++)

void solve(){
	int n,x;
	cin>>n>>x;
	vi v(2*n);
	loop(0,2*n) cin>>v[i];
	sort(v.begin(),v.end());
	loop(0,n){
		if(v[n+i]-v[i]<x){
			cout<<"NO\n";
			return;
		}
	}
	cout<<"YES\n";
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