#include <bits/stdc++.h>
using namespace std;
void merge(int arr[], int l, int mid, int r)
{
    int leftSize = mid - l + 1;
    int rightSize = r - mid;
    int left[leftSize], right[rightSize];
    int temp = l;
    for (int k = 0; k < leftSize; k++)
    {
        left[k] = arr[temp++];
    }
    for (int m = 0; m < rightSize; m++)
    {
        right[m] = arr[temp++];
    }
    int i = 0, j = 0, index = l;
    while (i < leftSize && j < rightSize)
    {
        if (left[i] < right[j])
        {
            arr[index++] = left[i];
            i++;
        }
        else
        {
            arr[index++] = right[j];
            j++;
        }
    }
    while (i < leftSize)
        arr[index++] = left[i++];

    while (j < rightSize)
        arr[index++] = right[j++];
}

void mergeSort(int arr[], int l, int r)
{
    if (l >= r)
        return;
    int mid = (l + r) / 2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);
    merge(arr, l, mid, r);
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0, -10, -4};
    mergeSort(arr, 0, 11);
    for (int i = 0; i < 12; i++)
        cout << arr[i] << endl;
}