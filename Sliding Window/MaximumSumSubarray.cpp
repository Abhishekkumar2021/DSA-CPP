/*
Given an array and k find out the maximum sum subarray of size k
*/

#include <bits/stdc++.h>
using namespace std;

int maximumSumSubarray(int arr[], int n, int k)
{
    int i = 0, j = 0, currSum = 0;
    while(j<k) {
        currSum += arr[j];
        j++;
    }
    int maxSum = max(maxSum, currSum);
    while(j<n){
        currSum += arr[j];
        currSum -= arr[i];
        maxSum = max(maxSum, currSum);
        i++;
        j++;
    }
    return maxSum;
}