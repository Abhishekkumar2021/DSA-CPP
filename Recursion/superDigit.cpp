#include <bits/stdc++.h>
using namespace std;

int superDigit(string n, int k)
{
  string p = "";
  for (int i = 0; i < k; i++)
    p += n;
  if (p.size() == 1)
    return p[0] - '0';
  int sum = 0;
  for (int i = 0; i < p.size(); i++)
  {
    sum += p[i] - '0';
  }
  string s = "";
  while (sum > 0)
  {
    s += (sum % 10) + '0';
    sum /= 10;
  }
  reverse(s.begin(), s.end());
  int ans = superDigit(s, 1);
  return ans;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  cout << superDigit("9875", 4);
  return 0;
}