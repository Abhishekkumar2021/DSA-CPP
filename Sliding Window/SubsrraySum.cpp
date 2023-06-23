/*
Given an array find out the sum of all the subsrray of size k
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> subarraySum(int arr[], int n, int k)
{
    vector<int> ans;
    int sum = 0;
    for (int i = 0; i < k; i++)
    {
        sum += arr[i];
    }
    ans.push_back(sum);
    for (int i = k; i < n; i++)
    {
        sum += arr[i] - arr[i - k];
        ans.push_back(sum);
    }
    return ans;
}