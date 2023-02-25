#include<bits/stdc++.h>
using namespace std;

long long solve(string s){
    int n = s.length();
    long long zero = 0;
    long long one = 0;
    long long ans = 0;
    for(int i=0;i<n;i++){
        if(s[i]=='0'){
            zero++;
        }
        else{
            one++;
        }
    }
    if(zero==0){
        ans = one*one;
        return ans;
    }
    else if(one==0){
        ans = zero*zero;
        return ans;
    }
    else{
        ans = zero*one;
    }
    // what is the difference between long and long long?

    long long max_consecutve_zero = 0;
    long long max_consecutve_one = 0;
    long long curr_zero = 0;
    long long curr_one = 0;
    for(int i=0;i<n;i++){
        if(s[i]=='0'){
            curr_zero++;
            curr_one = 0;
        }
        else{
            curr_one++;
            curr_zero = 0;
        }
        max_consecutve_zero = max(max_consecutve_zero,curr_zero);
        max_consecutve_one = max(max_consecutve_one,curr_one);
    }
    if(max_consecutve_zero*max_consecutve_zero>ans){
        ans = max_consecutve_zero*max_consecutve_zero;
    }
    if(max_consecutve_one*max_consecutve_one>ans){
        ans = max_consecutve_one*max_consecutve_one;
    }
    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        cout<<solve(s)<<endl;
    }
    return 0;
}