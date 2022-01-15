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
	double left = -num;
	double right = num;
	double x;
	int count = 0;
	while (true)
	{
		x = (left + right) / 2.0;
		double value = f(x, n, num);
		double prime = f_prime(x, n);
		if (value * prime <= 0)
			left = x;
		else
			right = x;
		if (value < 0.000001 && value >= 0)
		{
			cout << "Step taken = " << count << endl;
			return x;
		}
		count++;
	}
}
int main()
{

	cout << root(12345654321, 2) << endl;
}