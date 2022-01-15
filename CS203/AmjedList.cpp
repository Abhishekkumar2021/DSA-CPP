#include <iostream>

using namespace std;

class node
{

public:
    int name;
    node *next;
    node(int d)
    {
        name = d;
        next = NULL;
    }
};

void insertattail(node *&head, int p)
{
    node *n = new node(p);
    if (head == NULL)
    {
        head = n;
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

void insertathead(node *&head, int s)
{
    node *n = new node(s);
    node *temp = head;
    n->next = temp;
    head = n;
}

void printlist(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->name << endl;
        temp = temp->next;
    }
}

int main()
{
    node *head = NULL;
    insertattail(head, 1);
    insertattail(head, 5);
    insertattail(head, 4);
    insertattail(head, 6);
    printlist(head);
    return 0;
}