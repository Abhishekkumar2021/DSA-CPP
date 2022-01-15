#include <bits/stdc++.h>
using namespace std;

int extendedTopDownMemo(int price[], int revenue[], int n, vector<int> &solution)
{
    if (revenue[n] > 0)
        return revenue[n];
    if (n == 0)
        return 0;
    // int maximum = price[n];
    int maximum = INT_MIN;
    for (int i = 1; i <= n; i++)
    {
        // maximum = max(maximum, cutRod(price, i) + cutRod(price, n - i));
        if (maximum < price[i] + extendedTopDownMemo(price, revenue, n - i, solution))
        {
            maximum = price[i] + extendedTopDownMemo(price, revenue, n - i, solution);
            solution[n] = i;
        }
    }
    revenue[n] = maximum;
}
pair<vector<int>, int> extendedTopDown(int price[], int n)
{
    vector<int> solution(n + 1, 0);
    int revenue[n + 1] = {0};

    return {solution, extendedTopDownMemo(price, revenue, n, solution)};
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
        pair<vector<int>, int> ans = extendedTopDown(price, i);
        printSolution(ans.first, i);
    }
    return 0;
}