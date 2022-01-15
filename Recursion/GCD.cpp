#include <bits/stdc++.h>
using namespace std;
int GCD(int a, int b)
{
    int largest = (a > b) ? a : b;
    int smallest = (a < b) ? a : b;
    if (largest % smallest == 0)
        return smallest;
    else
        return GCD(smallest, largest % smallest);
}
int main()
{
    cout << GCD(12, 30);
    return 0;
}