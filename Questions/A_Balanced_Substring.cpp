#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int pa[n],pb[n];
        if(s[n-1]=='a') pa[n-1] = 1;
        else pa[n-1] = 0;
        if(s[n-1]=='b') pb[n-1] = 1;
        else pb[n-1] = 0;
        for(int i=n-2; i>=0; i++){
            if(s[i]=='a'){
                pa[i] = pa[i+1] + 1;
                pb[i] = pb[i+1];
            }
            if(s[i]=='b'){
                pa[i] = pa[i+1];
                pb[i] = pb[i+1] + 1;
            }
        }
        int l = 0;
        int r = n-1;
        while(pa[l]!=pb[l])
        l++;
        while(pa[r]!=pb[r])
        r--;
        if(pa[0]==0|| pb[0]==0)
        cout<<"-1 -1\n";
        else
        cout<<l+1<<" "<<r+1<<"\n";
    }
}