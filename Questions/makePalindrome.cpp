#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
    cin>>arr[i];
    int p = 0;
    int q = n-1;
    while(p<q){
        cout<<p<<" "<<q<<"\n";
        if(arr[p]==arr[q]){
            p++;
            q--;

        }else if(arr[p]<arr[q]){
            p++;
            arr[p] = arr[p] + arr[p-1]; 
            arr[p-1] = INT_MAX;
        }else{
            q--;
            arr[q] = arr[q] + arr[q+1];
            arr[q+1] = INT_MAX; 
        }
    }
    for(int i=0; i<n; i++){
        if(arr[i]==INT_MAX)
        continue;
        cout<<arr[i]<<" ";
    }
}