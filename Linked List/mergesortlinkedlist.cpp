#include<bits/stdc++.h>
using namespace std;
#include"linkedlist.cpp"

node* initialise_better(){
      int data;
      cin>>data;
      node* head = NULL;
     node*tail = NULL;
      while(data!=-1){
        node* n = new node(data);
        if(head==NULL){
         tail=n;
          head = n;
        }
        else{
            tail->next=n;
            tail = tail->next;
          }
          cin>>data;
      }
      return head;
    }

node* mergelinkedlist(node* h1, node* h2){
	node* fh = NULL;
	node* ft = NULL;
	if(h1->data<h2->data){
	   fh = h1;
	   ft = h1;
	   h1=h1->next;
	}
	else{
        fh = h2;
	    ft = h2;
	    h2=h2->next;
	}
	while(h1!=NULL && h2!=NULL){
		if(h1->data<h2->data){
			ft->next=h1;
            ft=ft->next;
			h1=h1->next;
		}
		else{
			ft->next=h2;
             ft=ft->next;
			h2 = h2->next;
		}
	}

	if(h1==NULL)
		ft->next=h2;
	else
	     ft->next=h1;

     return fh;
}

void print(node* head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp -> data;
        cout<<" ";
        temp = temp->next; 
        }
        cout<<"\n";
}

node* element(node* head,int x){
    node* temp = head;
    int cnt=0;
    while(temp!=NULL && cnt<x){
    	cnt++;
    	temp=temp->next;
    }
    return temp;
}

int size(node*head){
    int count=0;
    node*temp = head;
    while(temp!=NULL){
        count++;
        temp = temp->next;
    }
    return count;
}

node* mergesort(node* h){
    if(size(h)<=1)
    	return h;
    int mid = size(h)/2;
    node* h2 = element(h,mid+1);
    element(h,mid)->next=NULL;
    node* h1 = h;
    h1 = mergesort(h1);
    h2 = mergesort(h2);
    return mergelinkedlist(h1,h2);
}

int main(){
#ifndef ONLINE_JUDGE 
    freopen("input.txt", "r",stdin);
    freopen("output.txt", "w",stdout);
#endif
 node* h1 = initialise_better();
 // node* h2 = initialise_better();
 // node *head = merge(h2,h1);
h1 = mergesort(h1);
 print(h1); 
 return 0;
}