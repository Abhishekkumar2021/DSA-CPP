#include<bits/stdc++.h>
using namespace std;

/*
Armstrong Number
----------------
Time: O(logN)
Space: O(1)

*/

int main(){
    int n;
    cin>>n;
    int sum=0;
    int temp=n;
    while(temp>0){
        int last=temp%10;
        sum+=pow(last,3);
        temp/=10;
    }
    if(sum==n){
        cout<<"Armstrong Number";
    }
    else{
        cout<<"Not Armstrong Number";
    }
}



