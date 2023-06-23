#include<bits/stdc++.h>
using namespace std;

vector<int> firstNegative(int arr[], int n, int k)
{
    int i = 0, j = 0;
    vector<int> ans;
    queue<int> q;
    while(j<k) {
        if(arr[j]<0) q.push(arr[j]);
        j++;
    }
    if(q.empty()) ans.push_back(0);
    else ans.push_back(q.front());
    while(j<n){
        if(arr[j]<0) q.push(arr[j]);
        if(arr[i]==q.front()) q.pop();
        i++;
        j++;
        
        // For the last window
        if(q.empty()) ans.push_back(0);
        else ans.push_back(q.front());
    }
    return ans;

}