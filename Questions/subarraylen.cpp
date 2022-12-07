#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        int cnt = 0;
        map<int,int> m;
        for(int i=0; i<n; i++){
            int len = arr[i];
            int si = (i-len+1>=0)?i-len+1:0;
            if(m.count(arr[i])>0 && m[arr[i]]>=si) si = m[arr[i]]+1;
            int ei = (si+len-1>=n)?n-1:si+len-1;
            if(ei-si+1!=len || si>ei) continue;
            cnt+=min(i-si+1,n-ei);
            m[arr[i]] = i;
        }
        cout<<cnt<<"\n";
    }
}