#include<bits/stdc++.h>
using namespace std;
#include"linkedlist.cpp"

int element(node* head,int x){
    node* temp = head;
    int cnt=0;
    while(temp!=NULL && cnt<x){
    	cnt++;
    	temp=temp->next;
    }
    return temp->data;
}

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


int size(node*head){
    int count=0;
    node*temp = head;
    while(temp!=NULL){
        count++;
        temp = temp->next;
    }
    return count;
}

node* mid(node* head){
	node* slow = head;
	node* fast = head->next;
	while(fast!=NULL && fast->next!=NULL){
		slow=slow->next;
		fast=fast->next->next;
	}
	return slow;
}

int main(){
#ifndef ONLINE_JUDGE 
    freopen("input.txt", "r",stdin);
    freopen("output.txt", "w",stdout);
#endif
 node* head = initialise_better();
 // int mid = size(head)/2;
 // cout<<element(head,mid);
 cout<<mid(head)<<endl;
 return 0;
}