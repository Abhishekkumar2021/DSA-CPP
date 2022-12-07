#include<bits/stdc++.h>
using namespace std;

bool comp(pair<int,int> a,pair<int,int> b){
    if(a.second*1.0/a.first>=b.second*1.0/b.first) return true;
    return false;
}
void solve(){
    int n,capacity;
    cin>>n>>capacity;
    vector<pair<int,int>> items(n);
    for(int i=0; i<n; i++){
        int w,p;
        cin>>w>>p;
        items[i].first = w;
        items[i].second = p;
    }

    int maxProfit = 0;
    int currWeight = 0;
    sort(items.begin(),items.end(),comp);
    for(auto x:items){
        cout<<x.first<<" , "<<x.second<<", "<<x.second*1.0/x.first<<"\n";
    }
    int i = 0;
    while(currWeight<capacity){
        currWeight+=items[i].first;
        maxProfit+=items[i].second;
        i++;
    }
    int diff = currWeight-capacity;
    maxProfit-=(1.0*items[i-1].second/items[i-1].first)*diff;

    cout<<maxProfit<<"\n";
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    solve();
}