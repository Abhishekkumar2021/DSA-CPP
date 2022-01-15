#include<bits/stdc++.h>
using namespace std;


class linkedListADT{
      public:
        int data;
        linkedListADT *next;

        linkedListADT()
        {
            next = NULL;
            data = 0;
       }
};
bool isEmpty(linkedListADT *head)
{
    return head == NULL;
}
linkedListADT* addBegin(linkedListADT *head, int data)
{
    if (isEmpty(head))
    {
        linkedListADT *newNode = new linkedListADT;
        newNode->data = data;
        newNode->next = NULL;
        head = newNode;
        return head;
    }
    else
    {
        linkedListADT *newNode = new linkedListADT;
        newNode->data = data;
        newNode->next = head;
        head = newNode;
        return head;
    }
}

linkedListADT *secondLastAddress(linkedListADT *head)
{
    if (head == NULL && head->next == NULL)
        return NULL;
    else
    {
        linkedListADT *temp = head->next;
        while (temp->next->next != NULL)
            temp = temp->next;
        return temp;
    }
}

linkedListADT *lastAddress(linkedListADT *head)
{
    if (isEmpty(head))
        return NULL;
    else if (head->next == NULL)
        return head;
    else
    {
        linkedListADT *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        return temp;
    }
}

linkedListADT* addEnd(linkedListADT *head, int data)
{
    if (isEmpty(head))
    {
        return addBegin(head, data);
    }
    else
    {
        linkedListADT *last = lastAddress(head);
        linkedListADT *newNode = new linkedListADT;
        newNode->data = data;
        last->next = newNode;
        newNode->next = NULL;
        return head;
    }
}

linkedListADT *deleteBegin(linkedListADT *head)
{
    if (isEmpty(head))
    {
        return NULL;
    }
    else if (head->next == NULL)
    {
        linkedListADT *ans = head;
        head = NULL;
        return ans;
    }
    else
    {
        linkedListADT *ans = head;
        head = head->next;
        ans->next = NULL;
        return ans;
    }
}

linkedListADT *deleteEnd(linkedListADT *head)
{
    if (isEmpty(head) && head->next == NULL)
    {
        return deleteBegin(head);
    }
    else
    {
        linkedListADT *secondLast = secondLastAddress(head);
        linkedListADT *ans = secondLast->next;
        secondLast->next = NULL;
        return ans;
    }
}

void printList(linkedListADT *head){
    linkedListADT *temp = head;
    while (temp != NULL)
    {
        cout << temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  linkedListADT* head = NULL;
  head = addBegin(head,10);
  head = addBegin(head, 20);
  head = addBegin(head, 30);
  head = addBegin(head, 40);
  head = addBegin(head, 50);
  head = addBegin(head, 60);
  head = addBegin(head, 70);
  head = addBegin(head, 80);
  printList(head);
  head = addEnd(head,100);
  printList(head);
  linkedListADT* deleted = deleteBegin(head);
  cout<<deleted->data;
  return 0;
}