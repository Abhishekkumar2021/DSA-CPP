#include<iostream>
using namespace std;
int main(){
    string s;
    getline(cin,s);
    for(int i=0; i<s.length(); i++){
        s[i] = s[i]^11;
    }
    cout<<s;
}