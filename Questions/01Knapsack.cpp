#include<bits/stdc++.h>
using namespace std;

void generateAllSolutions(vector<int> arr, vector<int> subset,int i,vector<vector<int>> &solutions){
    if(i==arr.size()){
        solutions.push_back(subset);
        return;
    }
    subset.push_back(0);
    generateAllSolutions(arr,subset,i+1,solutions); //not included

    subset.pop_back();
    subset.push_back(1);
    generateAllSolutions(arr,subset,i+1,solutions);
}

vector<vector<int>> getValid(vector<vector<int>> solutions,int cap,vector<int> w){
    vector<vector<int>> ans;
    for(int i=0; i<solutions.size(); i++){
        int sum = 0;
        for(int j=0; j<solutions[i].size(); j++){
            
        }

    }
}

void solve(){
    int n,cap;
    cin>>n>>cap;
    vector<int> w(n),p(n);
    for(int i=0; i<n; i++){
        cin>>w[i];
        cin>>p[i];
    }

    vector<int> subset;
    vector<vector<int>> solutions;
    generateAllSolutions(w,subset,0,solutions);
    vector<vector<int>> validSolutions = getValid(solutions,cap,w);


}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    solve();
}