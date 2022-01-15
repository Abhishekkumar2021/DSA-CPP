#include<bits/stdc++.h>
#include"linkedlist.cpp"
using namespace std;

node* reverseiteratively(node* head){
	node* c = head;
	node* prev = NULL;
	node* n = head->next;
	while(c!=NULL ){
		n = c->next;
		c->next = prev;
        prev = c;
        c=n;
		n = n->next;
	}
	return prev;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r",stdin);
	freopen("output.txt", "w",stdout);
	#endif
	node* head = initialise_better();
	head = reverseiteratively(head);
	print(head);
}