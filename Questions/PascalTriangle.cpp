#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>pascal = {1};
        if(n>=1){
            pascal = {1,1};
        }
        for(int i=2; i<=n; i++){
            vector<int> next;
            next.push_back(1);
            for(int j=0; j<pascal.size()-1; j++){
                next.push_back(pascal[j]+pascal[j+1]);
            }
            next.push_back(1);
            pascal = next;
        }
        for(int i=0; i<pascal.size(); i++){
            cout<<pascal[i]<<" ";
        }
        cout<<"\n";
        
    }
}