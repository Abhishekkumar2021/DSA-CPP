#include <bits/stdc++.h>
using namespace std;
int firstindex(int arr[], int size, int x)
{
  if (size == 0)
  {
    return -1; // it means that if size is zero then the what is the purpose of searching the element .....simply return that there is no position.
  }
  int ans = firstindex(arr + 1, size - 1, x);
  if (arr[0] == x)
    return 0;
  else
    return ans + 1;
}
int lastindex(int arr[], int size, int x)
{
  if (size == 0)
  {
    return -1; // it means that if size is zero then the what is the purpose of searching the element .....simply return that there is no position.
  }
  int ans = lastindex(arr + 1, size - 1, x);
  if (ans == -1)
  {
    if (arr[0] == x)
      return 0;
    else
      return -1;
  }
  else
    return ans + 1;
}
int allindex(int arr[], int size, int x, int output[])
{
  if (size == 0)
    return 0;
  int ans = allindex(arr + 1, size - 1, x, output);
  for (int i = 0; i < ans; i++)
    output[i]++;
  if (arr[0] == x)
  {
    for (int i = 0; i < ans; i++)
    {
      output[ans - i] = output[ans - i - 1];
    }
    output[0] = 0;
    return ans + 1;
  }
  else
    return ans;
}
int allindex2(int arr[], int size, int x, int output[])
{
  if (size == 0)
    return 0;
  int ans = allindex2(arr, size - 1, x, output);
  if (arr[size - 1] == x)
  {
    output[ans] = size - 1;
    return ans + 1;
  }
  else
    return ans;
}
int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int size;
  cin >> size;
  int arr[size];
  for (int i = 0; i < size; i++)
  {
    cin >> arr[i];
  }
  int x;
  cin >> x;
  cout << "The first index of " << x << " in the array is : " << firstindex(arr, size, x);
  cout << "\nThe last index of " << x << " in the array is : " << lastindex(arr, size, x);
  int output[50];
  cout << "\nAll the indexes of " << x << " in the array is : ";
  for (int i = 0; i < allindex(arr, size, x, output); i++)
  {
    cout << output[i] << " ";
  }
  cout << "\nusing method 2 ...........";
  cout << "\nAll the indexes of " << x << " in the array is : ";
  for (int i = 0; i < allindex2(arr, size, x, output); i++)
  {
    cout << output[i] << " ";
  }
}
