#include <bits/stdc++.h>
using namespace std;

void binary(int n)
{
    if (n == 0)
    {
        cout << 0 << endl;
        return;
    }

    vector<int> v;
    while (n > 0)
    {
        int x = n % 2;
        v.insert(v.begin(), x);
        n /= 2;
    }
    for (int i = 0; i < v.size(); i++)
        cout << v[i];
    cout << endl;
}
int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // int n;
    // cin>>n;
    for (int i = 0; i <= 100; i += 10)
    {
        cout << i << " : ";
        binary(i);
    }
}