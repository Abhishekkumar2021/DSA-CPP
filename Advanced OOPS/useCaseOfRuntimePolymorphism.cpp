#include <iostream>
using namespace std;
// salary calculation function
class employee
{
public:
    //    virtual void print(){
    //        cout<<" I am an employee\n";
    //    }
    virtual void print() = 0; // this is a pure virtual function
};
class HR : public employee
{
public:
    void print()
    {
        cout << " I am HR \n";
    }
};
class manager : public employee
{
public:
    void print()
    {
        cout << " I am manager\n";
    }
};
class others : public employee
{
public:
    void print()
    {
        cout << " I am others\n";
    }
};
class engineer : public employee
{
public:
    void print()
    {
        cout << " I am an engineer\n";
    }
};
int main()
{
    employee **eptr = new employee *[10];
    eptr[0] = new HR;
    eptr[1] = new engineer;
    eptr[2] = new manager;
    eptr[3] = new HR;
    // eptr[4] = new employee; we cannot create an object of employee class as now it is an abstract class i.e it is incomplete class because it contains pure virtual functions
    eptr[4] = new others;
    eptr[5] = new HR;
    eptr[6] = new HR;
    eptr[7] = new manager;
    eptr[8] = new others;
    eptr[9] = new others;

    for (int i = 0; i < 10; i++)
    {
        eptr[i]->print();
    }
}
