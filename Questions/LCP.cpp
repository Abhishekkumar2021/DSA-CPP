#include<bits/stdc++.h>
using namespace std;
int f(int i,int j,string &s,vector<vector<int>> &dp){
    // base case
    if(i>j) return dp[i][j] = 0;
    if(i==j) return dp[i][j] = 1;

    if(dp[i][j]!=0) return dp[i][j];

    // do all stuff

    // if end character doesn'tmatch
    if(s[i]==s[j]) return dp[i][j] =  2 + f(i+1,j-1,s,dp);

    // if the end character don't match
    return dp[i][j] = max(f(i+1,j,s,dp),f(i,j-1,s,dp));
}

int tabulation(string &s,vector<vector<int>> &dp){
    int n = s.length();
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==j) dp[i][j] = 1;
            if(i>j) dp[i][j] = 0;
            if(j==i+1 && s[i]==s[j]){
                dp[i][j] = 2;
            }
        }
    }
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<n; j++){
    //         if(i>=j) continue;
    //         if(s[i]==s[j]) dp[i][j] =  2 + dp[i+1][j-1];
    //         else dp[i][j] = max(dp[i+1][j],dp[i][j-1]);  
    //     }
    // }
    return dp[0][n-1];
}
int main(){ 
    string s;
    cin>>s;
    int size = s.size();
    vector<vector<int>> dp(size,vector<int>(size,0));
    int n = f(0,size-1,s,dp);
    // int n = tabulation(s,dp);
    cout<<n<<"\n";
    int i = 0, j=size - 1;
    string ans = "";
    while(j>i && dp[i][j]){
        if(s[i]==s[j]){
            ans+=s[i];
            i++;
            j--;
        }else if(dp[i+1][j]>dp[i][j-1]){
            i++;
        }else{
            j--;
        }
    }

    string f = ans;
    if(i==j) f+=s[i];
    reverse(ans.begin(),ans.end());
    f+=ans;
    cout<<f;
}