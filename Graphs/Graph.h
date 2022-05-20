#include <bits/stdc++.h>
using namespace std;
class GraphUsingAdjacencyList
{
    vector<int> *adjacencyList;
    int n;
    int e;
    void runDFS(bool visited[], int startNode)
    {
        if (visited[startNode] == true)
            return;
        visited[startNode] = true;
        for (auto element : adjacencyList[startNode])
        {
            runDFS(visited, element);
        }
    }
    void runBFS(int startNode, bool visited[])
    {
        int distance[n + 1];
        queue<int> pendingNodes;
        visited[startNode] = true;
        pendingNodes.push(startNode);
        while (!pendingNodes.empty())
        {
            int start = pendingNodes.front();
            pendingNodes.pop();
            cout << start << " ";
            for (auto element : adjacencyList[start])
            {
                if (visited[element] == true)
                {
                    continue;
                }
                visited[element] = true;
                pendingNodes.push(element);
            }
        }
    }
    void DFSPrint_helper(bool visited[], int startNode)
    {
        if (visited[startNode] == true)
            return;
        visited[startNode] = true;
        cout << startNode << " ";
        for (auto element : adjacencyList[startNode])
        {
            DFSPrint_helper(visited, element);
        }
    }
    void BFSPrint_helper(bool *visited, int startNode)
    {
        int distance[n + 1];
        distance[0] = 0;
        distance[startNode] = 0;
        queue<int> pendingNodes;
        visited[startNode] = true;
        pendingNodes.push(startNode);
        while (!pendingNodes.empty())
        {
            int start = pendingNodes.front();
            pendingNodes.pop();
            cout << start << " ";
            for (auto element : adjacencyList[start])
            {
                if (visited[element] == true)
                {
                    continue;
                }
                visited[element] = true;
                distance[element] = distance[start] + 1;
                pendingNodes.push(element);
            }
        }
    }
    void getAllComponents_helper(bool visited[], int startNode, vector<int> &component)
    {
        visited[startNode] = true;
        component.push_back(startNode);
        for (auto element : adjacencyList[startNode])
        {
            if (!visited[element])
            {
                getAllComponents_helper(visited, element, component);
            }
        }
    }

public:
    GraphUsingAdjacencyList(int n, int e)
    {
        this->n = n;
        this->e = e;
        this->adjacencyList = new vector<int>[n + 1];
        adjacencyList[0].push_back(0);
    }
    ~GraphUsingAdjacencyList()
    {
        delete[] adjacencyList;
    }
    void takeInput()
    {
        for (int i = 1; i <= e; i++)
        {
            int startNode;
            cin >> startNode;
            int endNode;
            cin >> endNode;
            adjacencyList[startNode].push_back(endNode);
            adjacencyList[endNode].push_back(startNode); // if we want undirected graph then we can uncomment this line.
        }
    }
    int outDegree(int v)
    {
        return adjacencyList[v].size();
    }
    int inDegree(int v)
    {
        int count = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < adjacencyList[i].size(); j++)
            {
                if (adjacencyList[i][j] == v)
                    count++;
            }
        }
        return count;
    }
    void print()
    {
        for (int i = 1; i <= n; i++)
        {
            cout << i << " : ";
            for (int j = 0; j < adjacencyList[i].size(); j++)
            {
                cout << adjacencyList[i][j] << " ";
            }
            cout << "\n";
        }
    }
    GraphUsingAdjacencyList transposeGraph()
    {
        vector<int> *newAdjacencyList = new vector<int>[n + 1];
        for (int i = 1; i <= n; i++)
        {
            for (auto element : adjacencyList[i])
            {
                newAdjacencyList[element].push_back(i);
            }
        }
        GraphUsingAdjacencyList newGraph(n, e);
        newGraph.adjacencyList = newAdjacencyList;
        return newGraph;
    }
    GraphUsingAdjacencyList graphSquare()
    {
        vector<int> *newAdjacencyList = new vector<int>[n + 1];
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < adjacencyList[i].size(); j++)
            {
                int element = adjacencyList[i][j];
                newAdjacencyList[i].push_back(element);
                for (int k = 0; k < adjacencyList[element].size(); k++)
                {
                    int toPush = adjacencyList[element][k];
                    if (toPush != i)
                        newAdjacencyList[i].push_back(toPush);
                }
            }
        }
        GraphUsingAdjacencyList newGraph(n, e);
        newGraph.adjacencyList = newAdjacencyList;
        return newGraph;
    }

    bool hasPath(int startNode, int endNode)
    {
        bool visited[n + 1] = {false};
        visited[0] = true;
        runDFS(visited, startNode);
        return visited[endNode];
    }

    vector<vector<int>> getAllComponents()
    {
        bool visited[n + 1] = {false};
        visited[0] = true;
        vector<vector<int>> allComponents;
        for (int i = 1; i <= n; i++)
        {
            vector<int> component;
            if (!visited[i])
            {
                getAllComponents_helper(visited, i, component);
                allComponents.push_back(component);
            }
        }
        return allComponents;
    }

    void DFSPrint(int startNode)
    {
        bool visited[n + 1];
        visited[0] = true;
        for (int i = 1; i <= n; i++)
        {
            visited[i] = false;
        }
        DFSPrint_helper(visited, startNode);
        for (int i = 1; i <= n; i++)
        {
            if (!visited[i])
            {
                DFSPrint_helper(visited, i);
            }
        }
    }

    void BFSPrint(int startNode)
    {
        bool visited[n + 1] = {false};
        visited[0] = true;
        BFSPrint_helper(visited, startNode);
        for (int i = 1; i <= n; i++)
        {
            if (!visited[i])
            {
                BFSPrint_helper(visited, i);
            }
        }
    }
    vector<int> getPath_helper(int startNode, int endNode, bool visited[])
    {
        visited[startNode] = true;
        vector<int> path;
        if (startNode == endNode)
        {
            path.push_back(startNode);
            return path;
        }
        for (auto element : adjacencyList[startNode])
        {
            if (!visited[element])
            {
                visited[element] = true;
                path = getPath_helper(element, endNode, visited);
                if (path.size() != 0)
                {
                    path.insert(path.begin(), startNode);
                    return path;
                }
            }
        }
        return path;
    }
    vector<int> getPath(int startNode, int endNode)
    {
        bool visited[n + 1] = {false};
        visited[0] = true;
        return getPath_helper(startNode, endNode, visited);
    }
    bool isConnected()
    {
        bool visited[n + 1] = {false};
        runDFS(visited, 1);
        for (int i = 0; i <= n; i++)
        {
            if (!visited[i])
                return false;
        }
        return true;
    }
    void BFSPrintCormen(int startNode)
    {
        char color[n + 1];
        color[0] = 'b';
        for (int i = 0; i <= n; i++)
        {
            color[i] = 'w';
        }
        queue<int> pendingNodes;
        pendingNodes.push(startNode);
        color[startNode] = 'g';
        while (!pendingNodes.empty())
        {
            int front = pendingNodes.front();
            pendingNodes.pop();
            cout << front << " ";
            for (auto element : adjacencyList[front])
            {
                if (color[element] == 'w')
                {
                    pendingNodes.push(element);
                    color[element] = 'g';
                }
            }
            color[front] = 'b';
        }
    }
};

