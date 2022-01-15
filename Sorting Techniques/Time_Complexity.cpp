#include <bits/stdc++.h>
using namespace std;

void BubbleSort(int arr[], int size)
{
  for (int i = 0; i < size - 1; i++)
  {
    for (int j = 0; j < size - i - 1; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        swap(arr[j], arr[j + 1]);
      }
    }
  }
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

void selectionsort(int arr[], int size)
{

  for (int i = 0; i < size; i++)
  {
    int minindex = i;
    for (int j = i; j < size; j++)
    {
      if (arr[j] < arr[minindex])
        minindex = j;
    }
    int temp = arr[minindex];
    arr[minindex] = arr[i];
    arr[i] = temp;
  }
}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("Output.txt", "w", stdout);
#endif
  for (long int N = 10; N <= 1000000; N *= 10)
  {
    int arr[N];
    for (int i = 0; i < N; i++)
    {
      arr[i] = rand() % N;
      //   arr[i] = i;         // uncomment this for second question.
      // arr[i] = N-1-i;      // uncomment this one for third question.
    }
    clock_t time;
    double Timetaken;
    time = clock();
    insertionSort(arr, N);
    time = clock() - time;
    Timetaken = ((double)time) / CLOCKS_PER_SEC;
    cout << "Time taken by insertion sort algorithm for N = " << N << " is " << Timetaken << " seconds." << endl;

    time = clock();
    BubbleSort(arr, N);
    time = clock() - time;
    Timetaken = ((double)time) / CLOCKS_PER_SEC;
    cout << "Time taken by Bubble sort algorithm for N = " << N << " is " << Timetaken << " seconds." << endl;
    time = clock();
    selectionsort(arr, N);
    time = clock() - time;
    Timetaken = ((double)time) / CLOCKS_PER_SEC;
    cout << "Time taken by selection sort algorithm for N = " << N << " is " << Timetaken << " seconds." << endl;
    cout << endl;
  }
  return 0;
}