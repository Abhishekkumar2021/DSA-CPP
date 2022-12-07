#include<bits/stdc++.h>
using namespace std;
int indexOf(vector<int> arr, int x){
    int s = 0;
    int e = arr.size() - 1;
    int mid;
    while(e-s>1){
        mid = (s+e)/2;
        if(arr[mid]<x)
        s = mid + 1;
        else{
            e = mid;
        }
    }
    if(arr[s]==x)
    return s;
    if(arr[e]==x)
    return e;
    return -1;
}
int lowerBound(vector<int> arr, int x){
    int s = 0;
    int e = arr.size() - 1;
    int mid;
    while(e-s>1){
        mid = (s+e)/2;
        if(arr[mid]<x)
        s = mid + 1;
        else{
            e = mid;
        }
    }
    if(arr[s]<=x)
    return s;
    if(arr[e]<=x)
    return e;
    return -1;
}
int upperBound(vector<int> arr, int x){
    int s = 0;
    int e = arr.size() - 1;
    int mid;
    while(e-s>1){
        mid = (s+e)/2;
        if(arr[mid]<=x)
        s = mid + 1;
        else{
            e = mid;
        }
    }
    if(arr[s]>x)
    return s;
    if(arr[e]>x)
    return e;
    return -1;
}
int main(){
    vector<int> arr = {1,2,3,4,5,5,5,5,5,5,6,7,8,9};
    // int s = upper_bound(arr.begin(),arr.end(),5) - arr.begin();
    cout<<indexOf(arr,5)<<"\n";
    cout<<lowerBound(arr,5)<<"\n";
    cout<<upperBound(arr,5)<<"\n";
    // cout<<s<<"\n";
}