#include<bits/stdc++.h>
using namespace std;


void printSubsets(vector<int> arr, vector<int> subset,int i,vector<vector<int>> &subsets){
    if(i==arr.size()){
        subsets.push_back(subset);
        return;
    }
    subset.push_back(0);
    printSubsets(arr,subset,i+1,subsets); //not included

    subset.pop_back();
    subset.push_back(1);
    printSubsets(arr,subset,i+1,subsets);
}


void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];
    vector<int> subset;

    vector<vector<int>> subsets;
    printSubsets(arr,subset,0,subsets);

    // cout<<subsets.size()



}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    solve();
}