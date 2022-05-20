#include <bits/stdc++.h>
using namespace std;
char minimum(string s)
{
    char min = s[0];
    for (int i = 1; i < s.length(); i++)
        min = std::min(min, s[i]);
    return min;
}
int find_index(string s, char min)
{
    int i;
    for (i = 0; i < s.length(); i++)
        if (s[i] == min)
            return i;
}

int main()
{
    string s;
    cout << "enter the string ";
    cin >> s;
    int len = s.length();
    char min = minimum(s);
    cout << min << endl;
    int index = find_index(s, min);
    cout << index << endl;
    string str;
    if (index == 0)
        str = s.substr(1, s.length() - 1);
    else if (index == len - 1)
        str = s.substr(0, len - 2);
    else
        str = s.substr(0, index) + s.substr(index + 1, len - 1);
    cout << str;

    return 0;
}