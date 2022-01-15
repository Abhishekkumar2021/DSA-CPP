#include <bits/stdc++.h>
using namespace std;

tuple<int, int, int, vector<int>> LAS_loops(int arr[], int l, int r)
{
    int leftIndex = 0;
    int rightIndex = 0;
    int maxCount = 0;
    vector<int> finalAns;
    for (int i = l; i <= r; i++)
    {
        int count = 0;
        int currentMax = arr[i];
        int left = i;
        int right = i;
        vector<int> ans;
        for (int j = i; j <= r; j++)
        {

            if (currentMax <= arr[j])
            {
                currentMax = arr[j];
                right = j;
                count++;
                ans.push_back(arr[j]);
            }
        }
        if (count > maxCount)
        {
            maxCount = count;
            leftIndex = left;
            rightIndex = right;
            finalAns = ans;
        }
    }
    return {leftIndex, rightIndex, maxCount, finalAns};
}
int fun()
{
    return 1, 2, 3, 4, 5;
}
tuple<int, int, int> LAS_cross(int arr[], int l, int r)
{
    int mid = (l + r) / 2;
    int leftIndex = mid;
    int rightIndex = mid;
    int currentMax = arr[mid];
    int currentMin = arr[mid];
    int count = 0;

    for (int i = mid; i >= l; i--)
    {

        cout << "Current minimum = " << currentMin << endl;
        if (arr[i] <= currentMin)
        {
            leftIndex = i;
            currentMin = arr[i];
            count++;
        }
    }
    for (int i = mid + 1; i <= r; i++)
    {
        cout << "Current maximum = " << currentMax << endl;
        if (arr[i] >= currentMax)
        {
            rightIndex = i;
            currentMax = arr[i];
            count++;
        }
    }
    return {leftIndex, rightIndex, count};
}
// pair<int, int> LAS_cross(int arr[], int l, int r)
// {
//     int mid = (l + r) / 2;
//     int leftIndex = mid;
//     int rightIndex = mid;
//     for (int i = mid; i > l; i--)
//     {
//         if (arr[i] >= arr[i - 1])
//         {
//             leftIndex = i - 1;
//         }
//         else
//             break;
//     }
//     for (int i = mid + 1; i < r; i++)
//     {
//         if (arr[i] <= arr[i + 1])
//         {
//             rightIndex = i + 1;
//         }
//         else
//             break;
//     }
//     return {leftIndex, rightIndex};
// }
// pair<int, int> LAS(int arr[], int l, int r)
// {
//     if (l < r)
//     {
//         int mid = (l + r) / 2;
//         pair<int, int> ans_cross = LAS_cross(arr, l, r);
//         pair<int, int> ans_left = LAS(arr, l, mid);
//         pair<int, int> ans_right = LAS(arr, mid + 1, r);
//         int crossDiff = ans_cross.second - ans_cross.first;
//         int leftDiff = ans_left.second - ans_left.first;
//         int rightDiff = ans_right.second - ans_right.first;
//         if (leftDiff > rightDiff && leftDiff > crossDiff)
//             return ans_left;
//         else if (crossDiff > leftDiff && crossDiff > rightDiff)
//             return ans_cross;
//         else
//             return ans_right;
//     }
// }

pair<int, int> LAS_direct(int arr[], int l, int r)
{
    int leftIndex = 0;
    int rightIndex = 0;
    int maxCount = 0;
    for (int i = l; i < r; i++)
    {
        int count = 0;
        int left = i;
        int right = i;
        for (int j = i + 1; j <= r; j++)
        {

            if (arr[j - 1] <= arr[j])
            {
                right = j;
                count++;
            }
            else
                break;
        }
        if (count > maxCount)
        {
            maxCount = count;
            leftIndex = left;
            rightIndex = right;
        }
    }
    return {leftIndex, rightIndex};
}
int main()
{
    int arr[] = {10, 22, 9, 33, 21, 50, 41, 60, 80};
    // int arr[] = {12, 3, 4, 7, 9, 0, 1};
    int size = sizeof(arr) / sizeof(int);
    pair<int, int> ans = LAS_direct(arr, 0, size - 1);
    cout << "Left index = " << ans.first << " ,"
         << "Right index = " << ans.second;
    // tuple<int, int, int, vector<int>> ans = LAS_loops(arr, 0, size - 1);
    // cout << get<0>(ans) << endl;
    // cout << get<1>(ans) << endl;
    // cout << get<2>(ans) << endl;
    // vector<int> elements = get<3>(ans);
    // for (auto element : elements)
    // {
    //     cout << element << " ";
    // }

    cout << endl;
}