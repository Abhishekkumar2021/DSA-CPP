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

vector<int> findTripletBrute(vi &arr){
	int n = 0;
	int a,b,c;
	int sum = 0;
	loop(i,0,n)
		loop(j,i+1,n)
			loop(k,j+1,n)
				if((arr[i]+arr[j]+arr[k])>sum){
					a = arr[i];
					b = arr[j];
					c = arr[k];
					sum = arr[i]+arr[j]+arr[k];
				}
	cout<<a<<" "<<b<<" "<<c<<"\n";
	return {a,b,c};
}

void solve(){
	int n;
	cin>>n;
	vi arr(n);
	loop(i,0,n) cin>>arr[i];
	findTripletBrute(arr);

	
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