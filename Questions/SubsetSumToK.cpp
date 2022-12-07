#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
int sum(vi &arr){
    int sum = 0;
    for(int i=0; i<arr.size(); i++) sum+=arr[i];
    return sum;
}
vi getSet(int s, vi &arr){
    vi ans;
    for(int i=0; i<=15; i++){
        if(1&(s>>i)) ans.push_back(arr[i]);
    }
    return ans;
}

vvi f(vi &arr, int k){
    int n = arr.size();
    vvi ans;
    for(int set = 0; set<(1<<n); set++){
        vi curr = getSet(set,arr);
        if(sum(curr)==k) ans.push_back(curr);
    }
    return ans;
}
int main(){
	int n,k;
	cin>>n>>k;
	vi arr(n);
	for(int i=0; i<n; i++) cin>>arr[i];
	vvi ans = f(arr,k);
}