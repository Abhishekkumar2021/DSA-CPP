#include <bits/stdc++.h>
using namespace std;

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

void bubblesort(int arr[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void selectionSort(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		int temp = arr[i], minindex = i;
		for (int j = i; j < n; j++)
		{
			if (arr[j] < arr[minindex])
				minindex = j;
		}
		arr[i] = arr[minindex];
		arr[minindex] = temp;
	}
}

void printArray(int arr[], int n)
{

	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main()
{

	int arr[] = {12, 11, 13, 5, 6};
	int n = sizeof(arr) / sizeof(arr[0]);

	insertionSort(arr, n);
	printArray(arr, n);

	return 0;
}
