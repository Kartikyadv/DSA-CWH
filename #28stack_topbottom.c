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

int peek(struct stack* sp, int i){
    int pos = sp->top - i + 1;
    if (pos < 0 )
    {
        printf("Not a valid position\n");
        return -1;
    }
    else
        return sp->arr[sp->top-i+1];   
}

int stackBottom(struct stack* sp){
    return sp->arr[0];
}
int stackTop(struct stack* sp){
    return sp->arr[sp->top];
}
int main() {
	struct stack *sp = (struct stack *) malloc(sizeof(struct stack));
	sp->size = 6;
	sp->top = -1;
	sp->arr = (int *) malloc(sp->size * sizeof(int));
	printf("Stack has been created successfully\n");
	
	
	push(sp, 5);
	push(sp, 6);
	push(sp, 56);
	push(sp, 526);
	push(sp, 24);
	push(sp, 2);
	for (int j = 1; j <= sp->top + 1 ; j++)
        {
         printf("The value at Position %d is %d\n", j, peek(sp, j));
         }
    printf("The topmost value of this stack is %d\n", stackTop(sp));
    printf("The bottom most value of this stack is %d\n", stackBottom(sp));
     
	return 0;
}