#include <bits/stdc++.h>
using namespace std;

pair<vector<int>, int> extendedBottomUp(int price[], int n)
{
    vector<int> solution(n + 1, 0);
    int revenue[n + 1] = {0};
    for (int i = 1; i <= n; i++)
    {
        int maximum = INT_MIN;
        for (int j = 1; j <= i; j++)
        {
            if (maximum < price[j] + revenue[i - j])
            {
                maximum = price[j] + revenue[i - j];
                solution[i] = j;
            }
        }
        revenue[i] = maximum;
    }
    return {solution, revenue[n]};
}
void printSolution(vector<int> solution, int n)
{
    while (n > 0)
    {
        cout << solution[n] << " ";
        n -= solution[n];
        if (n > 0)
        {
            cout << "+ ";
        }
    }
    cout << endl;
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    int price[] = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    for (int i = 1; i <= 10; i++)
    {
        pair<vector<int>, int> ans = extendedBottomUp(price, i);
        printSolution(ans.first, i);
    }
    return 0;
}