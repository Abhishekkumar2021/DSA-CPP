#include<bits/stdc++.h>
using namespace std;

class DSU{
    vector<int> parent;
    vector<int> rank;
    public:
    DSU(int n){
        parent.resize(n);
        rank.resize(n);
        for(int i=0; i<n; i++){
            parent[i] = i;
            rank[i] = 0;
        }
    }

    // 'Path compression
    int findParent(int x){
        if(parent[x] == x) return x;
        return parent[x] = findParent(parent[x]);
    }

    // Union by rank
    void unionSet(int x, int y){
        int s1 = findParent(x);
        int s2 = findParent(y);
        if(s1 != s2){
            if(rank[s1] < rank[s2]){
                parent[s1] = s2;
            }
            else if(rank[s1] > rank[s2]){
                parent[s2] = s1;
            }
            else{
                parent[s2] = s1;
                rank[s1]++;
            }
            parent[s1] = s2;
        }
    }

    void drawGraph(string filename = "graph.dot"){
        ofstream fout(filename + ".dot");
        fout << "digraph {" << endl;
        for(int i=0; i<parent.size(); i++){
            fout << i << " -> " << parent[i] << endl;
        }
        fout << "}" << endl;
        fout.close();
        system(("dot -Tpng " + filename + ".dot -o " + filename + ".png").c_str());
    }
};