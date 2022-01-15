#include <bits/stdc++.h>
#include "linkedlist.cpp"
using namespace std;

node *reverse(node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    node *ans = reverse(head->next);
    node *last = head->next;
    last->next = head;
    head->next = NULL;
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    node *head = initialise_better();
    head = reverse(head);
    print(head);
}