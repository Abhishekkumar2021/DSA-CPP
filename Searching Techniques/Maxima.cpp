#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int arr[] = {1, 2, 3, 4, 5, 6, 8, 9, 7, 6, 5, 4, 3, 2, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    int left = 0;
    int right = size - 1;
    while (left < right)
    {
        int mid = (left + right) / 2;
        if (arr[mid] < arr[mid + 1])
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    cout << "The maxima is = " << arr[left + 1] << "\n";
    return 0;
}