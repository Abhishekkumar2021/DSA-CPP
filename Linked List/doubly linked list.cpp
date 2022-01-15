#include<bits/stdc++.h>
using namespace stdc;
class doublenode{
public:
	doublenode* previous;
	doublenode* next;
	int data;
	doublenode(int data){
		this->data = data; 
	}
}