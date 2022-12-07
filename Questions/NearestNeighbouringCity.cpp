#include<bits/stdc++.h>
using namespace std;
// some macros
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> pii; 
typedef long long ll;
#define loop(i,s,e) for(int i=s; i<e; i++)

// some bit manipulation functions
void setBit( int &x, int i){
	int bit = 1;
	bit = bit<<i;
	x = x|bit;

}
void changeBit(int &x, int i){
	int bit = 1;
	bit = bit<<i;
	x = x^bit;
}
void unsetBit(int &x, int i){
	int bit = 1;
	bit = bit<<i;
	x = x&(~bit);
}
void printBinary(int x){
	for(int i=31; i>=0; i--){
		int bit = (x>>i) & 1;
		cout<<bit;
	}
	cout<<"\n";
}
vi binary(int x){
	vi ans;	
	for(int i=31; i>=0; i--){
		int bit = (x>>i) & 1;
		ans.push_back(bit);
	}
	return ans;	
}

void solve(){
	int n;
	cin>>n;
	vector<string> c(n);
	vi x(n);
	vi y(n);
	loop(i,0,n) cin>>c[i];
	loop(i,0,n) cin>>x[i];
	loop(i,0,n) cin>>y[i];
	int que;
	cin>>que;
	vector<string> q(que);
	loop(i,0,que) cin>>q[i];
	map<string,int> m;
	loop(i,0,n) m.insert({c[i],i});
	int mini = INT_MAX;
	loop(i,0,que){
		int x0,y0,x1,y1;
		x0 = x[m[q[i]]];
		y0 = y[m[q[i]]];
		int ans = -1;
		loop(j,0,n){
			x1 = x[j];
			y1 = y[j];
			if((x0==x1 || y0==y1) && !(x0==x1 && y0==y1)){
				if(abs(x1-x0)+abs(y1-y0)<=mini){
					ans = j;
					mini = abs(x1-x0)+abs(y1-y0);
				}
			}

		}
		if(ans==-1){
			cout<<"NONE\n";
		}else{
			cout<<c[ans]<<"\n";
		}
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