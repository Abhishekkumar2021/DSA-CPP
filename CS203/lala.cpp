#include<bits/stdc++.h>
using namespace std;int main() {
    int t;
    cin>>t;
    while(t--){
        int n,i;
        cin>>n;
        cin.ignore();
        string s1,s2;
        getline(cin,s1);
        getline(cin,s2);
        for( i=0; i<n; i++){
            if((s1[i]=='1')&&(s2[i]=='1')){
               cout<<"NO"<<endl;
               break;
            }
        }
        if(i==n)
        cout<<"YES"<<endl;
    }
}