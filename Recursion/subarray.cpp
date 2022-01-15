#include <bits/stdc++.h>
using namespace std;
int subarray(string input, string output[])
{
	if (input.size() == 0)
	{
		output[0] = "";
		return 1;
	}
	string smallstring = input.substr(1);
	int ans = subarray(smallstring, output);
	for (int i = 0; i < ans; i++)
	{
		output[ans + i] = input[0] + output[i];
	}
	return 2 * ans;
}
void printsubarray(string input, string output)
{
	if (input.size() == 0)
	{
		cout << "{" << output << "} ";
		return;
	}
	printsubarray(input.substr(1), output);
	printsubarray(input.substr(1), output + input[0]);
}
int main()
{
	string s, output[1000], newoutput;
	getline(cin, s);
	for (int i = 0; i < subarray(s, output); i++)
	{
		cout << "{" << output[i] << "} ";
	}
	cout << "\nUsing a new method.....\n";
	printsubarray(s, newoutput);
	return 0;
}