#include <bits/stdc++.h>
using namespace std;

double f(double x, int n, double num)
{
    return pow(x, n) - num;
}
double f_prime(double x, int n)
{
    return n * pow(x, n - 1);
}
double root(double num, int n)
{
    double current = num;
    double next;
    int count = 0;
    while (true)
    {
        double value = f(current, n, num);
        double prime = f_prime(current, n);
        next = current - value / prime;
        if (fabs(current - next) < 0.0000001)
        {
            cout << "Step taken = " << count << endl;
            return current;
        }
        current = next;
        count++;
    }
}
int main()
{
    cout << root(12345654321, 2) << endl;
}