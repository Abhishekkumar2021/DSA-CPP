#include<bits/stdc++.h>
using namespace std;
int c = 0;
int main(){
    int A = 4;
    int n = 2*A- 1;
    for(int i=0; i<n; i++){
        for(int j= 0; j<n; j++){
            if(i==c || i==n-1-c || j==c || j== n-1-c){
            }
            cout<<A-c<<" ";  
        }
        c++;
        cout<<"\n";
    }
}