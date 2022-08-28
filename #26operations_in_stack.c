#include <stdio.h>
#include <stdlib.h>

struct stack {
	int size;
	int top;
	int * arr;
};

int isFull(struct stack* ptr) {
	if (ptr->top == ptr->size - 1)	{
		return 1;
	} else {
		return 0;
	}
}
int isEmpty(struct stack* ptr) {
	if (ptr->top == -1) {
		return 1;
	} else {
		return 0;
	}
}

void push(struct stack* ptr, int val){
	if(isFull(ptr)) {
		printf("Stack Overflow!  Cannot push %d to the stack\n", val); 
	}
	else{
	ptr->top++;
	ptr->arr[ptr->top] = val;
	}
}
int pop(struct stack* ptr){
	if(isEmpty(ptr)) {
		printf("Stack Underflow!  Cannot POP from the stack\n"); 
		return -1;
	}
	else{
		int val = ptr->arr[ptr->top];//storing top value to be freed
		ptr->top--;
		return val;//free val
	}
}
int main() {
	struct stack *sp = (struct stack *) malloc(sizeof(struct stack));
	sp->size = 5;
	sp->top = -1;
	sp->arr = (int *) malloc(sp->size * sizeof(int));
	printf("Stack has been created successfully\n");
	
	printf("Before PUSH, FULL: %d\n", isFull(sp));
	printf("Before PUSH, EMPTY: %d\n", isEmpty(sp));
	push(sp, 5);
	push(sp, 6);
	push(sp, 56);
	push(sp, 526);
	push(sp, 24);
	push(sp, 2);// stack overflow
	printf("\n");
	printf("After PUSH, FULL: %d\n", isFull(sp));
	printf("After PUSH, EMPTY: %d\n", isEmpty(sp));
	// last in first out
	printf("Popped %d from the stack\n",pop(sp));
	printf("Popped %d from the stack\n",pop(sp));
	printf("Popped %d from the stack\n",pop(sp));
	
	printf("After POP, FULL: %d\n", isFull(sp));
	printf("After POP, EMPTY: %d\n", isEmpty(sp));
	
	return 0;
}
