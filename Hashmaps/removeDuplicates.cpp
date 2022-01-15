#include <bits/stdc++.h>
using namespace std;

// Brute Force Algorithm
pair<int *, int> removeDuplicates(int *arr, int size)
{
    if (size == 0 || size == 1)
    {
        pair<int *, int> result;
        result.first = arr;
        result.second = size;
        return result;
    }
    int temp = arr[0];
    pair<int *, int> result = removeDuplicates(arr + 1, size - 1);
    for (int i = 0; i < result.second; i++)
    {
        if (result.first[i] == temp)
        {
            return result;
        }
    }
    pair<int *, int> finalAnswer;
    finalAnswer.first = new int[result.second + 1];
    finalAnswer.second = result.second + 1;
    finalAnswer.first[0] = temp;
    for (int i = 0; i < result.second; i++)
    {
        finalAnswer.first[i + 1] = result.first[i];
    }
    return finalAnswer;
}

// HashMaps approach
vector<int> removeDuplicates(vector<int> v)
{
    vector<int> result;
    unordered_map<int, bool> seen;
    for (int i = 0; i < v.size(); i++)
    {
        if (seen.count(v[i]) > 0)
        {
            continue;
        }
        seen[v[i]] = true;
        result.push_back(v[i]);
    }
    return result;
}
int main()
{
    int arr[] = {2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 4, 4, 4, 5, 6, 7, 8, 9, 0};
    // pair<int*, int> result = removeDuplicates(arr,21);
    // for(int i=0; i<result.second; i++) {
    //     cout<<result.first[i]<<"  ";
    // }
    cout << endl
         << "Using HashMaps" << endl;
    vector<int> v;
    for (int i = 0; i < 21; i++)
    {
        v.push_back(arr[i]);
    }
    v = removeDuplicates(v);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
}