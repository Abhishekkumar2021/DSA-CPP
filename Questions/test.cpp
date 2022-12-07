#include<bits/stdc++.h>
using namespace std;
void solve(){
    multimap<int,int>m;
    m.insert({3,1});
    m.insert({8,2});
    m.insert({7,4});
    m.insert({6,5});
    m.insert({8,6});
    m.insert({6,7});
    m.insert({9,8});
    
    cout<<"Before : \n";
    for(auto it: m){
        cout<<"{ "<<it.first<<" : "<<it.second<<" }\n";
    }
    m.erase(m.find(6));
    m.insert({6,5});
    cout<<"After : \n";
    for(auto it: m){
        cout<<"{ "<<it.first<<" : "<<it.second<<" }\n";
    }


}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    solve();
}