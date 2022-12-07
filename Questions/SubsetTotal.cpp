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
void f(int idx,int arr[],int n,vector<int> &sub,int &maxi){
    if(idx==n){
    	int ans = 0;
        for(int i=0; i<sub.size(); i++) ans^=sub[i];
        maxi = max(maxi,ans);
    }else{
    	sub.push_back(arr[idx]);
    	f(idx+1,arr,n,sub,maxi);
    	sub.pop_back();
    	f(idx+1,arr,n,sub,maxi);
    }

}

void solve(){
	int n;
	cin>>n;
	int arr[n];
	loop(i,0,n) cin>>arr[i];
	vi sub;
	int maxi = 0;
	f(0,arr,n,sub,maxi);
	cout<<maxi;

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