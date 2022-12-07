#include<bits/stdc++.h>
using namespace std;
vector<int> primesum(int A) {
    vector<bool> arr(A+1,1);
    arr[0] = false; 
    arr[1] = false; 
    arr[2] = true;
    for(int i=2; i<=A; i++){
        if(arr[i]){
            cout<<i<<" ";
            for(int j=2*i; j<=A; j+=i){
                arr[j] = false;
            }
        }
    }
    set<int> prime;
    for(int i=2; i<=A; i++){
        if(arr[i])
        prime.insert(i);
    }
    for(auto e: prime){
        int rem = A - e;
        if(prime.count(rem)>0){
            return {e,rem};
        }
    }
}

int main(){
    cout<<primesum(10)[0]<<", "<<primesum(10)[1]<<"\n";
}
