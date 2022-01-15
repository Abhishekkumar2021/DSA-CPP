#include <bits/stdc++.h>
using namespace std;
void countingSort(int arr[], int n)
{
	int max = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	} // O(n)
	int frequency[max + 1] = {0};
	for (int i = 0; i < n; i++)
	{
		frequency[arr[i]]++;
	} // O(n)
	for (int i = 0; i < max; i++)
	{
		frequency[i + 1] += frequency[i];
	} // O(max)
	int output[n];
	for (int i = n - 1; i >= 0; i--)
	{
		int index = frequency[arr[i]] - 1;
		output[index] = arr[i];
		frequency[arr[i]]--;
	} // O(n)
	for (int i = 0; i < n; i++)
		arr[i] = output[i];
	// O(n)
}
int main()
{
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 2};
	countingSort(arr, 15);
	for (int i = 0; i < 15; i++)
		cout << arr[i] << " ";
}