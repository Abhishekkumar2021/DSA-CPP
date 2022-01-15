#include<bits/stdc++.h>
using namespace std;

// Unweighted graphs
void printDirected(vector<pair<int,int>> edgeList){
    for(int i=0; i<edgeList.size(); i++){
        cout<<edgeList[i].first<<" --> "<<edgeList[i].second<<"\n";
    }
}
void printUndirected(vector<pair<int,int>> edgeList){
    for(int i=0; i<edgeList.size(); i+=2){
        cout<<edgeList[i].first<<" <----> "<<edgeList[i].second<<"\n";
    }
}
// Weighted graphs
//1. Directed graphs
void printDirected(vector<tuple<int,int,int>> edgeList){
    for(int i=0; i<edgeList.size(); i++){
        cout<<get<0>(edgeList[i])<<" --> "<<get<1>(edgeList[i])<<", weight = "<<get<2>(edgeList[i])<<"\n";
    }
}
//2. Undirected graphs
void printUndirected(vector<tuple<int,int,int>> edgeList){
    for(int i=0; i<edgeList.size(); i+=2){
        cout<<get<0>(edgeList[i])<<" <-----> "<<get<1>(edgeList[i])<<", weight = "<<get<2>(edgeList[i])<<"\n";
    }
}
int main(){
    // ----------- Unweighted graphs -----------
    //1. Directed graphs
    int e;
    cin>>e;
    // vector<pair<int,int>> edgeList;
    // for(int i=0; i<e; i++){
    //     int startNode;
    //     int endNode;
    //     cin>>startNode;
    //     cin>>endNode;
    //     edgeList.push_back({startNode,endNode});
    // }
    // printDirected(edgeList);

    //2. Undirected graphs

    // for(int i=0; i<e; i++){
    //     int startNode;
    //     int endNode;
    //     cin>>startNode;
    //     cin>>endNode;
    //     edgeList.push_back({startNode,endNode});
    //     edgeList.push_back({endNode,startNode});
    // }
    // printUndirected(edgeList);

    // ----------------- weighted graphs ----------
    //1. Directed graph
    vector<tuple<int,int,int>> edgeList;
    // for(int i=0; i<e; i++) {
    //     int startNode;
    //     int endNode;
    //     int weight;
    //     cin>>startNode;
    //     cin>>endNode;
    //     cin>>weight;
    //     edgeList.push_back({startNode,endNode,weight});
    // }
    // printDirected(edgeList);

    //2. Undirected graph

    for(int i=0; i<e; i++) {
        int startNode;
        int endNode;
        int weight;
        cin>>startNode;
        cin>>endNode;
        cin>>weight;
        edgeList.push_back({startNode,endNode,weight});
        edgeList.push_back({startNode, endNode, weight});
    }
    printUndirected(edgeList);
}