#include <bits/stdc++.h>
using namespace std;

int fib(unsigned int n, int *arr)
{
    if (n <= 1)
    {
        arr[n] = n;
        return n;
    }
    if (arr[n - 1] == 0)
    {
        int ans = fib(n - 1, arr);
        arr[n - 1] = ans;
    }
    if (arr[n - 2] == 0)
    {
        int ans = fib(n - 2, arr);
        arr[n - 2] = ans;
    }
    arr[n] = arr[n - 1] + arr[n - 2];
    return arr[n];
}
int fibonacci(unsigned int n)
{
    int *arr = new int[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        arr[i] = 0;
    }
    return fib(n, arr);
}
int fibonacciBetter(unsigned int n)
{
    if (n <= 1)
        return n;
    int first = 0;
    int second = 1;
    int fib = 0;
    for (int i = 0; i <= n; i++)
    {
        fib = first + second;
        first = second;
        second = fib;
    }
    return fib;
}
int main()
{
    // cout<<"| ";
    // for(int i=0; i<50; i++){
    //     cout << fibonacci(i) << " | ";
    // }
    cout << fibonacciBetter(10);
    return 0;
}