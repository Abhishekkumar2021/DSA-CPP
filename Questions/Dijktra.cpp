#include<bits/stdc++.h>
using namespace std;
/*
    Dijkstra's Algorithm
    --------------------
    Time: O((V + E)logV)
    Space: O(V)

    Dijkstra's algorithm is an algorithm for finding the shortest paths between nodes in a graph, which may represent, for example, road networks.
    It was conceived by computer scientist Edsger W. Dijkstra in 1956 and published three years later.
    Pseudocode: https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm#Pseudocode
    Code: https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm#C++
    Image: https://upload.wikimedia.org/wikipedia/commons/5/57/Dijkstra_Animation.gif
    Video: https://www.youtube.com/watch?v=gdmfOwyQlcI

*/
int main()
{
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> adj[n+1];
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    int src;
    cin>>src;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> dist(n+1,INT_MAX);
    pq.push({0,src});
    dist[src]=0;
    while(!pq.empty())
    {
        int u=pq.top().second;
        pq.pop();
        for(auto it:adj[u])
        {
            int v=it.first;
            int w=it.second;
            if(dist[v]>dist[u]+w)
            {
                dist[v]=dist[u]+w;
                pq.push({dist[v],v});
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        cout<<dist[i]<<" ";
    }
}

/*
Example:
Input:
5 7
1 2 4
1 3 2
2 3 1
2 4 5
3 4 8
3 5 10
4 5 2
4
Output:
8 5 6 0 2



*/
