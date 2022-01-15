#include<bits/stdc++.h>
using namespace std;
class child{
    int age;
    int const rollnumber;
    int &x;
    public:
    child(int age,int rollnumber) : rollnumber(rollnumber),x(this->age){
        this -> age = age;
    }
    void display(){
        cout<<age<<" "<<rollnumber<<endl;
    }
};
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    child C(20,200101006);
    C.display();
}