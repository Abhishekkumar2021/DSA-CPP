#include<bits/stdc++.h>
using namespace std;

// we have to keep LCP intact and have to make insertion corresonding to each othe character
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
    int size;
    string a;
    cin>>size>>a;
    vector<vector<int>> dp(size+1,vector<int>(size+1,-1));
    string temp = a;
    reverse(a.begin(),a.end());
    int n = tabulation(size,size,a,temp,dp);
    cout<<size - n;

    // cout<<"\nThe LCP string is -\n\n";
    // int i = size,j=size;
    // int idx = n-1 ;
    // vector<char> s(n);
    // while(i>0 && j>0){
    //     if(a[i-1]==temp[j-1]){
    //         s[idx] = a[i-1];
    //         idx--;
    //         i--;
    //         j--;
    //     }else if(dp[i-1][j]>dp[i][j-1]){
    //         i--;
    //     }else {
    //         j--;
    //     }
    // }
    // for (int i = 0; i < n; ++i)
    // {
    //     cout<<s[i];
    // }

}