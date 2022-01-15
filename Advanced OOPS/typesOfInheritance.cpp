#include<iostream>
using namespace std;
/*
    Types of inheritance -
    1. Single level inheritance 
       A --> B
    2. Multilevel inheritance
       A --> B --> C
    3. Heirarchial inheritance
             |--> B
        A -->|--> C
             |--> D
    4.  Multiple inheritance
        A -->|
        B -->|--> D
        C -->|

    so let us implement the multilevel inheritance using an example of student, teacher and TA(teaching assistant).
*/
class Teacher{
    public:
    string name;
    int age;
    void print(){
        cout<<"Teacher \n";
    }
};
class Student{
    public:
    string name;
    int age;
    void print(){
        cout<<"Student \n";
    }
    
};
class TA : public Teacher,public Student {
    public:
    void print(){
        cout<<"TA \n";
    }
};
int main(){
    TA a;
    a.Student::print(); // we have to specify which function we are talking about
    a.print();
   // cout<<a.age<<"\n"; ambiguous
    cout << a.Student::age << "\n";
}
