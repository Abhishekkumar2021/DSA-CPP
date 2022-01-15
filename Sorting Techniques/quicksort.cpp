#include <iostream>

using namespace std;
// if we chose last element as pivot
int pivotLast(int arr[], int l, int r)
{
  int x = arr[r];
  int index = l - 1; // here this represents the index of the last element upto which the elements are less than or equal to the x.
  for (int i = l; i <= r; i++)
  {
    if (arr[i] <= x)
    {
      index++;
      swap(arr[i], arr[index]);
    }
  }
  return index;
}
void swap(int &a, int &b)
{
  int temp = a;
  a = b;
  b = temp;
}
int pivotFirst(int arr[], int l, int r)
{
  int x = arr[l];
  int index = r + 1;
  for (int i = r; i >= l; i--)
  {
    if (arr[i] >= x)
    {
      index--;
      swap(arr[i], arr[index]);
    }
  }
  return index;
}
int pivotRandom(int arr[], int l, int r)
{
  int randomIndex = l + rand() % (r - l + 1);
  int x = arr[randomIndex];
  int left = l;
  int right = r;
  int count = 0;
  for (int i = left; i <= right; i++)
  {
    if (arr[i] < x)
    {
      count++;
    }
  }
  swap(arr[randomIndex], arr[l + count]);
  while (left < l + count && right > l + count)
  {
    if (arr[left] < x)
    {
      left++;
    }
    else if (arr[right] >= x)
    {
      right--;
    }
    else
    {
      swap(arr[left], arr[right]);
      left++;
      right--;
    }
  }
  return l + count;
}
int HoarePartition(int arr[], int l, int r)
{
  int x = arr[l];
  int left = l - 1;
  int right = r + 1;
  while (true)
  {
    while (arr[right] > x)
    {
      right--;
    }
    while (arr[left] <= x)
    {
      left++;
    }
    if (left < right)
      swap(arr[left], arr[right]);
    else
      return right;
  }
}
void quicksort(int arr[], int l, int r)
{

  if (l < r)
  {
    int index = pivotRandom(arr, l, r);
    quicksort(arr, l, index - 1);
    quicksort(arr, index + 1, r);
  }
}
int main()
{

  int array[] = {13, 19, 9, 5, 12, 8, 7, 4, 21, 2, 6, 11};
  int size = 12;
  // // cin >> size;
  // for (int i = 0; i < size; i++)
  // {
  //   array[i] = size - i;
  // }
  for (int i = 0; i < size; i++)
  {
    cout << array[i] << " ";
  }
  cout << endl;
  // cout << pivotRandom(array, 0, size - 1) << endl;
  quicksort(array, 0, size - 1);

  for (int i = 0; i < size; i++)
  {
    cout << array[i] << " ";
  }

  return 0;
}
