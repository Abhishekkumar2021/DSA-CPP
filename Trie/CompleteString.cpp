#include<bits/stdc++.h>
#include"Trie1.h"
using namespace std;

string completeString(vector<string> v, int n){
    Trie t;
    for(auto &it : v){
        t.insert(it);
    }
    string longest = "";
    for(auto it: v){
        if(t.ifPrefixExist(it)){
            if(it.length()>longest.length()){
                longest = it;
            }else if(it.length()==longest.length() && it<longest){
                it = longest;
            }
        }
    }
    return longest;
    
}
int main(){
    vector<string> v = {"n","ni","nin","ninj","ninja","ninga"};
    cout<<completeString(v,5);
    
}