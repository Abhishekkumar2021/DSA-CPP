#include<bits/stdc++.h>
using namespace std;

template <typename T>
class pairs{
   T first;
T second;

public:
    void set_first(T first){
        this->first = first;
    }
    void set_second(T second){
        this->second = second;
    }
    T get_first(){
        return first;
    }
    T get_second(){
        return second;
    }
};


int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    pairs <int>P;
    P.set_first(10);
    P.set_second(20);
    cout<<P.get_first()<<" "<<P.get_second()<<endl;
    
}
