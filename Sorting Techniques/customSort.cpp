#include <bits/stdc++.h>
using namespace std;

void selectionSort(auto left, auto right, auto compare)
{
    for (auto i = left; i < right; i++)
    {
        auto min = i;
        for (auto j = i + 1; j < right; j++)
        {
            if (compare(*j, *min))
                min = j;
        }
        swap(*i, *min);
    }
}
bool compare(int a, int b) { return a <= b; }
int main()
{
    int arr[] = {2, 7, 1, 0, 4, 2};
    customSort(arr, arr + sizeof(arr) / sizeof(arr[0]), compare);
    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }
}

void merge(auto left, auto right, auto isOrder)
{
    auto mid = left + (right - left) / 2;
    auto leftSize = mid - left + 1;
    int rightSize = right - mid;
    decltype(*left) A[leftSize];
    decltype(*left) B[rightSize];
    int current = 0;
    for (int i = 0; i < leftSize; i++)
    {
        A[i] = *(left + current);
        current++;
    }
    for (int i = 0; i < rightSize; i++)
    {
        B[i] = *(left + current);
        current++;
    }
    int i = 0, j = 0;
    current = 0;
    while (i < leftSize && j < rightSize)
    {
        if (isOrder(A[i], B[j]))
        {
            *(left + current) = A[i++];
        }
        else
        {
            *(left + current) = B[j++];
        }
        current++;
    }
    while (i < leftSize)
    {
        *(left + current) = A[i++];
        current++;
    }
    while (j < rightSize)
    {
        *(left + current) = B[j++];
        current++;
    }
}

void customSort(auto left, auto right, auto isOrder)
{
    if (left < right)
    {
        auto mid = left + (right - left) / 2;
        customSort(left, mid, isOrder);
        customSort(mid + 1, right, isOrder);
        merge(left, right, isOrder);
    }
}