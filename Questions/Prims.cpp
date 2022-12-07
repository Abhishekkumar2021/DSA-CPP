#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> adj(n);
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    int src;
    cin>>src;
    vector<int> dist(n,INT_MAX);
    dist[src]=0;
    set<pair<int,int>> s;
    s.insert({0,src});
    while(!s.empty()){
        auto it=s.begin();
        int node=it->second;
        int nodeDist=it->first;
        s.erase(it);
        for(auto it:adj[node]){
            if(nodeDist+it.second<dist[it.first]){
                int dest=it.first;
                auto f=s.find({dist[dest],dest});
                if(f!=s.end())
                    s.erase(f);
                dist[dest]=nodeDist+it.second;
                s.insert({dist[dest],dest});
            }
        }
    }
    for(int i=0;i<n;i++)
        cout<<dist[i]<<" ";
    return 0;
}