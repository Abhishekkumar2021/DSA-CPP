#include<stdio.h>
struct node {
    int val;
    struct node *next;
};
typedef struct node ListNode;
typedef ListNode* ListPtr;

void printList(ListPtr head) 
{
    if (head==NULL)
        printf("Empty List");
    else{
        while(head->next!=NULL){
            printf("%d->",head->val);
            head=head->next;
        }
        printf("%d",head->val);
    }
    printf("\n");
}


ListPtr element(ListPtr head,int x){
     ListPtr temp = head;
    int cnt=0;
    while(temp!=NULL && cnt<x){
      cnt++;
      temp=temp->next;
    }
    return temp;
}

ListPtr reverse(ListPtr head){
if(head == NULL || head->next== NULL)
		return head;
	ListPtr ans = reverse(head->next);
     node *last = head->next;    
    last->next = head;
    head->next = NULL;
    return ans;
}

ListPtr reverse_linkedlist(ListPtr head,int m,int n){

     	ListPtr newhed = element(head,m-1);
        ListPtr newtail = element(head,n-1);
        ListPtr temp1 = newtail->next;
        ListPtr temp2 = element(head,m-2);
        newtail->next = NULL;
        temp1->next->next = temp2;
        temp1->next=reverse(newhead);
    
}

int main()
{
    
    struct Node* head = NULL;
    return 0;
 }