/*        Pending class        */
class GraphUsingAdjacencyMatrix
{
    int **matrix;
    int *parent;
    int e;
    int n;

public:
    GraphUsingAdjacencyMatrix(int n, int e)
    {
        this->n = n;
        this->e = e;
        this->matrix = new int *[n + 1];
        this->parent = new int[n+1];
        for (int i = 0; i <= n; i++)
        {
            this->matrix[i] = new int[n + 1];
        }
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                matrix[i][j] = 0;
            }
        }
    }
    void takeInput()
    {
        for (int i = 0; i < e; i++)
        {
            int first;
            int second;
            cin >> first >> second;
            matrix[first][second] = 1;
            matrix[second][first] = 1; //  if graph is undirected then uncomment it.
        }
    }
    int outDegree(int v)
    {
        int count = 0;
        for (int i = 1; i <= n; i++)
        {
            if (matrix[v][i] == 1)
            {
                count++;
            }
        }
        return count;
    }
    int inDegree(int v)
    {
        int count = 0;
        for (int i = 1; i <= n; i++)
        {
            if (matrix[i][v] == 1)
            {
                count++;
            }
        }
        return count;
    }
    void transposeGraph()
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }

    void print()
    {
        for (int i = 1; i <= n; i++)
        {
            cout << i << " : ";
            for (int j = 1; j <= n; j++)
            {
                if (matrix[i][j] == 1)
                {

                    cout << j << " ";
                }
            }
            cout << "\n";
        }
    }
    void fillParent(){
        
    }
};

