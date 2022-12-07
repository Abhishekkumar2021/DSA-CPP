#include<bits/stdc++.h>
using namespace std;

string solve(string A, int B) {
    char ch = A[0];
    string ans = "";
    vector<int>index;
    int cnt = 0;
    for(int i=0; i<A.length(); i++){
        if(A[i]==ch){
            cnt++;
        }else{
            if(cnt==B){
                cnt = 0;
                index.push_back(i);
            }
            ch = A[i];
            cnt++;
        }
    }
    if(cnt==B){
        cnt = 0;
        index.push_back(A.size());
    }
    int j=0;
    for(int i=0; i<A.size(); i++){
        if(i>index[j]-B && i<=index[j]){
            //do nothing
        }else{
            ans+=A[i];
        }
        if(index[j]==i-1)
        j++;
    }
    for(auto &it : index)
    cout<<it<<"\n";
    return ans;
}

int main(){
    string A = "aaabbcddd";
    int B = 3;
    cout<<solve(A,B)<<"\n";
}