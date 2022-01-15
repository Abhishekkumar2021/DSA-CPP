#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> pairSum(vector<int> arr, int s)
{
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[i] + arr[j] == s)
            {
                ans.push_back({arr[i], arr[j]});
            }
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}
int main()
{
    int n, s;
    cin >> n >> s;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<vector<int>> ans = pairSum(arr, s);
    for (auto element : ans)
    {
        for (auto i : element)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
}
