#include<bits/stdc++.h>
using namespace std;

int f(int i,int j, string &a, string &b,vector<vector<int>> &dp){
    // base case
    if(j<0 ) return 1;
    if(i<0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];

    // explore all possibilities
    if(a[i]==b[j]){
        int not_take = f(i-1,j,a,b,dp);
        int take = f(i-1,j-1,a,b,dp);
        return dp[i][j] = take + not_take; 
    }
    return dp[i][j] = f(i-1,j,a,b,dp);
}

int main(){
    int n1,n2;
    string s1,s2;
    cin>>n1>>s1>>n2>>s2;
    vector<vector<int>> dp(n1,vector<int>(n2,-1));
    cout<<f(n1-1,n2-1,s1,s2,dp);
    
} 

