#include<iostream>
using namespace std;
int main(){
    int n = 13;
    cout<<n<<"\n";
    n = n&(n-1); 
    /*
        n = 1101
        when we calculate n - 1 the all the bits from last upto the first 1 all bits gets inverted.
        now when we perform n & n-1 all the bits in the result is equals to zero including the first 1 and all others remains same.
        Conclusion - when we perform n&(n-1) it stripes off the last set bit from the number
    */
    cout<<n<<"\n";
    n = n&(n-1);
    cout<<n<<"\n";
    n = n&(n-1);

}