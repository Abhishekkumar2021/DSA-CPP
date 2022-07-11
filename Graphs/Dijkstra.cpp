#include <bits/stdc++.h>
using namespace std;

vector<int> Dijkstra(vector<pair<int, int>> adj[], int n, int src)
{
    vector<int> dis(n, INT_MAX);
    dis[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({src, 0});
    while (!q.empty())
    {
        pair<int, int> front = q.top();
        int node = front.first;
        int dist = front.second;
        q.pop();

        for (auto it : adj[node])
        {
            int nextNode = it.first;
            int edgeWeight = it.second;
            if (dis[nextNode] > dis[node] + edgeWeight)
            {
                dis[nextNode] = dis[node] + edgeWeight;
                q.push({nextNode, dis[nextNode]});
            }
        }
    }
    return dis;
}
void solve()
{
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    solve();
}