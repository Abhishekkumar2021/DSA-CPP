#include <bits/stdc++.h>
#include "Graph.h"
using namespace std;
int main()
{
    cout << "Enter number of nodes : ";
    int n;
    cin >> n;
    cout << "Enter number of edges : ";
    int e;
    cin >> e;
    cout << "Enter edges : \n";
    // GraphUsingAdjacencyList g(n, e);
    // g.takeInput();
    GraphUsingEdgeList g(n, e);
    g.takeInput();
    // g.print();
    g.kruskal();
    /*
    Tested succesfully.....
    g.print();
    g.BFSPrint(1);
    g.DFSPrint(3);
    GraphUsingAdjacencyList square = g.graphSquare();
    square.print();
    cout << g.outDegree(2) << endl;
    cout << g.inDegree(2) << endl;
    GraphUsingAdjacencyList transpose = g.transposeGraph();
    transpose.print();
    g.takeInput();
    g.print();
    vector<vector<int>> allComponents = g.getAllComponents();
    for (int i = 0; i < allComponents.size(); i++)
    {
        for (int j = 0; j < allComponents[i].size(); j++)
        {
            cout << allComponents[i][j] << " ";
        }
        cout << "\n";
    }
    bool isConnected = g.hasPath(1, 4);
    cout << isConnected << endl;
    g.BFSPrintCormen(1);
    vector<int> path = g.getPath(1, 4);
    for (auto element : path)
        cout << element << " "
    WeightedGraph wg(n, e);
    wg.takeInput();
    wg.print();
    */

    return 0;
}
/*

---------
9
6
1 2
3 4
2 3
5 6
6 7
8 9
---------
5
5
1 2
2 3
3 4
4 5
5 1

------------
5
4
1 2 10
2 3 20
2 4 30
4 5 40

--------kruskal's-------
5
7
1 2 3
2 3 5
3 4 7
2 4 6
4 1 5
2 5 7
3 5 8


......
4
6
1 2 1
2 3 5
1 3 4
2 4 2
3 4 6
1 4 3


*/
