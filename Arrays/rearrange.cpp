#include<bits/stdc++.h>
using namespace std;
void arrange(vector<int> &A) {
    int n = A.size();
    for(int i=0; i<n; i++){
        A[i] =A[i]+ (A[A[i]]%n)*n;
    }
    for(int i=0; i<n; i++){
        A[i]=A[i]/n;
    }
}

int main(){
    vector<int> A = {0,1,4,5,3,2};
    arrange(A);
    for(auto x: A)
    cout<<x<<" ";
}