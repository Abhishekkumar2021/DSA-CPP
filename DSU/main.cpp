#include<bits/stdc++.h>
using namespace std;

class DSU{
    vector<int>parent;
    int n;
    public:
    DSU(int n){
        this->n = n;
        for(int i=0; i<=n; i++) parent.push_back(i);
    }
    int find(int x){
        if(parent[x]==x) return x;
        return find(parent[x]);
    }
    bool sameSet(int a,int b){
        return find(a)==find(b);
    }
    int join(int a,int b){
        int pa = find(a);
        int pb = find(b);
        if(pa==pb) return 0;
        parent[pa] = pb;
    }
    int numSets(){
        set<int> s;
        for(int i=1; i<=n; i++){
            s.insert(find(i));
        }
        return s.size();

    }
};

void solve(){
    DSU d(10);
    cout<<d.numSets()<<"\n";
    d.join(3,4);
    cout<<d.numSets()<<"\n";
    d.join(7,4);
    cout<<d.numSets()<<"\n";
    d.join(3,8);
    cout<<d.numSets()<<"\n";
    d.join(3,9);
    cout<<d.numSets()<<"\n";

}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    solve();
}