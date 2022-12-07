#include<bits/stdc++.h>
using namespace std;
int f(int n1,int n2, string &a, string &b,vector<vector<int>> &dp){
    if(n1==0 || n2==0) return 0;
    if(dp[n1][n2]!=-1) return dp[n1][n2];
    // explore all possiblities
    if(a[n1-1] == b[n2-1]) return 1 + f(n1-1, n2-1, a,b,dp);
    return dp[n1][n2] = max(f(n1, n2-1, a,b,dp),f(n1-1, n2, a,b,dp));
}

int tabulation(int n1,int n2, string &a, string &b,vector<vector<int>> &dp){
    // corresponding to the base case
    for(int i=0; i<=n1; i++){
        for(int j=0; j<=n2; j++){
            if(i==0 || j==0) dp[i][j] = 0;
        }
    }
    for(int i=1; i<=n1; i++){
        for(int j=1; j<=n2; j++){
            if(a[i-1] == b[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }
    return dp[n1][n2];

}

int main(){
    int n1,n2;
    string s1,s2;
    cin>>n1>>s1>>n2>>s2;
    vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1));
    cout<<"length of LCS = "<<tabulation(n1,n2,s1,s2,dp);

    cout<<"\nThe dp matrix is looking like this\n\n";
    for(auto e : dp){
        for(auto x : e) cout<<x<<" ";
        cout<<"\n";
    }

}