#include<bits/stdc++.h>
using namespace std;

void solve(int open,int close,string output,vector<string> &result) {
    if(open==0 && close==0){
        result.push_back(output);
        return;
    }
    if(open>0){
        string newOutput1 = output + "(";
        solve(open-1,close,newOutput1,result);
    }
    if(close>open){
        string newOutput2 = output+")";
        solve(open,close-1,newOutput2,result);
    }
}
vector<string> balancedBracket(int n){
    int close = n;
    int open = n;
    string output = "";
    vector<string> result;
    solve(open,close,output,result);
    return result;

}
int main(){
    vector<string> result = balancedBracket(4);
    for(int i=0; i<result.size(); i++){
        cout<<result[i]<<endl;
    }
}