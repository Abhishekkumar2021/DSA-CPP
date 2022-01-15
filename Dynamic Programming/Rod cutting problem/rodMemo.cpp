#include <bits/stdc++.h>
using namespace std;
int cutRodMemo(int price[], int revenue[], int n)
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
        maximum = max(maximum, price[i] + cutRodMemo(price, revenue, n - i));
    }
    revenue[n] = maximum;
    return revenue[n];
}
int cutRod(int price[], int n)
{
    int revenue[n + 1] = {0};
    return cutRodMemo(price, revenue, n);
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    int price[] = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    for (int i = 1; i <= 2; i++)
    {
        int maxRevenue = cutRod(price, i);
        cout << maxRevenue << "\n";
    }
    return 0;
}