#include <iostream>
using namespace std;
/*
    polymorphism - many forms
    twotypes of polymorphism is there
    1. compile time
    2. run time
    ----------------------------------------------------------------
    compile time polymorphism can be achieved using
    1. function overloading
    2. operator overloading
    -- return type is not a diffrentiating factor for function overloading
    3. method overriding
    run time polymorphism can be achieved using
    1. virtual functions
    -- virtual functions are those functions that are present in the base class and can be overridden in the derived class
*/
class A
{
public:
    int dataOfA;
    A()
    {
        cout << "A Created!\n";
    }
    ~A()
    {
        cout << "A destroyed!\n";
    }
    virtual void print()
    {
        cout << "I am A\n";
    }
};
class B : public A
{
public:
    int dataOfB;
    B()
    {
        cout << "B Created!\n";
    }
    ~B()
    {
        cout << "B destroyed!\n";
    }
    void print()
    {
        cout << "I am B\n";
    }
};
int main()
{
    A a;
    A *ptrA;
    B b;
    ptrA = &b; // this is allowed i.e the pointer to a base class can points to the derived class object but vice versa is not true;
    // using this pointer we can access only those properties that are related to base class object
    ptrA->print();
    B *ptrB = new B;
    ptrB->print();
}