#include<iostream>
#include<cmath>
#include<iomanip>
#include<string>
using namespace std;

int* fun(int **arr, int n, int m){
    int *brr = new int[2];
    //array manipulation
    return brr;
}
int main(){
    float x = 21;
    float l = 0,r=x, mid;
    while(l<=r){
        mid = (l+r)/2;
        if(abs(mid*mid-x)<0.0001){
            break;
        }else if(mid*mid>x){
            r = mid;
        }else{
            l = mid;
        }
    }
    // cout<<setprecision(4)<<mid;
    char buf[10];
    sprintf(buf,"%.3f",mid);
    // cout<<buf;
    float ans = stof(buf);
    cout<<ans;



    // 2D matrix 

    int n = 4; //rows
    int m = 5; //columns
    // int arr[4][5];

    int **arr = new int*[n];
    for(int i=0; i<n; i++){
        arr[i] = new int[m];
    }

    fun(arr,n,m);
    
}