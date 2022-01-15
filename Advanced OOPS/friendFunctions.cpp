#include <bits/stdc++.h>
using namespace std;
class B
{
public:
    void printPrivateItemsOfA();
};
class A
{
private:
    int privateDataOfA;

protected:
    int protectedDataOfA;

public:
    int publicDataOfA;
    A()
    {
        cout << "I am contructor of A" << endl;
    }
    A(int privateDataOfA)
    {
        this->privateDataOfA = privateDataOfA;
        cout << "I am parametrised constructor of A\n";
    }
    ~A()
    {
        cout << "I am destructor of A" << endl;
    }
    void print()
    {
        cout << "........................... Object of class A ...................." << endl;
        cout << "Private Items " << endl;
        cout << " privateDataOfA = " << privateDataOfA << endl;
        cout << "Protected Items " << endl;
        cout << " protectedDataOfA = " << protectedDataOfA << endl;
        cout << "Public Items " << endl;
        cout << " publicDataOfA = " << publicDataOfA << endl;
        cout << "..................................................................\n";
    }
    friend void printPrivateItems();
    friend void B ::printPrivateItemsOfA();
    friend class B; // we have defined the class B as friend function .... this friendship is one way i.e class B can access all properties of the class A but vice-versa is not true
};
void printPrivateItems()
{
    A a;
    a.privateDataOfA = 10;
    a.protectedDataOfA = 20;
    a.publicDataOfA = 30;
    cout << "I am a friend function of class A and showing you the private items as : \nprivateDataOfA = " << a.privateDataOfA << endl;
}
void B::printPrivateItemsOfA()
{
    A a;
    a.privateDataOfA = 10;
    a.protectedDataOfA = 20;
    a.publicDataOfA = 30;
    cout << "I am a friend function of class A and showing you the private items as : \nprivateDataOfA = " << a.privateDataOfA << endl;
}
// friend functions are not affected by their access modifier

int main()
{
    //    printPrivateItems();
    B b;
    b.printPrivateItemsOfA();
    return 0;
}