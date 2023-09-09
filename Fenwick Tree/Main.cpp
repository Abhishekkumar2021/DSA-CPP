#include<bits/stdc++.h>
using namespace std;

class FenwickTree{
    vector<int> bit;
    int n;
    public:
    FenwickTree(int n){
        this->n = n;
        bit.resize(n+1, 0);
    }

    /*
    idx = 1100
    -idx = 0100

    idx & (-idx) = 0100 = lsb

    */

    int query(int idx){
        int ans = 0;
        while(idx > 0){
            ans += bit[idx];
            int lsb = idx & (-idx);
            idx -= lsb;
        }
        return ans;
    }

    void update(int idx, int add){
        while(idx <= n){
            bit[idx] += add;
            int lsb = idx & (-idx);
            idx += lsb;
        }
    }
};