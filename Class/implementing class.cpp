#include<bits/stdc++.h>
#include "class.cpp"
using namespace std;
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    familymember mem;
    familymember *ptr = new familymember("Abhishek",20,"A+",73,172);
    cout<<"ptr contains : "<<ptr<<"\n";
    familymember newmem(*ptr);    //copy constructor.
    cout<<"For newmem........................................... "<<"\n";
    newmem.display();
    mem = newmem;
    cout<<"For mem........................................... "<<"\n";
    mem.display();
    familymember nextmem = newmem;   //copy constructor called not the default constructor......
    delete ptr;
}