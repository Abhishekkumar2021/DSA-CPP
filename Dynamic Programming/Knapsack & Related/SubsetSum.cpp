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
    int sum = 11;
    int n = 6;
    cout << subsetSum(arr, n, sum);
}