#include<bits/stdc++.h>
using namespace std;
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
    int n = tabulation(n1,n2,s1,s2,dp);
    cout<<"Length of shortest superstring = "<<(n1+n2)-n<<"\n";

    int i = n1,j=n2;
    int idx = (n1+n2)-n-1 ;
    vector<char> s(n1+n2-n);
    while(i>0 && j>0){
        if(s1[i-1]==s2[j-1]){
            s[idx] = s1[i-1];
            idx--;
            i--;
            j--;
        }else if(dp[i-1][j]>dp[i][j-1]){
            s[idx] = s1[i-1];
            idx--;
            i--;
        }else {
            s[idx] = s2[j-1];
            idx--;
            j--;
        }
    }

    //either of them is going to be executed
    while(i>0){
        s[idx] = s1[i-1];
        idx--;
        i--;

    }
     while(j>0){
        s[idx] = s2[-1];
        idx--;
        j--;

    }
    for (int i = 0; i < (n1+n2)-n; ++i)
    {
        cout<<s[i];
    }
}