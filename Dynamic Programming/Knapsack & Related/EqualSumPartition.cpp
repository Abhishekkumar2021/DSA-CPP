#include <bits/stdc++.h>
using namespace std;

int subsetSum(int *arr, int n, int sum)
{
    if (sum == 0)
    {
        return 1;
    }
    if(n==0)
    return 0;
    if (arr[n - 1] <= sum)
    {
        return subsetSum(arr, n - 1, sum) || subsetSum(arr, n - 1, sum - arr[n - 1]);
    }
    else
    {
        return subsetSum(arr, n - 1, sum);
    }
}


int main()
{
    int arr[] = {1,2,3,7,8,10};
    int sum = 0;
    int n = 6;
    for(int i=0; i<n; i++)
    sum+=arr[i];
    if(sum%2==1)
    cout<<0;
    else
    cout << subsetSum(arr, n, sum/2);
}