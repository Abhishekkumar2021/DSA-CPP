#include <bits/stdc++.h>
using namespace std;
int minCount(int n)
{
    if (n == 1)
    {
        return 1;
    }
    int best = INT_MAX;
    int temp = 1;
    while (temp * temp < n)
    {
        int square = temp * temp;
        best = min(best, minCount(n - square));
        temp++;
    }
    return best + 1;
}
int main()
{
    cout << minCount(4);
    return 0;
}