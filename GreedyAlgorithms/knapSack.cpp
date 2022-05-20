#include<bits/stdc++.h>
using namespace std;
class Object{
    public:
    int p;
    int w;
    float x;
    Object(int p,int w){
        this->p = p;
        this->w = w;
        this->x = 0;
    }
};
bool comparator(Object a, Object b){
    if(a.p/a.w > b.p/b.w)
    return true;
    return false;

}
int main(){ 
    //number of objects
    int n;
    cin>>n;
    vector<Object> objects;
    for(int i=0; i<n; i++) {
        //price and weight
        int p,w;
        cin>>p>>w;
        Object obj(p,w);
        objects.push_back(obj);
    }
    //the capacity
    int c;
    cin>>c;
    sort(objects.begin(),objects.end(),comparator);
    for(auto o :objects){
        cout<<o.p/o.w<<" ";
    }
}