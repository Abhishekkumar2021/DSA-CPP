#include<bits/stdc++.h>
using namespace std;
// unweighted graph
void printGraph(vector<int> v[],int n){
    for(int i = 1; i<=n; i++){
        cout<<i<<" : ";
        for(int j=0; j<v[i].size(); j++){
            cout<<v[i][j]<<" ";
        }
        cout<<"\n";
    }
}

//weighted graph
void print(vector<pair<int,int> > v[],int n){
     for(int i = 1; i<=n; i++){
        cout<<i<<" : ";
        for(int j=0; j<v[i].size(); j++){
            cout<<"("<<v[i][j].first<<", weight = "<<v[i][j].second<<") ";
        }
        cout<<"\n";
    }
}

int main(){
    int n;
    cin>>n;
    // -------------- unweighted graphs ------------------------------
    //1. Directed graph

    // vector<int> v[n+1];
    // v[0].push_back(0);
    // for(int i=1; i<=n; i++){
    //     int startNode;
    //     cin>>startNode;
    //     int endNode;
    //     cin>>endNode;
    //     v[startNode].push_back(endNode);
    // }
    // printGraph(v,n);

    //2.Undirected Graphs

    //  for(int i=1; i<=n; i++){
    //       int startNode;
    //       cin>>startNode;
    //       int endNode;
    //       cin>>endNode;
    //       v[startNode].push_back(endNode);
    //       v[endNode].push_back(startNode);
    //   }
    //   printGraph(v,n);
    // -------------- weighted graphs ------------------------------
    //1. Directed graph

    vector<pair<int,int>> v[n+1];
    v[0].push_back(make_pair(0,0));
    // for(int i=1; i<=n; i++){
    //     int startNode;
    //     int endNode;
    //     int weight;
    //     cin>>startNode;
    //     cin>>endNode;
    //     cin>>weight;
    //     v[startNode].push_back(make_pair(endNode,weight));
    // }
    // print(v,n);

    //2. Undirected graph

    for(int i=1; i<=n; i++){
        int startNode;
        int endNode;
        int weight;
        cin>>startNode;
        cin>>endNode;
        cin>>weight;
        v[startNode].push_back(make_pair(endNode,weight));
        v[endNode].push_back(make_pair(startNode,weight));
    }
    print(v,n);


}
// 5
// 1 2 2
// 2 3 3
// 3 4 4
// 4 5 5
// 5 1 1