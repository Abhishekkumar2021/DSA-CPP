#include <bits/stdc++.h>
using namespace std;
// int minSteps(int n){
//     if(n==1)
//     return 0;
//     int y=INT_MAX,z=INT_MAX;
//     int x = minSteps(n-1);
//     if(n%2==0){
//         y = minSteps(n/2);
//     }
//     if(n%3==0) {
//         z = minSteps(n/3);
//     }
//     int minStep = min(x,min(y,z));
//     return minStep + 1;

// }
int minSteps(int n, int *arr)
{
    if (n == 1)
    {
        arr[n] = 0;
        return 0;
    }
    int y = INT_MAX, z = INT_MAX;
    if (arr[n - 1] == -1)
        arr[n - 1] = minSteps(n - 1, arr);
    if (n % 2 == 0)
    {
        if (arr[n / 2] == -1)
            arr[n / 2] = minSteps(n / 2, arr);
        y = arr[n / 2];
    }
    if (n % 3 == 0)
    {
        if (arr[n / 3] == -1)
            arr[n / 3] = minSteps(n / 3, arr);
        z = arr[n / 3];
    }
    arr[n] = min(arr[n - 1], min(y, z)) + 1;
    return arr[n];
}
int minStep(int n)
{
    int *arr = new int[n + 1];
    for (int i = 0; i < n + 1; i++)
        arr[i] = -1;
    return minSteps(n, arr);
}
int main()
{
    cout << minStep(100);
    return 0;
}