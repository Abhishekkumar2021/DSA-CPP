#include <bits/stdc++.h>
using namespace std;
class complexnumber
{
    double real;
    double comp;

public:
    complexnumber(double r, double c)
    {
        real = r;
        comp = c;
    }
    void display()
    {
        cout << real << " +" << comp << "i";
        cout << "\n";
    }
    void add(complexnumber second)
    {
        real += second.real;
        comp += second.comp;
        this->display();
    }
    void subtract(complexnumber second)
    {
        real -= second.real;
        comp -= second.comp;
        this->display();
    }
    void multiply(complexnumber second)
    {
        real = real * second.real - comp * second.comp;
        comp = real * second.comp + comp * second.real;
        this->display();
    }
};
int main()
{
    int choice;
    cout << "........Operations........" << endl;
    cout << "1.Addition......." << endl;
    cout << "2.Subtraction....." << endl;
    cout << "3.Multiplication...." << endl;
    cout << "Enter your choice : ";
    cin >> choice;
    while (choice <= 3 && choice >= 1)
    {
        double x, y;
        char b;
        cout << "Enter first complex number : ";
        cin >> x >> y >> b;
        complexnumber c1(x, y);
        double m, n;
        char q;
        cout << "Enter second complex number : ";
        cin >> m >> n >> q;
        complexnumber c2(m, n);
        switch (choice)
        {
        case 1:
            c1.add(c2);
            break;
        case 2:
            c1.subtract(c2);
            break;
        case 3:
            c1.multiply(c2);
            break;
        }
        cout << "Do you want to continue....(Y/N) : ";
        char ch;
        cin >> ch;
        if (ch == 'N')
        {
            cout << "Thank you" << endl;
            break;
        }

        else
        {
            int x;
            cout << "Enter your choice : ";
            cin >> x;
            choice = x;
        }
    }
}
