#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b, min;
    cin >> a >> b;
    min = (a < b) ? a : b;
    int gcd;
    for (int i = 1; i <= min; i++)
    {
        if (a % i == 0 && b % i == 0)
            gcd = i;
    }
    cout << "GCD = " << gcd << endl;
    cout << "LCM = " << a * b / gcd << endl;
}