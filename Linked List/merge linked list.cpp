#include <bits/stdc++.h>
using namespace std;
#include "linkedlist.cpp"

void print(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data;
        cout << " ";
        temp = temp->next;
    }
    cout << "\n";
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

node *merge(node *h1, node *h2)
{
    node *fh = NULL;
    node *ft = NULL;
    if (h1->data < h2->data)
    {
        fh = h1;
        ft = h1;
        h1 = h1->next;
    }
    else
    {
        fh = h2;
        ft = h2;
        h2 = h2->next;
    }
    while (h1 != NULL && h2 != NULL)
    {
        if (h1->data < h2->data)
        {
            ft->next = h1;
            ft = ft->next;
            h1 = h1->next;
        }
        else
        {
            ft->next = h2;
            ft = ft->next;
            h2 = h2->next;
        }
    }
    if (h1 == NULL)
        ft->next = h2;
    else
        ft->next = h1;

    return fh;
}
