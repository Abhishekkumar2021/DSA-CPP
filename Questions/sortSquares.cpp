#include<bits/stdc++.h>
using namespace std;
vector<int> solve(vector<int> &arr) {
    int n = arr.size();
    int r = 0;
    int l;
    for(int i=0; i<n; i++){
        if(arr[i]<0)
        r++;
        arr[i] = arr[i]*arr[i];
    }
    l = r-1;
    vector<int> ans;
    while(l>=0 && r<n){
        if(arr[l]<=arr[r]){
            ans.push_back(arr[l]);
            l--;
        }else{
            ans.push_back(arr[r]);
            r++;
        }
        if(l==-1){
            while(r<n){
                ans.push_back(arr[r]);
                r++;
            }
        }
        if(r==n){
            while(l>=0){
                ans.push_back(arr[l]);
                l--;
            }
           
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {-5,-4,-3,-2,-1,2,4,6,8};
    vector<int> ans = solve(arr);
    for(auto x : ans)
    cout<<x<<" ";
}