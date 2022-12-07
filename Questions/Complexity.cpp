#include<iostream>
using namespace std;
int main(){
    int n = 15,count=0;
    while (n) {
        n &= (n - 1);
        count++;
        cout<<n<<endl;
    }
    cout<<count;
    return 0;
}