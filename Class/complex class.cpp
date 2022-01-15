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
        if (comp < 0)
            cout << real << comp << "i";
        else
            cout << real << "+" << comp << "i";
        cout << "\n";
    }
    void operator+(complexnumber second)
    {
        real += second.real;
        comp += second.comp;
        this->display();
    }
    void operator-(complexnumber second)
    {
        real -= second.real;
        comp -= second.comp;
        this->display();
    }
    void operator*(complexnumber second)
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
        cout << "Enter first complex number : ";
        cin >> x >> y;
        cout << x << " " << y;
        complexnumber c1(x, y);
        double m, n;
        cout << "Enter second complex number : ";
        cin >> m >> n;
        cout << m << " " << n;
        complexnumber c2(m, n);
        switch (choice)
        {
        case 1:
            c1 + (c2);
            break;
        case 2:
            c1 - (c2);
            break;
        case 3:
            c1 *(c2);
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
