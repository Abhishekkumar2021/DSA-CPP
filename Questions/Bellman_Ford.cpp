/*
Bellman-Ford Algorithms for Single Source Shortest Path
Time Complexity: O(VE)
Space Complexity: O(V)
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

struct Edge {
    int from, to, weight;
    Edge(int from, int to, int weight) : from(from), to(to), weight(weight) {}
};

int main() {
    int V, E;
    cin >> V >> E;
    vector<Edge> edges;
    for (int i = 0; i < E; i++) {
        int from, to, weight;
        cin >> from >> to >> weight;
        edges.push_back(Edge(from, to, weight));
    }
    vector<int> dist(V, INT_MAX);
    dist[0] = 0;
    for (int i = 0; i < V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int from = edges[j].from;
            int to = edges[j].to;
            int weight = edges[j].weight;
            if (dist[from] != INT_MAX && dist[from] + weight < dist[to]) {
                dist[to] = dist[from] + weight;
            }
        }
    }
    for (int i = 0; i < V; i++) {
        cout << dist[i] << " ";
    }
    cout << endl;
    return 0;
}


/*
Dry Run -
Input:
5 8
0 1 4
0 2 1
1 2 2
1 3 5
2 1 2
2 3 8
2 4 10
3 4 2
Output:
0 3 1 6 8

Working of this code -
Initially, all the distances are set to infinity except the distance of the source vertex which is 
set to 0.
We iterate over all the edges V-1 times. In each iteration, we relax all the edges.
If the distance of the source vertex of the edge is not infinity and the distance of the source
vertex plus the weight of the edge is less than the distance of the destination vertex, we update
the distance of the destination vertex.



*/





