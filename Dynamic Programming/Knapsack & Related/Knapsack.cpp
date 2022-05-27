#include <bits/stdc++.h>
using namespace std;

// The given codes are for the bounded and for the unbounded one what is their is that any item can be filled more than ones also so in the
// including case we dont pass n-1 we pass n as their is still chance it can be included

int knapsackRecursive(int *p, int *w, int n, int sum)
{
    if (n == 0 || sum == 0)
    {
        return 0;
    }
    if (w[n - 1] <= sum)
    {
        return max(knapsackRecursive(p, w, n - 1, sum), p[n - 1] + knapsackRecursive(p, w, n - 1, sum - w[n - 1]));
    }
    else
    {
        return knapsackRecursive(p, w, n - 1, sum);
    }
}

int helper(int *p, int *w, int n, int sum, int **mem)
{
    if (mem[n][sum] != -1)
    {
        return mem[n][sum];
    }
    if (w[n - 1] <= sum)
    {
        mem[n][sum] = max(helper(p, w, n - 1, sum, mem), p[n - 1] + helper(p, w, n - 1, sum - w[n - 1], mem));
    }
    else
    {
        mem[n][sum] = helper(p, w, n - 1, sum, mem);
    }
    return mem[n][sum];
}
int knapsackMemoize(int *p, int *w, int n, int sum)
{
    int **mem = new int *[n + 1];
    for (int i = 0; i <= n; i++)
        mem[i] = new int[sum + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (i == 0 || j == 0)
                mem[i][j] = 0;
            else
                mem[i][j] = -1;
        }
    }
    return helper(p, w, n, sum, mem);
}

int knapsackIterative(int *p, int *w, int n, int sum)
{
    int **mem = new int*[n + 1];
    for (int i = 0; i <= n; i++)
        mem[i] = new int[sum + 1];

    // initialisation condition
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= sum; j++){
            if (i == 0 || j == 0)
                mem[i][j] = 0;
        }
    }

    // corresponding code
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= sum; j++){
            if (w[i - 1] <= j){
                mem[i][j] = max(mem[i - 1][j], p[i - 1] + mem[i - 1][j - w[i - 1]]);
            }
            else{
                mem[i][j] = mem[i - 1][j];
            }
        }
    }
    return mem[n][sum];
}

int main()
{
    int p[] = {60, 100, 120};
    int w[] = {10, 20, 30};
    int sum = 50;
    int n = 3;
    cout << knapsackIterative(p, w, n, sum);
}