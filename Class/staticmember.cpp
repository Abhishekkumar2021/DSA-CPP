#include<bits/stdc++.h>
using namespace std;
class student{
    public:
    int rollnumber;
    int age;
    static int totalstudents; //this belongs to a class not to an object.
    student(){
        totalstudents++;
    }
};
int student:: totalstudents=0;
int main(){
    student s1;
    cout<<s1.rollnumber<<endl;
    cout<<student::totalstudents;
    student s2;  
    cout <<endl<< student::totalstudents;
}