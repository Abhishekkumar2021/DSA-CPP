#include<bits/stdc++.h>
using namespace std;
int solve(vector<int> &arr, int B) {
    int n = arr.size();
    int prefix[n];
    prefix[0] = arr[0];
    int suffix[n];
    suffix[n-1] = arr[n-1];
    for(int i=1; i<n; i++){
        prefix[i] = prefix[i-1] + arr[i];
    }
    for(int i=n-2; i>=0; i--){
        suffix[i] = suffix[i+1] + arr[i];
    }
    int best = suffix[n-B];
    for(int i=0; i<B-1; i++){
        best = max(best,(prefix[i] + suffix[n-(B-i)+1]));
        
    }
    return best;
}
int main(){
    vector<int> arr = {1,2,3,-4,-5,4,6,7};
    cout<<solve(arr,5);
}