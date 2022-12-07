#include<bits/stdc++.h>
using namespace std;
// some macros
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii; 
typedef vector<ii> vii;
typedef long long ll;
#define loop(i,s,e) for(int i=s; i<e; i++)

void solve(){
	int n,k;
	cin>>n>>k;
	if(k > (n + 1) / 2){
		cout<<"-1\n";
		return ;
	}
	int in = 0;
	loop(i,0,n){
		loop(j,0,n){
			if(j==in && i==in){
				cout<<"R";
				in+=2;
			}  
			else cout<<".";
		}
		cout<<"\n";
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