#include<stdio.h>

#define SIZE 100

struct stack{
	int data[SIZE];
	int next_index;
};

int pop(struct stack *S){
	if(S->next_index == 0){
		printf("Sorry! your stack is empty.\n");
		return 0;
	}
	S->next_index--;
	return S->data[S->next_index+1];
}

void push(struct stack *S,int x){
	if(S->next_index == SIZE){
		printf("Stack is full.\n");
		return;
	}
	S->data[S->next_index] = x;
	S->next_index++;
}

void print(struct stack *S){
	for(int i=0; i<S->next_index; i++)
		printf("%d ",S->data[i]);
	printf("\n");
}

int isempty(struct stack *S){
	if(S->next_index == 0)
		return 1;
	else
		return 0;
}

int isfull(struct stack *S){
	if(S->next_index == SIZE)
		return 1;
	else
		return 0;
}

int top(struct stack *S){
	return S->data[S->next_index-1];
}

int main(){
	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  	struct stack S;
	S.next_index = 0;
	push(&S,1);
    pop(&S);
    pop(&S); 

}