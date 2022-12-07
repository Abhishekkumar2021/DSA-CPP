#include<bits/stdc++.h>
using namespace std;

int minimumHealth(vector<vector<int>> mat, int n, int m){
    int ans = 0;
    if(n==1){
        for(int i=0; i<m; i++)
        ans+=mat[0][i];
        return ans+1;
    }
    if(m==1){
        for(int i=0; i<n; i++)
        ans+=mat[i][0];
        return ans+1;
    }
}

void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> mat(n);
    for(int i=0; i<n; i++){
        vector<int> row(m);
        for(int j=0; i<m; j++) 
        cin>>row[j];
        mat[i] = row;
    }
    int ans = minimumHealth(mat,n,m);     
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    solve();
}