#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    for(int i=0; i<16; i++){
        for(int j=0; j<64; j++){
            if(__builtin_popcount(i)+__builtin_popcount(j)==n){
                int hr = 0;
                for(int k=3; k>=0; k--){
                    int bit = (i>>k) &1;
                    hr+=pow(2,k)*bit;
                }
                int min = 0;
                for(int k=5; k>=0; k--){
                    int bit = (j>>k) &1;
                    min+=pow(2,k)*bit;
                }
                
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}