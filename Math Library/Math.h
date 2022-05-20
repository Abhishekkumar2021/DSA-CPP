#include <bits/stdc++.h>
using namespace std;

int floor(float x)
{
    return (int)x;
}
int ceil(float x)
{
    return (int)x + 1;
}
int mod(int a, int b)
{
    return a % b;
}
int nearestInt(float x)
{
    return (int)(x + 0.5);
}
void printDivision(int a, int b, int digits)
{
    cout << a / b << ".";
    int rem = a % b;
    for (int i = 0; i < digits; i++)
    {
        rem *= 10;
        cout << rem / b;
        rem = rem % b;
    }
}
// Fibonacci series
int fib1(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return fib1(n - 1) + fib1(n - 2);
}
int fib2(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    int prev = 0;
    int curr = 1;
    int sum = 1;
    for (int i = 2; i <= n; i++)
    {
        sum = prev + curr;
        prev = curr;
        curr = sum;
    }
    return sum;
}

int fib3(int n)
{
    const float phi = (float)(sqrt(5) + 1) / 2;
    const float phi_inverse = (float)(1 - sqrt(5)) / 2;
    float res = ((pow(phi, n) - pow(phi_inverse, n)) / sqrt(5));
    return (int)res;
}

int fib4(int n)
{
    const float phi = (float)(sqrt(5) + 1) / 2;
    float res = (pow(phi, n) / sqrt(5) + 0.5);
    return (int)res;
}

int random(int a, int b)
{
    static int r = 0;
    if (r < 0)
        r = 0;
    srand(r);
    int smaller = (a < b) ? a : b;
    int larger = (a > b) ? a : b;
    r++;
    return smaller + rand() % (larger - smaller);
}
