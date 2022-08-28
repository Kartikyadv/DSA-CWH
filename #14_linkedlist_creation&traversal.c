#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node * next;
	};

void linkedListTraversal(struct Node* ptr){
	while(ptr != NULL){
	printf("Element : %d\n", ptr->data);
	ptr = ptr->next;
    }
}

int main(){
	struct Node * head;
	struct Node * second;
	struct Node * third;
	struct Node * fourth;
	
	//Allocate memory for nodes in the linked list in heap
	head = (struct Node *) malloc(sizeof(struct Node));
	second = (struct Node *) malloc(sizeof(struct Node));
	third = (struct Node *) malloc(sizeof(struct Node));
	fourth = (struct Node *) malloc(sizeof(struct Node));
	
	//Link first and second nodes
	head ->data = 7; 
	head ->next = second; 
	
	//Link second and third nodes
	second ->data = 11; 
	second ->next = third; 
	
	//Link third and fourth nodes
	third ->data = 66; 
	third ->next = fourth; 
	
	// Terminate the list at the 4th node
	fourth ->data = 100; 
	fourth ->next = NULL; 
	linkedListTraversal(head);//(head)= where to start printing from
	return 0;
}
