#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define vii vector<pair<int,int>>
#define loop(s,e) for(long long i=(s); i<(e); i++)

void solve(){
	int n,c,q;
	cin>>n>>c>>q;
	string s;
	cin>>s;
	vii p(c);
	loop(0,c){
		cin>>p[i].first;
		cin>>p[i].second;
	}
	vi v(q);
	loop(0,q) cin>>v[i];
	
	
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

// #include<bits/stdc++.h>
// using namespace std;
// #define vi vector<int>
// #define vvi vector<vi>
// #define loop(s,e) for(long long i=(s); i<(e); i++)

// void solve(){
	// int n,c,q;
	// cin>>n>>c>>q;
	// string s;
	// cin>>s;
// 	loop(0,c){
// 		long long l,r;
// 		cin>>l>>r;
// 		s+=s.substr(l-1,(r-l+1));
// 	}
// 	loop(0,q){
// 		int x;
// 		cin>>x;
// 		cout<<s[x-1]<<"\n";
// 	}
// }

// int main(){
//     ios_base::sync_with_stdio(false);
// 	cin.tie(NULL);
// 	int t;
// 	cin>>t;
// 	while(t--){
// 		solve();
// 	}
// }