#include<bits/stdc++.h>
using namespace std;
class Box{
    int l,b,h;
    public:
    Box(){
        l=0;
        b=0;
        h=0;
    }
    Box(int l,int b,int h){
        this->l = l;
        this->b = b;
        this->h = h;
    }
    Box(Box &B){
        this->l = B.l;
        this->b = B.b;
        this->h = B.h;
    }
    int getLength(){
        return l;
    }
    int getBreadth (){
        return b;
    }
    int getHeight (){
        return h;
    }
    long long CalculateVolume(){
        return l*b*h;
    }
    bool operator<(Box &B){
        return ((l<B.l) || (b<B.b && l==B.l) || (h<B.h && l==B.l && b==B.b));
    }
  
};

int main(){
    Box B(3,4,5);
    cout<<B.getHeight();
    Box C(4,5,6);
    cout<<(B<C);
}