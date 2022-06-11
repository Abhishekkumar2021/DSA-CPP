#include<bits/stdc++.h>
#include"ST.h"
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];
    SGTree sgt(arr);
    sgt.build();
    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<sgt.query(l,r)<<"\n";
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    solve();
}