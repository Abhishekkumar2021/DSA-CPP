#include <bits/stdc++.h>
using namespace std;
class student
{
public:
    int age;
};
bool comparator(student a, student b)
{
    return a.age < b.age;
}
int main()
{
    student st[10];
    for (int i = 0; i < 10; i++)
    {
        st[i].age = 10 - i;
    }
    sort(st, st + 10, comparator);
    for (int i = 0; i < 10; i++)
    {
        cout << st[i].age << " ";
    }

    return 0;
}