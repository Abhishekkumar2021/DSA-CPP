#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define loop(s,e) for(int i=s; i<e; i++)

void solve(){
	int n;
	cin>>n;
	vi v(n);
	loop(0,n) cin>>v[i];
	long long cnt = 0;
	int s = n;
	loop(0,n-1){
		if(v[i]==0) continue;
		else{
			s = i;
			break;
		}
	}
	loop(s,n-1){
		if(v[i]==0) cnt+=1;
		else cnt+=v[i];
	}
	cout<<cnt<<"\n";
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