#include<bits/stdc++.h>
using namespace std;
// some macros
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii; 
typedef vector<ii> vii;
typedef long long ll;
#define loop(i,s,e) for(int i=s; i<e; i++)

int f(vi &arr,int idx,vi &dp){
        //base case
        if(idx==0) return dp[idx] = 1;
        
        if(dp[idx]!=-1) return dp[idx];
        
        // do stuff with idx
        int j = 0;
        int maxi = 1;
        while(j<idx){
            if(arr[j]<arr[idx]){
            	// cout<<"arr[j] = "<<arr[j]<<", arr[idx] = "<<arr[idx]<<"\n";
                maxi = max(maxi,1+f(arr,j,dp));
            }
            j++;
        }
        
        
        //return max
        return dp[idx] = maxi;
        
    }

void solve(){
	int n;
	cin>>n;
	vi arr(n); 
	loop(i,0,n) cin>>arr[i];
	vi dp(n,-1);
	loop(i,0,n)
	f(arr,i,dp);
	for(int x : dp) cout<<x<<" ";
	cout<<"\n";
    cout<< *max_element(dp.begin(),dp.end());

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