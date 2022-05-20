#include <bits/stdc++.h>
using namespace std;

bool isDigit(char c)
{
    return (c <= 57 && c >= 48);
}
bool isCharacter(char c)
{
    return (c == '+' || c == '/' || c == '^' || c == '-' || c == '*');
}
void integrate(string s)
{
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'x')
        {
            if (i + 1 < n)
            {
                if (isCharacter(s[i + 1]))
                {
                }
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}