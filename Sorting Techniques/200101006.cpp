#include <iostream>
using namespace std;
int digSum(int x)
{
    int sum = 0;
    while (x > 0)
    {
        int digit = x % 10;
        sum += digit;
        x /= 10;
    }
    return sum;
}
void insertionSort(int arr[], int n)
{
    int temp, j;
    for (int i = 1; i < n; i++)
    {
        temp = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    insertionSort(arr, n);
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (max < digSum(arr[i]))
            max = digSum(arr[i]);
    }
    int frequencyArray[max + 1];
    for (int i = 0; i < max + 1; i++)
    {
        frequencyArray[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        int sum = digSum(arr[i]);
        frequencyArray[sum]++;
    }
    for (int i = 1; i < max + 1; i++)
    {
        frequencyArray[i] += frequencyArray[i - 1];
    }
    int outputArr[n];
    for (int i = n - 1; i >= 0; i--)
    {
        int sum = digSum(arr[i]);
        int index = frequencyArray[sum];
        outputArr[index - 1] = arr[i];
        frequencyArray[sum]--;
    }
    for (int i = 0; i < n; i++)
    {
        if (i == n - 1)
        {
            cout << outputArr[i] << "\n";
            break;
        }
        cout << outputArr[i] << " ";
    }
}