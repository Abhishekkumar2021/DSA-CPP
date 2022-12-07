#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>  A = {5, 6, 7, 8, 9, 10, 3, 2, 1};
    int n = A.size();
    int s = 0;
    int e = n-1;
    int idx = -1;
    while(s<=e){
        int mid = (s+e)/2;
        if(A[mid]>A[mid+1] && A[mid]>A[mid-1]){
            idx = mid;
            break;
        }
        if(A[mid]<A[mid+1]){
            s = mid + 1;
        }else{
            e = mid -1;
        }
    }
    cout<<idx<<"\n";
}