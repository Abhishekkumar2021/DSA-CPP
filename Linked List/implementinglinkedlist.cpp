#include <bits/stdc++.h>
using namespace std;

#include "linkedlist.cpp"

int size(node *head)
{
    int count = 0;
    node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void print(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data;
        cout << " ";
        temp = temp->next;
    }
    if (size(head) == 0)
    {
        cout << "List is empty";
    }
    cout << "\n";
}

node *initialise()
{
    int data;
    cin >> data;
    node *head = NULL;
    node *tail = NULL;
    while (data != -1)
    {
        node *n = new node(data);
        if (head == NULL)
            head = n;
        else
        {
            node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = n;
        }
        cin >> data;
    }
    return head;
}

node *initialise_better()
{
    int data;
    cin >> data;
    node *head = NULL;
    node *tail = NULL;
    while (data != -1)
    {
        node *n = new node(data);
        if (head == NULL)
        {
            tail = n;
            head = n;
        }
        else
        {
            tail->next = n;
            tail = tail->next;
        }
        cin >> data;
    }
    return head;
}
node *insertnode(node *head, int data, int i)
{
    node *n = new node(data);
    node *temp = head;
    int cnt = 0;
    if (i == 0)
    {
        n->next = head;
        head = n;
    }
    else
    {
        while (temp != NULL && cnt < i - 1)
        {
            temp = temp->next;
            cnt++;
        }
        if (temp != NULL)
        {
            n->next = temp->next;
            temp->next = n;
        }
    }
    return head;
}

node *deletenode(node *head, int i)
{
    node *temp = head;
    int cnt = 0;
    if (size(head) == 0)
    {
        cout << "Your list is already empty!" << endl;
    }
    else
    {
        if (i == 0)
        {
            head = head->next;
            delete temp;
        }
        else
        {
            while (temp != NULL && cnt < i - 1)
            {
                temp = temp->next;
                cnt++;
            }
            if (temp != NULL)
            {
                node *a = temp->next;
                node *b = a->next;
                temp->next = b;
                delete a;
                cnt++;
            }
        }
    }
    return head;
}
node *insert(node *head, int data, int i)
{
    if (head == NULL)
        return head;
    if (i == 0)
    {
        node *n = new node(data);
        n->next = head;
        head = n;
        return head;
    }
    node *temp = insert(head->next, data, i - 1);
    head->next = temp;
    return head;
}

node *Delete(node *head, int i)
{
    if (head == NULL)
        return head;
    if (i == 0)
    {
        node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    node *temp = Delete(head->next, i - 1);
    head->next = temp;
    return head;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    node *head = initialise_better();
    print(head);
    cout << size(head) << endl;
    head = insert(head, 20, 4);
    print(head);
    cout << size(head) << endl;
    head = Delete(head, 4);
    print(head);
    cout << size(head) << endl;
    return 0;
}