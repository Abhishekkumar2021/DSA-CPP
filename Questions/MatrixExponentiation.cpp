#include<bits/stdc++.h>
using namespace std;
#define vi vector<int> 
#define vvi vector<vi>


/* 
The problem is that you are given a matrix M and a number 0<=N<=18 and
you have to find out M^N
*/

void print(vvi m){
	int r = m.size();
	int c = m[0].size();
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++)
			cout<<m[i][j]<<" ";
		cout<<"\n";
	}

}

// Matrices must be compatible
vvi mul(vvi a, vvi b){
	int p,q,r;
	p = a.size();
	q = b.size();
	r = b[0].size();

	vvi ans(p,vi(r,0));
	for(int i=0; i<p; i++){
		for(int j=0; j<r; j++){
			for(int k = 0; k<q; k++){
				ans[i][j]+=a[i][k]*b[k][j];
			}
		}
	}
	return ans;
}

vvi identity(int n){
	vvi ans(n,vi(n,0));
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			if(i==j)
				ans[i][j] = 1;

	return ans;
}
// Matrix exponentiation
vvi exp(vvi m, int n){
	if(n==1) return m;
	if(n==0) return identity(m.size());
	vvi half = exp(m,n/2);
	vvi sqr = mul(half,half);
	if(n&1) return mul(m,sqr);
	return sqr;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int r,c,n;
	cin>>r>>c>>n;
	vvi m(r,vi(c));
	for(int i=0; i<r; i++)
		for(int j=0; j<c; j++)
			cin>>m[i][j];

	print(m);
	vvi sqr = mul(m,m);
	print(sqr);
	vvi power = exp(m,n);
	print(power);
}