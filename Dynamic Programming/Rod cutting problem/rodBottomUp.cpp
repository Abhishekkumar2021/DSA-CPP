#include <bits/stdc++.h>
using namespace std;

int cutRod(int price[], int n)
{
    int revenue[n + 1] = {0};
    for (int i = 1; i <= n; i++)
    {
        int maximum = INT_MIN;
        for (int j = 1; j <= i; j++)
        {
            maximum = max(maximum, price[j] + revenue[i - j]);
        }
        revenue[i] = maximum;
    }
    return revenue[n];
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
        int maxRevenue = cutRod(price, i);
        cout << maxRevenue << "\n";
    }
    return 0;
}