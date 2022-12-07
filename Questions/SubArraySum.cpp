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
	vi arr(n);
	loop(i,0,n) cin>>arr[i];
	int k;
	cin>>k;
	vi pre(n,0);
	pre[0] = arr[0];
	loop(i,1,n) pre[i] = pre[i-1] + arr[i];
	int cnt = 0;
	loop(i,0,n)
		loop(j,i,n)
			if(i>0 && pre[j]-pre[i-1]<k) cnt++;
			else if(pre[j]<k) cnt++;

	cout<<cnt;
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