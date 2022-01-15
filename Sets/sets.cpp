#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    set<int> input;
    input.insert(5);
    input.insert(5);
    input.insert(10);
    cout << "{ ";
    for (auto x : input)
    {
        cout << x << " ";
    }
    cout << "}\n";
    set<int> output;
    output.insert(20);
    output.insert(30);
    cout << "{ ";
    for (auto x : output)
    {
        cout << x << " ";
    }
    cout << "}\n";
    output.erase(20);
    cout << "{ ";
    for (auto x : output)
    {
        cout << x << " ";
    }
    cout << "}\n";
    set<int> new_input = {1, 2, 3, 4, 5, 6, 6, 6, 6};
    cout << "{ ";
    for (auto x : new_input)
    {
        cout << x << " ";
    }
    cout << "}\n";
    unordered_set<int> new_output = {1, 2, 3, 4, 5, 6, 6, 5, 7, 5, 6, 7, 6};
    cout << "{ ";
    for (auto x : new_output)
    {
        cout << x << " ";
    }
    cout << "}\n";
    multiset<int> next = {1, 2, 3, 4, 5, 6, 6};
    cout << "{ ";
    for (auto x : next)
    {
        cout << x << " ";
    }
    cout << "}\n";
    unordered_multiset<int> last = {2, 3, 4, 5, 3, 131, 312, 312, 312, 312, 3, 13};
    cout << "{ ";
    for (auto x : last)
    {
        cout << x << " ";
    }
    cout << "}\n";
    return 0;
}