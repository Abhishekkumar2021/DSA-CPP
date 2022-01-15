#include <bits/stdc++.h>
using namespace std;
void countingSort_digitwise(int arr[], int n, int digitPlaceValue)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if ((arr[i] / digitPlaceValue) % 10 > max)
        {
            max = (arr[i] / digitPlaceValue) % 10;
        }
    } // O(n)
    int frequency[max + 1] = {0};
    for (int i = 0; i < n; i++)
    {
        frequency[(arr[i] / digitPlaceValue) % 10]++;
    } // O(n)
    for (int i = 0; i < max; i++)
    {
        frequency[i + 1] += frequency[i];
    } // O(max)
    int output[n];
    for (int i = n - 1; i >= 0; i--)
    {
        int index = frequency[(arr[i] / digitPlaceValue) % 10] - 1;
        output[index] = arr[i];
        frequency[(arr[i] / digitPlaceValue) % 10]--;
    } // O(n)
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
    // O(n)
}

void radixSort(int arr[], int n)
{
    int maxDigit = 4;
    for (int i = 0; i < maxDigit; i++)
    {
        countingSort_digitwise(arr, n, pow(10, i));
    }
}
int main()
{
    int arr[] = {2, 5, 1, 9, 3, 4, 2, 10};
    radixSort(arr, sizeof(arr) / sizeof(int));
    for (auto element : arr)
        cout << element << " ";
}