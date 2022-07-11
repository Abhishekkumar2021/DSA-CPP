#include<bits/stdc++.h>
using namespace std;

int prims(vector<pair<int,int>> adj[],int n){
    int parent[n],mst[n],key[n];
    for(int i=0; i<n; i++){
        parent[i]=-1;
        mst[i]=0;
        key[i]=INT_MAX;
    }
    key[0]=0;
    for(int i=0; i<n-1; i++){
        int mini = INT_MAX,u ;
        for(int j=0; j<n; j++){
            if(mst[j]==0 && mini>key[j]){
                mini = key[j];
                u = j;
            }
        }
        mst[u] = 1;
        for(auto it : adj[u]){
            int node = it.first;
            int weight = it.second;
            if(!mst[node] && key[node]>weight){
                parent[node] = u;
                key[node]= weight;
            }
        }
    }

    int totalSum = 0;
    for(int i=0; i<n; i++){
        if(parent[i]!=-1) totalSum+=key[i];
    }
    return totalSum;

}

void solve(){
    
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    solve();
}