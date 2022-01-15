#include <bits/stdc++.h>
using namespace std;

int sum(int arr[], int n)
{
  if (n == 0)
    return 0;
  int ans = sum(arr + 1, n - 1);
  return ans + arr[0];
}

int max(int arr[], int n)
{
  if (n == 1)
    return arr[0];
  int ans = max(arr + 1, n - 1);
  return (arr[0] > ans) ? arr[0] : ans;
}

int min(int arr[], int n)
{
  if (n == 1)
    return arr[0];
  int ans = max(arr + 1, n - 1);
  return (arr[0] < ans) ? arr[0] : ans;
}

int product(int arr[], int n)
{
  if (n == 1)
    return arr[0];
  int ans = product(arr + 1, n - 1);
  return arr[0] * ans;
}

float average(int arr[], int n)
{
  if (n == 1)
    return arr[0];
  float ans = average(arr + 1, n - 1);
  return (arr[0] + (n - 1) * ans) / n;
}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n;
  cin >> n;
  int array[n];
  for (int i = 0; i < n; i++)
    cin >> array[i];
  cout << max(array, n);
  cout << "\n"
       << min(array, n);
  cout << "\n"
       << product(array, n);
  cout << "\n"
       << average(array, n);
  return 0;
}
