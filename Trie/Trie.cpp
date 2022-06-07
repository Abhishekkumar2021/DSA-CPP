#include<bits/stdc++.h>
#include"Trie2.h"
using namespace std;
int main(){
    Trie t;
    t.insert("abhishek");
    t.insert("abhijeet");
    t.insert("area");
    t.insert("area");
    t.insert("area");
    t.insert("area");
    t.insert("area");
    t.insert("areacal");
    cout<<t.countWordsEqualsTo("area");
    
}