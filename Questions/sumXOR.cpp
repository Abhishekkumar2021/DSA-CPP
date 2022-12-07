#include<bits/stdc++.h>
using namespace std;
int main(){
    int A = 7;
    int B = 5;
    int a,b,sum,carry = 0;
    int res = 0;
    for(int i=0; i<32; i++){
        a = (A&(1<<i))?1:0;
        b = (B&(1<<i))?1:0;
        sum = a^b^carry;
        if(sum==0 && carry==1){
            carry = 1;
        }
        else
        carry = a&b;
        if(sum){
            res = res^(1<<i);
        }
    }
    cout<<res;
}

