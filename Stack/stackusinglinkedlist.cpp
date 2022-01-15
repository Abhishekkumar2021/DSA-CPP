#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void push(int data)
{
    node *newnode = new node(data);
    newnode->next = head;
    head = newnode;
    size++;
}

int pop()
{
    if (head == NULL)
    {
        return 0;
    }
    head = head->next;
}

class stack
{
private:
    node *head;
    int size;

public:
    stack()
    {
        head = NULL;
        size = 0;
    }
};

int main()
{
}