#include <bits/stdc++.h>
using namespace std;
int main()
{

    int array[] = {1, 2, 3, 4, 4, 4, 4, 4, 4, 4, 5, 6, 7, 8, 9, 0};
    int firstIndex = lower_bound(array, array + sizeof(array) / sizeof(int), 4) - array; // based on binary search
    int lastIndex = upper_bound(array, array + sizeof(array) / sizeof(int), 4) - array;  // based on binary search
    if (firstIndex < 17)
    {
        // x found at index k
        cout << firstIndex << endl;
    }
    if (lastIndex < 17)
    {
        cout << lastIndex << endl;
    }
    cout << "Count of 4 = " << lastIndex - firstIndex << endl;
    auto result = equal_range(array, array + sizeof(array) / sizeof(int), 4);
    cout << result.second - result.first << endl;
    return 0;
}