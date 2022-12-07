#include<bits/stdc++.h>
using namespace std;
int sqrt(int A) {
    int s = 0;
    int e = A;
    if(A==1)
    return 1;
    while(e-s>1){
        long long  mid = (s+e)/2;
        if(mid*mid<=A){
            s = mid;
        }else{
            e = mid;
        }
        
    }
    return s;
}

int main(){
    int x = 20;
    cout<<sqrt(x);
}