//----------------------weighted graphs------------------------

class WeightedGraph
{
    int n;
    int e;
    vector<pair<int, int>> *List;

public:
    WeightedGraph(int n, int e)
    {
        this->n = n;
        this->e = e;
        List = new vector<pair<int, int>>[n + 1];
    }
    void takeInput()
    {
        for (int i = 1; i <= n; i++)
        {
            int first;
            int second;
            int weight;
            cin >> first >> second >> weight;
            pair<int, int> p1 = {second, weight};
            pair<int, int> p2 = {first, weight};
            List[first].push_back(p1);
            List[second].push_back(p2);
        }
    }
    void print()
    {
        for (int i = 1; i <= n; i++)
        {
            cout << i << " : ";
            for (auto pair : List[i])
            {
                cout << "(" << pair.first << ", " << pair.second << ")"
                     << " ";
            }
            cout << "\n";
        }
    }
};

//--------------- Graph using the edgeList-----------

class Edge
{
public:
    int source;
    int destination;
    int weight;
    Edge()
    {
        source = 0;
        destination = 0;
        weight = 0;
    }
    Edge(int source, int destination, int weight)
    {
        this->source = source;
        this->destination = destination;
        this->weight = weight;
    }
};

bool compare(Edge a, Edge b)
{
    return a.weight < b.weight;
}
class GraphUsingEdgeList
{
    Edge *List;
    int n;
    int e;

public:
    GraphUsingEdgeList(int n, int e)
    {
        this->n = n;
        this->e = e;
        List = new Edge[e];
    }
    ~GraphUsingEdgeList()
    {
        delete[] List;
    }
    void takeInput()
    {
        for (int i = 0; i < e; i++)
        {
            int startNode;
            int endNode;
            int weight;
            cin >> startNode >> endNode >> weight;
            List[i] = Edge(startNode, endNode, weight);
        }
    }
    void print()
    {
        for (int i = 0; i < e; i++)
        {
            cout << List[i].source << "-----(" << List[i].weight << ")-----" << List[i].destination << "\n";
        }
    }
    int findParent(int *parent, int element)
    {
        if (parent[element] == element)
        {
            return element;
        }
        return findParent(parent, parent[element]);
    }
    void kruskal()
    {
        // The first step is to sort the List on the based of weights.
        bool visited[n + 1] = {false};
        visited[0] = true;
        Edge MST[n - 1];

        sort(List, List + e, compare);
        int parent[n + 1];
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
        int count = 0, i = 0;
        while (count != n - 1)
        {
            Edge current = List[i];
            int sourceParent = findParent(parent, current.source);
            int destinationParent = findParent(parent, current.destination);
            if (sourceParent != destinationParent)
            {
                MST[count] = current;
                count++;
                parent[current.source] = destinationParent;
            }
            i++;
        }
        for (int i = 0; i < n - 1; i++)
        {
            cout << MST[i].source << " " << MST[i].destination << "\n";
        }
        for (int i = 1; i <= n; i++)
        {
            cout << parent[i] << " ";
        }
    }
};

/*

Kruskal's algorithm works on a weighted and a connected graph to find out the MST(Minimum Spanning Tree).

*/
