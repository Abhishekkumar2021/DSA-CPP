#include <bits/stdc++.h>
using namespace std;
int arraylength(char arr[])
{
  if (arr[0] == '\0')
    return 0;
  int ans = arraylength(arr + 1);
  return ans + 1;
}

void removeChar(char str[], char x)
{
  if (str[0] == '\0')
    return;
  removeChar(str + 1, x);
  if (str[0] == x)
  {
    int i = 1;
    for (; str[i] != '\0'; i++)
    {
      str[i - 1] = str[i];
    }
    str[i - 1] = '\0';
  }
}
void replaceConsecutiveWithOne(char str[])
{
  if (strlen(str) <= 1)
    return;
  replaceConsecutiveWithOne(str + 1);
  if (str[0] != str[1])
    return;
  else
  {
    int i = 1;
    for (; str[i] != '\0'; i++)
    {
      str[i - 1] = str[i];
    }
    str[i - 1] = '\0';
  }
}

string keypadCharacters(int n)
{
  int diff = n - 2;
  string result = "";
  if (n <= 7)
  {
    result += (char)(3 * diff + 65);
    result += (char)(3 * diff + 66);
    result += (char)(3 * diff + 67);
    if (n == 7)
      result += (char)(3 * diff + 68);
  }
  else
  {
    result += (char)(3 * diff + 66);
    result += (char)(3 * diff + 67);
    result += (char)(3 * diff + 68);
    if (n == 9)
      result += (char)(3 * diff + 69);
  }

  return result;
}
void getKeypadCombination(int n, string output)
{
  if (n <= 1)
  {
    reverse(output.begin(), output.end());
    cout << "{" << output << "} ";
    return;
  }

  string possible = keypadCharacters(n % 10);
  for (int i = 0; i < possible.length(); i++)
  {
    getKeypadCombination(n / 10, output + possible[i]);
  }
}
int main()
{
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
  // char str[100];
  // cin >> str;
  // cout << arraylength(str);
  // removeChar(str, 'a');
  // replaceConsecutiveWithOne(str);
  // for (int i = 2; i < 10; i++)
  // {
  //   cout << keypadCharacters(i) << endl;
  // }
  string output;
  getKeypadCombination(23, output);
  // cout << str;
}
