#include<bits/stdc++.h>
using namespace std;

bool ispalindrome(string &s, int i, int j){
    if(j==i) return true;
    while (i<=j){
        if( (s[i] != s[j])) return false;
       i++, j--; 
    } 
    return true;
    
}
int main(){
    string str = "banana";
    for(int i=0; i<str.length(); i++){
        cout<<"(0, "<<i<<") -> "<<ispalindrome(str,0,i)<<"\n";
    }
}