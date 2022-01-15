#include <iostream>
using namespace std;
/*
5.Hybrid inheritance/virtual inheritance
   -- this is mixture of other inheritances
           vehicle
            /  \
           /    \
          /      \
        car     truck
          \      /
           \    /
            \  /
            bus
   -------------- this is also known as diamond problem.
*/
class vehicle
{
public:
    string color;
    int numTyres;
    vehicle()
    {
        cout << "Vehicle created!\n";
    }
    ~vehicle()
    {
        cout << "Vehicle destroyed!\n";
    }
    void print()
    {
        cout << "------------ Vehicle's object --------------------\n";
        cout << "color: " << color << endl;
        cout << "numTyres: " << numTyres << endl;
        cout << "--------------------------------------------------\n";
    }
};
class car : virtual public vehicle
{ // virtual is added to remove two copies from the bus class
public:
    string company;
    string model;
    car()
    {
        cout << "Car created!\n";
    }
    ~car()
    {
        cout << "Car destroyed!\n";
    }
    void print()
    {
        cout << "------------ Car's object --------------------\n";
        cout << "color: " << color << endl;
        cout << "numTyres: " << numTyres << endl;
        cout << "company: " << company << endl;
        cout << "model: " << model << endl;
        cout << "--------------------------------------------------\n";
    }
};
class truck : virtual public vehicle
{
public:
    string company;
    string model;
    int numGears;
    truck()
    {
        cout << "Truck created!\n";
    }
    ~truck()
    {
        cout << "Truck destroyed!\n";
    }
    void print()
    {
        cout << "------------ Truck's object --------------------\n";
        cout << "color: " << color << endl;
        cout << "numTyres: " << numTyres << endl;
        cout << "company: " << company << endl;
        cout << "model: " << model << endl;
        cout << "numGears: " << numGears << endl;
        cout << "--------------------------------------------------\n";
    }
};
class bus : public car, public truck
{
public:
    bus()
    {
        cout << "Bus created!\n";
    }
    ~bus()
    {
        cout << "Bus destroyed!\n";
    }
    void print()
    {
        cout << "------------ Bus's object --------------------\n";
        cout << "color: " << car::color << endl;
        cout << "numTyres: " << car::numTyres << endl;
        cout << "company: " << car::company << endl;
        cout << "model: " << car::model << endl;
        cout << "numGears: " << numGears << endl;
        cout << "--------------------------------------------------\n";
    }
};
int main()
{
    vehicle v;
    v.print();
    car c;
    c.print();
    truck t;
    t.print();
    bus b;
    b.print();
}