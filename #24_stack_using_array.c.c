#include <stdio.h>
#include <stdlib.h>

struct stack {
	int size;
	int top;
	int * arr;
};

int isEmpty(struct stack* ptr) 
{
	if(ptr->top == -1) {
		return 1;
	} else {
		return 0;
	}
}
int isFull(struct stack*ptr) {
	if(ptr->top == ptr->size - 1) {
		return 1;
	} else {
		return 0;
	}
}

int main() {
//	struct stack s;// s is  now stack
//	s.size = 80;
//	s.top = -1;
//	s.arr = (int *) malloc(s.size * sizeof(int));
	struct stack *s = (struct stack *) malloc(sizeof(struct stack));// s is now ptr
	s->size = 80;
	s->top = -1;
	s->arr = (int *)malloc(s->size * sizeof(int));
	
	//Pushing an element manually
	s->arr[0] = 4;
	s->top++;
	//check if stack is empty
	if(isEmpty(s)){
		printf("The stack is empty\n");
	}
	else{
		printf("The stack is not empty\nElement is %d\n", s->arr[0]);		
	}
	return 0;
}
