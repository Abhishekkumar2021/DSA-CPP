#include <bits/stdc++.h>
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
class linkedList
{
    node *head;
    node *tail;

public:
    linkedList()
    {
        head = NULL;
        tail = NULL;
    }
    ~linkedList()
    {
        delete head->next;
    }
    void print()
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
    void addValues(int n)
    {
        for (int i = 0; i < n; i++)
        {
            int data;
            cin >> data;
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
        }
    }
    node *mid()
    {
        node *slow = head;
        node *fast = head->next;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    int midElement()
    {
        return mid()->data;
    }
    node *getSecondLast()
    {
        if (head == NULL)
            return NULL;

        if (head->next == NULL)
            return NULL;
        node *temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        return temp;
    }
    int size()
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
    bool isEmpty()
    {
        if (head == NULL)
            return true;
        else
            return false;
    }
    bool isPresent(int data)
    {
        node *temp = head;
        while (temp != NULL)
        {
            if (temp->data == data)
                return true;
        }
        return false;
    }
    void insertAtBeg(int data)
    {
        if (head == NULL)
        {
            head = new node(data);
            tail = head;
        }
        else
        {
            node *newNode = new node(data);
            newNode->next = head;
            head = newNode;
        }
    }
    void insertAtEnd(int data)
    {
        if (head == NULL)
        {
            insertAtBeg(data);
        }
        else
        {
            node *newNode = new node(data);
            tail->next = newNode;
            tail = tail->next;
        }
    }
    node *getAddress(int index)
    {
        if (index >= size())
        {
            return NULL;
        }
        else
        {
            int count = 0;
            node *temp = head;
            while (temp != NULL)
            {
                if (count == index)
                    return temp;
                temp = temp->next;
                count++;
            }
        }
    }
    void insert(int data, int index)
    {
        if (index >= size())
            return;
        else
        {
            node *temp = getAddress(index - 1);
            if (temp != NULL)
            {
                node *newNode = new node(data);
                newNode->next = temp->next;
                temp->next = newNode;
            }
        }
    }
    void removeFromBeg()
    {
        if (head == NULL)
            return;
        if (head->next == NULL)
        {
            tail = tail->next;
        }
        node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    void removeFromEnd()
    {
        if (head == NULL)
        {
            return;
        }
        if (head->next == NULL)
        {
            removeFromBeg();
        }
        node *temp = getSecondLast();
        tail = temp;
        delete temp->next;
        tail->next = NULL;
    }
    void remove(int index)
    {
        if (index >= size())
            return;
        if (index == 0)
            removeFromBeg();
        if (index == size() - 1)
            removeFromEnd();
        node *temp = getAddress(index - 1);
        node *toDelete = temp->next;
        temp->next = toDelete->next;
        toDelete->next = NULL;
        delete toDelete;
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
    node *midExplicit(node *head)
    {
        node *slow = head;
        node *fast = head->next;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    node *mergesort_helper(node *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        node *midelement = midExplicit(head);
        node *h2 = midelement->next;
        midelement->next = NULL;
        node *h1 = head;
        h1 = mergesort_helper(h1);
        h2 = mergesort_helper(h2);
        head = merge(h1, h2);
        return head;
    }
    void mergeSort()
    {
        head = mergesort_helper(head);
    }
    pair<node *, node *> reverseUsingPair(node *head)
    {
        if (head == NULL || head->next == NULL)
        {
            pair<node *, node *> ans;
            ans.first = head;
            ans.second = head;
            return ans;
        }
        pair<node *, node *> temp = reverseUsingPair(head->next);
        (temp.second)->next = head;
        head->next = NULL;
        pair<node *, node *> ans;
        ans.first = temp.first;
        ans.second = head;
        return ans;
    }
    node *reverseSimple(node *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        node *ans = reverseSimple(head->next);
        node *last = head->next;
        last->next = head;
        head->next = NULL;
        return ans;
    }
    node *reverse()
    {
        pair<node *, node *> ans = reverseUsingPair(head);
        head = ans.first;
        // OR use
        // head = reverseSimple(head);
    }
};