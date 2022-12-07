#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define vii vector<pair<int,int>>
#define loop(i,s,e) for(long long i=(s); i<(e); i++)
int divide(int A, int B) {
    // edge cases
    if(A==INT_MIN && B==1) return INT_MIN;
    if(A==INT_MIN && B==-1) return INT_MAX;
    if(A==INT_MIN && B==INT_MIN) return 1;
    long long ans = 0;
    long long a = A,b = B;
    if(A<0) a = -1.0*a;
    if(B<0) b = -1.0*b;
    while(a>=b){
        a-=b;
        ans++;
    }
    if(A>=0 && B>0 || A<=0 && B<0) 
        return ans;
    else
        return -ans;
}

void solve(){

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