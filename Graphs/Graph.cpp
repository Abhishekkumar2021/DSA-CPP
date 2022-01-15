#include <bits/stdc++.h>
using namespace std;
void runDFS(int **Edges, int numVertices, bool *visited, int startingVertex)
{
    visited[startingVertex] = true;
    for (int i = 0; i < numVertices; i++)
    {
        if (i == startingVertex)
            continue;
        if (Edges[startingVertex][i] == 1)
        {
            if (visited[i])
            {
                continue;
            }
            runDFS(Edges, numVertices, visited, i);
        }
    }
}
void printDFS(int **Edges, int numVertices, bool *visited, int startingVertex)
{
    cout << startingVertex << endl;
    visited[startingVertex] = true;
    for (int i = 0; i < numVertices; i++)
    {
        if (i == startingVertex)
            continue;
        if (Edges[startingVertex][i] == 1)
        {
            if (visited[i])
            {
                continue;
            }
            printDFS(Edges, numVertices, visited, i);
        }
    }
}

void printBFS(int **Edges, int numVertices, bool *visited, int startingVertex)
{
    queue<int> pending;
    pending.push(startingVertex);
    while (pending.size() != 0)
    {
        int front = pending.front();
        pending.pop();
        cout << front << endl;
        visited[front] = true;
        for (int i = 0; i < numVertices; i++)
        {
            if (i == front)
            {
                continue;
            }
            if (Edges[front][i] == 1 && !visited[i])
            {
                pending.push(i);
                visited[i] = true;
            }
        }
    }
}

void BFS(int **Edges, int numVertices)
{
    bool *visited = new bool[numVertices];
    for (int i = 0; i < numVertices; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < numVertices; i++)
    {
        if (!visited[i])
            printBFS(Edges, numVertices, visited, i);
    }
    delete[] visited;
}
void printDFS(int **Edges, int numVertices)
{
    bool *visited = new bool[numVertices];
    for (int i = 0; i < numVertices; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < numVertices; i++)
    {
        if (!visited[i])
            printDFS(Edges, numVertices, visited, i);
    }
    delete[] visited;
}
bool hasPath(int **Edges, int numVertices, int startingVertex, int endingVertex)
{
    bool *visited = new bool[numVertices];
    for (int i = 0; i < numVertices; i++)
    {
        visited[i] = false;
    }
    runDFS(Edges, numVertices, visited, startingVertex);
    return visited[endingVertex];
}
bool isConnected(int **Edges, int numVertices)
{
    bool *visited = new bool[numVertices];
    for (int i = 0; i < numVertices; i++)
    {
        visited[i] = false;
    }
    runDFS(Edges, numVertices, visited, 0);
    for (int i = 0; i < numVertices; i++)
    {
        if (visited[i] == false)
            return false;
    }
    return true;
}
int runBFSandStore(int **Edges, int numVertices, bool *visited, int startingVertex, vector<int> &v)
{
    int edges = 0;
    queue<int> pending;
    pending.push(startingVertex);
    while (pending.size() != 0)
    {
        int front = pending.front();
        pending.pop();
        v.push_back(front);
        visited[front] = true;
        for (int i = 0; i < numVertices; i++)
        {
            if (i == front)
            {
                continue;
            }
            if (Edges[front][i] == 1 && !visited[i])
            {
                pending.push(i);
                visited[i] = true;
                edges++;
            }
        }
    }
    return edges;
}
vector<pair<vector<int>, int>> allComponents(int **Edges, int numVertices)
{
    vector<pair<vector<int>, int>> output;
    bool *visited = new bool[numVertices];
    for (int i = 0; i < numVertices; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < numVertices; i++)
    {
        if (!visited[i])
        {
            pair<vector<int>, int> edgeAndComponents;
            vector<int> component;
            int e = runBFSandStore(Edges, numVertices, visited, i, component);
            edgeAndComponents.first = component;
            edgeAndComponents.second = e;
            output.push_back(edgeAndComponents);
        }
    }
    return output;
}

int main()
{
    int numVertices;
    int numEdges;
    cout << "Enter Number of edges : ";
    cin >> numEdges;
    cout << "Enter number of Vertices : ";
    cin >> numVertices;
    int **Edges = new int *[numVertices];
    for (int i = 0; i < numVertices; i++)
    {
        Edges[i] = new int[numVertices];
        for (int j = 0; j < numVertices; j++)
        {
            Edges[i][j] = 0;
        }
    }
    cout << "Enter connected edges : " << endl;
    for (int i = 0; i < numEdges; i++)
    {
        int first, second;
        cin >> first;
        cin >> second;
        Edges[first][second] = 1;
        Edges[second][first] = 1;
    }
    // BFS(Edges, numVertices);

    if (hasPath(Edges, numVertices, 1, 4))
        cout << "They are connected." << endl;
    vector<pair<vector<int>, int>> AllComponents = allComponents(Edges, numVertices);
    for (int i = 0; i < AllComponents.size(); i++)
    {
        for (int j = 0; j < AllComponents[i].first.size(); j++)
            cout << AllComponents[i].first[j] << " ";
        cout << "number of edges = " << AllComponents[i].second << endl;
    }
    for (int i = 0; i < numVertices; i++)
    {
        delete[] Edges[i];
    }
    delete[] Edges;
}
// 4 4 0 1 0 3 1 2 2 3