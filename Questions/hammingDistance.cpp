#include<bits/stdc++.h>
using namespace std;

int hamD(int a,int b){
    if(a==b)
    return 0;
    int cnt = 0;
    for(int i=0; i<32; i++){
        int bitA = a&(1<<i) ? 1:0;
        int bitB = b&(1<<i) ? 1:0;
        if(bitA!=bitB)
        cnt++;
    }
    return cnt;
}
int hammingDistance(const vector<int> &A) {
    int n1 = A.size();
    int m = 1000000007;
    int ans = 0;
    for(int i=0; i<n1; i++){
        for(int j=0; j<n1; j++){
            cout<<hamD(A[i],A[j])<<"\n";
            ans = (ans+hamD(A[i],A[j]))%m;

        }
    }
    return ans;
}

int main(){
    vector<int> v = {2,4,6};
    cout<<hammingDistance(v);
}