#include<bits/stdc++.h>
#include"linkedlist.cpp"
using namespace std;

node* mergesort(node*head){
	if(size(head)<=1)
		return head;
   node* midelement = mid(head);
   node* h2 = midelement->next;
   midelement->next = NULL;
   node* h1 = head;
   h1 = mergesort(h1);
   h2 = mergesort(h2);
   head = merge(h1,h2);
   return head;
}

int main(){
	#ifndef ONLINE_JUDGE 
    freopen("input.txt", "r",stdin);
    freopen("output.txt", "w",stdout);
    #endif
   node* head=initialise_better();
   print(head);
   head = mergesort(head);
   print(head);
  

}

