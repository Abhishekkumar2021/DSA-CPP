/*
Given an array and sum find out the largest subarray with sum equal to given sum

Input:
arr = {5, 8, -4, -4, 9, -2, 2}
sum = 0

Output:
{8, -4, -4}
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> largestSubarraySum(int arr[], int n, int sum)
{
    vector<int> ans;
    int i = 0, j = 0, currSum = 0;
    while (j < n)
    {
        currSum += arr[j];
        if (currSum < sum)
        {
            j++;
        }
        else if (currSum == sum)
        {
            ans.push_back(i);
            ans.push_back(j);
            return ans;
        }
        else
        {
            while (currSum > sum)
            {
                currSum -= arr[i];
                i++;
            }
            j++;
        }
    }
    return ans;
}