#include<bits/stdc++.h>
using namespace std;

void solve(){
	int n,H,M;
	vector<int> hour(n);
	vector<int> min(n);
	for(int i=0; i<n; i++){
		cin>>hour[i];
		cin>>min[i];
	}
	int i =0;
	for(; i<n; i++){
		if(hour[i]<=H) break;
	}
	if(hour[i]==H) cout<<M-min[i]<<"\n";
	else{

	}

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