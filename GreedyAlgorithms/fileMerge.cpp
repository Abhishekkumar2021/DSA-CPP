#include<bits/stdc++.h>
using namespace std;
int optimalMerge(int arr[], int n){
    if(n==2){
        return arr[0]+arr[1];
    }
    sort(arr, arr+n);
    arr[1] = arr[0]+arr[1];
    return arr[1] + optimalMerge(arr+1,n-1);
}
int main(){
    int n = 6;
    int arr[] = {2,3,4,5,6,7};
    cout<<optimalMerge(arr,n);
}