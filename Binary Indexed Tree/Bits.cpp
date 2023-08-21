#include<bits/stdc++.h>
using namespace std;

int lastSet(int n){
    return (n & (-n));
    // n = 10100
    // -n = 01100
    // n & -n = 00100
}

int removeLastSet(int n){
    int mask = n & (-n);
    return n - mask;
    // n = 10100
    // mask = 00100
    // n - mask = 10000
}