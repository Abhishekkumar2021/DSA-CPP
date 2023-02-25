/*
Given an array arr of size n and an integer X. Find if there's a triplet in the array which sums up to the given integer X.


Example 1:

Input:
n = 6, X = 13
arr[] = [1 4 45 6 10 8]
Output:
1
Explanation:
The triplet {1, 4, 8} in 
the array sums up to 13.
Example 2:

Input:
n = 5, X = 10
arr[] = [1 2 4 3 6]
Output:
1
Explanation:
The triplet {1, 3, 6} in 
the array sums up to 10.
*/

#include<bits/stdc++.h>
using namespace std;

bool twoSum(int arr[], int sum, int left, int right){
    while(left<right){
        if(arr[left]+arr[right]==sum){
            return true;
        }
        else if(arr[left]+arr[right]<sum){
            left++;
        }
        else{
            right--;
        }
    }
    return false;
}

bool threeSum(int arr[], int n, int sum){
    sort(arr, arr+n);
    for(int i=0;i<n-2;i++){
        if(twoSum(arr, sum-arr[i], i+1, n-1)){
            return true;
        }
    }
    return false;
}

int main(){
    int n, sum;
    cin>>n>>sum;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<threeSum(arr, n, sum);
    return 0;
}