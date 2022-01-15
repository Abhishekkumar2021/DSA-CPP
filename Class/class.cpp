#include <bits/stdc++.h>
using namespace std;
class familymember
{
private:
	string name;
	int age;
	string bloodgroup;
	float weight;
	float height;

public:
	familymember()
	{
		cout << "Default constructor called...\n";
		name = " ";
		age = 0;
		bloodgroup = " ";
		weight = 0;
		height = 0;
	}
	~familymember()
	{
		cout << "Destructor called...\n";
	}
	void setname(string s)
	{
		name = s;
	}
	void setage(int age)
	{
		this->age = age;
	}
	void setbloodgroup(string b)
	{
		bloodgroup = b;
	}
	void setweight(float weight)
	{
		this->weight = weight;
	}
	void setheight(float height)
	{
		this->height = height;
	}
	familymember(string name, int age, string bloodgroup, float weight, float height)
	{
		cout << "Explicit constructor called...\n";
		this->name = name;
		this->age = age;
		this->bloodgroup = bloodgroup;
		this->weight = weight;
		this->height = height;
		cout << "This contains : " << this << "\n";
	}
	string getname()
	{
		return name;
	}
	int getage()
	{
		return age;
	}
	string getbloodgroup()
	{
		return bloodgroup;
	}
	float getweight()
	{
		return weight;
	}
	float getheight()
	{
		return height;
	}
	void display()
	{
		cout << "Name: " << name << endl;
		cout << "Age: " << age << endl;
		cout << "Bloodgroup: " << bloodgroup << endl;
		cout << "Weight: " << weight << endl;
		cout << "Height: " << height << endl;
	}
};
