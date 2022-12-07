#include<bits/stdc++.h>
using namespace std;

vector<int> sieve(int A) {
    vector<int> res(A+1);
    res[0] = res[1] = -1;
    for(int i=2; i<=A; i++){
        res[i] = i;
    }
    vector<int> final;
    for(int i=2; i<=A; i++){
        if(res[i]!=-1){
            final.push_back(res[i]);
            for(int j=i*2; j<=A; j+=i){
                res[j] = -1;
            }
        }
    }
    return final;
}
int main(){
    vector<int> primes = sieve(10);
}