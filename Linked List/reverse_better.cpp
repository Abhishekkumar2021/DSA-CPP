#include<bits/stdc++.h>
#include"linkedlist.cpp"
using namespace std;

class pairs{
  public:
  	node* head;
  	node* tail;
  	pairs(){
  		head = NULL;
  		tail = NULL;
  	}
};

pairs reverse_better(node* head){
	if(head == NULL || head->next== NULL){
		pairs ans;
		ans.head = head;
		ans.tail = head;
		return ans;
	}
	pairs temp = reverse_better(head->next);
	(temp.tail)->next = head;
	head->next = NULL;
	pairs ans ;
	ans.head = temp.head;
	ans.tail = head;
	return ans; 
}

node* reverse(node* head){
	pairs ans = reverse_better(head);
	return ans.head;
}

int main(){
	#ifndef ONLINE_JUDGE 
    freopen("input.txt", "r",stdin);
    freopen("output.txt", "w",stdout);
    #endif
	node* head = initialise_better();
	head = reverse(head);
	print(head);
}