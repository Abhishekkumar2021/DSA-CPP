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
	vi arr(n),pre(n);
	loop(i,0,n){
		cin>>arr[i];
		if(i==0) pre[i] = arr[i];
		else pre[i] = pre[i-1]+arr[i];
	} 
	unordered_map<int,int> m;
	m.insert({0,-1});
	int count=0;
	loop(i,0,n){
		cout<<pre[i]<<" ";
		if(m.count(pre[i])) count++;
		else m.insert({pre[i],i});
	}
	cout<<count;



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