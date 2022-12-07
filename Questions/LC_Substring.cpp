#include<bits/stdc++.h>
using namespace std;

int tabulation(int n1,int n2, string &a, string &b,vector<vector<int>> &dp){
    // corresponding to the base case
    for(int i=0; i<=n1; i++){
        for(int j=0; j<=n2; j++){
            if(i==0 || j==0) dp[i][j] = 0;
        }
    }
    int maxi = INT_MIN;
    for(int i=1; i<=n1; i++){
        for(int j=1; j<=n2; j++){
            // if they match then we check the previous max length substring common
            if(a[i-1] == b[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
                maxi = max(maxi,dp[i][j]);
            } 
            else dp[i][j] = 0;
        }
    }
    return maxi;
}

int main(){
    int n1,n2;
    string s1,s2;
    cin>>n1>>s1>>n2>>s2;
    vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1));
    int n = tabulation(n1,n2,s1,s2,dp);
    cout<<"LC substring = "<<n;

    int r,c;
    for(int i=0; i<=n1; i++){
        for(int j=0; j<=n2; j++){
            if(dp[i][j]==n){
                r = i;
                c = j;
            }
            // cout<<dp[i][j]<<" ";
        }
        // cout<<"\n";
    }
    vector<char> s(n);
    int idx = n-1;
    while(r>0 && c>0 && dp[r][c]){
        s[idx] = s1[r-1];
        r--;
        c--;
        idx--;
    }
    cout<<"\n";
    for(auto &c : s) cout<<c;
}