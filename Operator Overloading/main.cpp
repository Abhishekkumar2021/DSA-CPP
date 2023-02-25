#include<bits/stdc++.h>
using namespace std;

class Point{
    double x;
    double y;
    double z;
public:
    // Default constructor
    Point(){
        this->x = 0;
        this->y = 0;
        this->z = 0;
    }
    // Constructor for 1D point
    Point(double x){
        this->x = x;
        this->y = 0;
        this->z = 0;
    }
    // Constructor for 2D point
    Point(double x, double y){
        this->x = x;
        this->y = y;
        this->z = 0;
    }
    // Constructor for 3D point
    Point(double x, double y, double z){
        this->x = x;
        this->y = y;
        this->z = z;
    }
    // Overloading + operator
    Point operator+(Point p){
        Point temp;
        temp.x = this->x + p.x;
        temp.y = this->y + p.y;
        temp.z = this->z + p.z;
        return temp;
    }
    // Overloading - operator
    Point operator-(Point p){
        Point temp;
        temp.x = this->x - p.x;
        temp.y = this->y - p.y;
        temp.z = this->z - p.z;
        return temp;
    }
    // Overloading * operator
    Point operator*(Point p){
        Point temp;
        temp.x = this->x * p.x;
        temp.y = this->y * p.y;
        temp.z = this->z * p.z;
        return temp;
    }
    // Overloading / operator
    Point operator/(Point p){
        Point temp;
        temp.x = this->x / p.x;
        temp.y = this->y / p.y;
        temp.z = this->z / p.z;
        return temp;
    }
    // Overloading << operator
    friend ostream& operator<<(ostream& out, Point p){
        out << "(" << p.x << ", " << p.y << ", " << p.z << ")";
        return out;
    }
    // Overloading >> operator
    friend istream& operator>>(istream& in, Point &p){
        in >> p.x >> p.y >> p.z;
        return in;
    }
    // Overloading ++ operator
    Point operator++(){
        this->x++;
        this->y++;
        this->z++;
        return *this;
    }
    // Overloading -- operator
    Point operator--(){
        this->x--;
        this->y--;
        this->z--;
        return *this;
    }
    // Overloading == operator
    bool operator==(Point p){
        if(this->x == p.x && this->y == p.y && this->z == p.z){
            return true;
        }
        return false;
    }
    // Overloading != operator
    bool operator!=(Point p){
        if(this->x != p.x || this->y != p.y || this->z != p.z){
            return true;
        }
        return false;
    }
    // Overloading < operator
    bool operator<(Point p){
        if(this->x < p.x && this->y < p.y && this->z < p.z){
            return true;
        }
        return false;
    }
    // Overloading > operator
    bool operator>(Point p){
        if(this->x > p.x && this->y > p.y && this->z > p.z){
            return true;
        }
        return false;
    }
    // Overloading <= operator
    bool operator<=(Point p){
        if(this->x <= p.x && this->y <= p.y && this->z <= p.z){
            return true;
        }
        return false;
    }
    // Overloading >= operator
    bool operator>=(Point p){
        if(this->x >= p.x && this->y >= p.y && this->z >= p.z){
            return true;
        }
        return false;
    }
    // Overloading = operator
    Point operator=(Point p){
        this->x = p.x;
        this->y = p.y;
        this->z = p.z;
        return *this;
    }
    // Overloading += operator
    Point operator+=(Point p){
        this->x += p.x;
        this->y += p.y;
        this->z += p.z;
        return *this;
    }
    // Overloading -= operator
    Point operator-=(Point p){
        this->x -= p.x;
        this->y -= p.y;
        this->z -= p.z;
        return *this;
    }
    // Overloading *= operator
    Point operator*=(Point p){
        this->x *= p.x;
        this->y *= p.y;
        this->z *= p.z;
        return *this;
    }
    // Overloading /= operator
    Point operator/=(Point p){
        this->x /= p.x;
        this->y /= p.y;
        this->z /= p.z;
        return *this;
    }
    // Overloading [] operator
    double operator[](int index){
        if(index == 0){
            return this->x;
        }
        else if(index == 1){
            return this->y;
        }
        else if(index == 2){
            return this->z;
        }
        else{
            return -1;
        }
    }
    // Overloading () operator
    void operator()(double x, double y, double z){
        this->x = x;
        this->y = y;
        this->z = z;
    }
    // Overloading ! operator
    bool operator!(){
        if(this->x == 0 && this->y == 0 && this->z == 0){
            return true;
        }
        return false;
    }
    // Overloading - operator
    Point operator-(){
        this->x = -this->x;
        this->y = -this->y;
        this->z = -this->z;
        return *this;
    }
    // Overloading ~ operator => not possible as it works on int only
    // Overloading & operator => not possible as it works on int only
    // Overloading | operator => not possible as it works on int only
    // Overloading ^ operator => not possible as it works on int only
    // Overloading << operator => not possible as it works on int only
    // Overloading >> operator => not possible as it works on int only
    
    // Overloading && operator
    bool operator&&(Point p){
        if((this->x && p.x) && (this->y && p.y) && (this->z && p.z)){
            return true;
        }
        return false;
    }
    // Overloading || operator
    bool operator||(Point p){
        if((this->x || p.x) || (this->y || p.y) || (this->z || p.z)){
            return true;
        }
        return false;
    }
    // Overloading , operator
    Point operator,(Point p){
        return p;
    }
    // Overloading -> operator
    Point* operator->(){
        return this;
    }
};

int main(){
    Point p1(1, 2, 3);
    Point p2(4, 5, 6);
    Point p3;
    cout << "p1 = " << p1 << endl;
    cout << "p2 = " << p2 << endl;
    cout << "p3 = " << p3 << endl;
    cout << "p1 + p2 = " << p1 + p2 << endl;
    cout << "p1 - p2 = " << p1 - p2 << endl;
    cout << "p1 * p2 = " << p1 * p2 << endl;
    cout << "p1 / p2 = " << p1 / p2 << endl;
    cout << "p1 += p2 = " << (p1 += p2) << endl;
    cout << "p1 -= p2 = " << (p1 -= p2) << endl;
    cout << "p1 *= p2 = " << (p1 *= p2) << endl;
    cout << "p1 /= p2 = " << (p1 /= p2) << endl;
    cout << "p1 == p2 = " << (p1 == p2) << endl;
    cout << "p1 != p2 = " << (p1 != p2) << endl;
    cout << "p1 < p2 = " << (p1 < p2) << endl;
    cout << "p1 > p2 = " << (p1 > p2) << endl;
    cout << "p1 <= p2 = " << (p1 <= p2) << endl;
    cout << "p1 >= p2 = " << (p1 >= p2) << endl;
    cout << "p1 = p2 = " << (p1 = p2) << endl;
    cout << "p1[0] = " << p1[0] << endl;
    cout << "p1[1] = " << p1[1] << endl;
    cout << "p1[2] = " << p1[2] << endl;
    cout << "p1(4, 5, 6) = " << (p1(4, 5, 6), p1) << endl;
    cout << "!p1 = " << !p1 << endl;
    cout << "-p1 = " << -p1 << endl;
    cout << "p1 && p2 = " << (p1 && p2) << endl;
    cout << "p1 || p2 = " << (p1 || p2) << endl;
    cout << "p1, p2 = " << (p1, p2) << endl;
    cout << "this for p1 = " << p1 << endl;
    cout << "this for p2 = " << p2 << endl;
    cout << "this for p3 = " << p3 << endl;
    return 0;

}