#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,x0,y0;
    cin>>n>>m;
    int x[n],y[n];
    for(int i=0; i<n; i++){
        cin>>x[i]>>y[i];
    }
    cin>>x0>>y0;
    set<float> slope;
    for(int i=0; i<n; i++ ){
        int delX = x0 - x[i];
        int delY = y0 - y[i];
        slope.insert((delY*1.0)/delX);
    }
    cout<<slope.size();
}