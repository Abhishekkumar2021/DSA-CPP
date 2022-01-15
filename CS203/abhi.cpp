#include <iostream>
using namespace std;
string substring(string s, int x, int y)
{
    string res = "";
    for (int i = x; i <= y; i++)
    {
        res+= s[i];
    }
    return res;
}

int main()
{
    string s1;
    cin >> s1;
    cout << substring(s1, 1, 4);
    return 0;
}
