#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n1,n2;
    cin>>n1>>n2;
    vector<int> arr1(n1);
    vector<int> arr2(n2);
    for(int i=0; i<n1; i++) cin>>arr1[i];
    for(int i=0; i<n2; i++) cin>>arr2[i];
    int p = 0;
    while(p<n1){
        if(arr1[p]<arr2[0]) p++;
        else{
            swap(arr1[p],arr2[0]);
            p++;
            for(int j=0; j<n2-1; j++){
                if(arr2[j]>arr2[j+1]) swap(arr2[j],arr2[j+1]);
                else break;
            }
            // int idx = lower_bound(arr2.begin()+1,arr2.end(),arr2[0])- arr2.begin()-1;
            // // cout<<idx<<"\n";
            // swap(arr2[0],arr2[idx]);
        }
    } 
    for(int x1:arr1) cout<<x1<<" ";
    cout<<"\n";
    for(int x2:arr2) cout<<x2<<" ";
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    solve();
}