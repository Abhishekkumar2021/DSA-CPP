#include <bits/stdc++.h>
using namespace std;
class child
{
    int age;
    int const rollnumber;
    int &x;

public:
    child(int rollnumber, int age) : rollnumber(rollnumber), x(this->age)
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
    child C(20, 200101006);
    C.display();
}