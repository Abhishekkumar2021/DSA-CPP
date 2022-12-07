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

int arrSum(vi v){
	int sum= 0;
	loop(i,0,v.size()){
		sum+=v[i];
	}
	return sum;
}

void solve(){
	int n;
	cin>>n;
	vi a(n);
	loop(i,0,n) cin>>a[i];
	int q;
	cin>>q;
	int l,r;
	int s = arrSum(a);
	loop(i,0,q){
		cin>>l>>r;
		int la,lb,ra,rb,sum=0;
		la = l%n;
		lb = l/n;
		ra = r%n;
		rb = r/n;
		if(rb-lb>1){
			sum+=(rb-lb)*s;
			while(la<=n){
				sum+=a[la-1];
				la++;
			}
			while(ra>=1){
				sum+=a[ra-1];
				ra--;
			}

		}else if(rb-lb==1){
			while(la<=n){
				sum+=a[la-1];
				la++;
			}
			while(ra>=1){
				sum+=a[ra-1];
				ra--;
			}

		}else if(lb==rb){
			while(la<=ra){
				sum+=a[la-1];
				la++;
			}
		}
		cout<<sum<<"\n";
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