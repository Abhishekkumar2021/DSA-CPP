#include <bits/stdc++.h>
using namespace std;
class student
{
    int age;
    int const rollnumber;
    int &x;

public:
    student() : rollnumber(0), x(age)
    {
        age = 0;
    }
    student(int rollnumber, int age) : rollnumber(rollnumber), x(this->age)
    {
        this->age = age;
    }
    void display()
    {
        cout << age << " " << rollnumber << " " << x << endl;
    }
};
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    student s;
    s.display();
}