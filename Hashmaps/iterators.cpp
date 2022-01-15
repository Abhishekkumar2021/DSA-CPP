#include <bits/stdc++.h>
using namespace std;
int main()
{
    unordered_map<string, int> map;
    map["hello"] = 42;
    map["Bye"] = 43;
    map["Hey"] = 44;
    map["Hi"] = 45;
    map["Goodbye"] = 46;
    map["Good Night"] = 50;
    map["Good Morning"] = 47;
    // iterators are in some way like pointer as they also points to the containers
    unordered_map<string, int>::iterator iter = map.begin();
    // cout << "Key : " << iter->first << " | Value : " << iter->second << endl;
    // iter++;
    // cout << "Key : " << iter->first << " | Value : " << iter->second << endl;
    // iter++;
    // cout << "Key : " << iter->first << " | Value : " << iter->second << endl;
    // iter++;
    // cout << "Key : " << iter->first << " | Value : " << iter->second << endl;
    // iter++;
    // cout << "Key : " << iter->first << " | Value : " << iter->second << endl;
    // iter++;
    // cout << "Key : " << iter->first << " | Value : " << iter->second << endl;
    // iter++;
    // cout << "Key : " << iter->first << " | Value : " << iter->second << endl;
    // iter++;
    for (iter = map.begin(); iter != map.end(); iter++)
    {
        cout << "Key : " << iter->first << " | Value : " << iter->second << endl;
    }
    vector<int> v;
    for (int i = 0; i < 20; i++)
    {
        v.push_back(i + 1);
    }
    vector<int>::iterator v_iter = v.begin();
    while (v_iter != v.end())
    {
        cout << *v_iter << " ";
        v_iter++;
    }
    // find function
    vector<int>::iterator ans = find(v.begin(), v.end(), 20);
    if (ans != v.end())
    {
        cout << endl;
        cout << "Index = " << ans - v.begin() << endl;
    }
    v.erase(v.begin(), v.begin() + 5);
    v_iter = v.begin();
    while (v_iter != v.end())
    {
        cout << *v_iter << " ";
        v_iter++;
    }
    return 0;
}