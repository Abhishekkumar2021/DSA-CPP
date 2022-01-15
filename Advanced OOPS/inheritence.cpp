#include <iostream>
using namespace std;
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
};
class B : public A
{
private:
    int privateDataOfB;

protected:
    int protectedDataOfB;

public:
    int publicDataOfB;
    B()
    {
        cout << "I am contructor of B" << endl;
    }
    B(int privateDataOfA, int privateDataOfB) : A(privateDataOfA)
    {
        this->privateDataOfB = privateDataOfB;
        cout << "I am parametrised constructor of B\n";
    }
    ~B()
    {
        cout << "I am destructor of B" << endl;
    }
    void print()
    {
        cout << "........................... Object of class B ...................." << endl;
        cout << "Private Items " << endl;
        cout << " privateDataOfB = " << privateDataOfB << endl;
        cout << "Protected Items " << endl;
        cout << " protectedDataOfA = " << protectedDataOfA << endl;
        cout << " protectedDataOfB = " << protectedDataOfB << endl;
        cout << "Public Items " << endl;
        cout << " publicDataOfA = " << publicDataOfA << endl;
        cout << " publicDataOfB = " << publicDataOfB << endl;
        cout << "..................................................................\n";
    }
};
class C : public B
{
private:
    int privateDataOfC;

protected:
    int protectedDataOfC;

public:
    int publicDataOfC;
    C()
    {
        cout << "I am contructor of C" << endl;
    }
    C(int privateDataOfA, int privateDataOfB, int privateDataOfC) : B(privateDataOfA, privateDataOfB)
    {
        this->privateDataOfC = privateDataOfC;
        cout << "I am parametrised constructor of C\n";
    }
    ~C()
    {
        cout << "I am destructor of C" << endl;
    }
    void print()
    {
        cout << "........................... Object of class C ...................." << endl;
        cout << "Private Items " << endl;
        cout << " privateDataOfC = " << privateDataOfC << endl;
        cout << "Protected Items " << endl;
        cout << " protectedDataOfA = " << protectedDataOfA << endl;
        cout << " protectedDataOfB = " << protectedDataOfB << endl;
        cout << " protectedDataOfC = " << protectedDataOfC << endl;
        cout << "Public Items " << endl;
        cout << " publicDataOfA = " << publicDataOfA << endl;
        cout << " publicDataOfB = " << publicDataOfB << endl;
        cout << " publicDataOfC = " << publicDataOfC << endl;
        cout << "..................................................................\n";
    }
};
int main()
{
    // Let us check the order of call of constructors
    C c;
    // I am contructor of A
    // I am contructor of B
    // I am contructor of C
    // I am destructor of C
    // I am destructor of B
    // I am destructor of A
    // So we can interpret that the order of creation of the objects is : parent --> child --> grandchilds and the order of destruction is childs --> parent --> grandparents
    B b;
    A a;
    // order of destructor call is just opposite of the order of creation of the objects
    //  Now let's have a look at the sizes of each class objects
    cout << "The size of the object of class A is " << sizeof(a) << " bytes" << endl;
    cout << "The size of the object of class B is " << sizeof(b) << " bytes" << endl;
    cout << "The size of the object of class C is " << sizeof(c) << " bytes" << endl;
    // creating the object of class C with parameters
    C newC(10, 20, 30);
    // the newC object has three member function with the same name as print but which is outermost is going to be called
    newC.print();
    a.print();
    b.print();
    c.print();
}