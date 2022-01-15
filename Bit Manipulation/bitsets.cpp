#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  bitset<10> a(string("1010101010"));
  cout << a[0]; // right to left
  bitset<10> b(string("0101010101"));
  cout << a.count() << endl; // returns the number of 1's
  cout << (a | b) << endl;
  return 0;
}