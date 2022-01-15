#include<bits/stdc++.h>
#include"ourmap.h"
using namespace std;
int main(){
    ourmap<int> map;
    // map.insert("Hey",5);
    // map.insert("Hey", 15);
    // map.insert("Hey", 25);
    // map.remove("Hey");
    // cout<<map.getValue("Hey")<<endl;
    for(int i=1; i<20; i++){
        string key = "abc";
        key+='0'+i;
        map.insert(key,i);
        cout<<"current size : "<<map.currentSize()<<" and load factor : "<<map.getLoadFactor()<<endl;
    }
}