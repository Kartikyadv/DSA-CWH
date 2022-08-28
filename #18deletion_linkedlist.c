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
// case 1: Deleting 1st element(head)from the  linked list
struct Node * deleteFirst(struct Node * head){
	struct Node * ptr = head;
	head = head->next;
	free(ptr);
	return head;
}

// case 2: Deleting element at given index from the  linked list
struct Node * deleteAtIndex(struct Node * head,int index){
	struct Node * p = head;
	struct Node * q = head->next;
	int i = 0;
	
	while(i!=index - 1){
		p = p->next;
		q = q->next;
		i++;
	}
	p->next = q->next;
	free(q);
	return head;
}

// case 3: Deleting last element 
struct Node * deleteLastElement(struct Node * head){
	struct Node * p = head;
	struct Node * q = head->next;
	
	while(q->next != NULL){
		p = p->next;
		q = q->next;
	}
	p->next = NULL;
	free(q);
	return head;
}

// case 4: Deleting element at given value of the  linked list
struct Node * deleteAtValue(struct Node * head,int value){
	struct Node * p = head;
	struct Node * q = head->next;
	
	while(q->data!=value && q->next!=NULL){
		p = p->next;
		q = q->next;
	}
    if(q->data == value){
    	p->next = q->next;
    	free(q);
	}
	return head;
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
	head ->data = 4; 
	head ->next = second; 
	
	//Link second and third nodes
	second ->data = 3; 
	second ->next = third; 
	
	//Link third and fourth nodes
	third ->data = 8; 
	third ->next = fourth; 
	
	// Terminate the list at the 4th node
	fourth ->data = 1; 
	fourth ->next = NULL; 
	
	printf("Linked list before deletion\n");
	linkedListTraversal(head);//(head)= where to start printing from
	
//	head = deleteFirst(head);//for deleting 1st element of linked list
//    head = deleteAtIndex(head, 2);//for deleting given index element of linked list
   // head = deleteLastElement(head);//for deleting last element
   head = deleteAtValue(head, 8);
	printf("Linked list after deletion\n");
	linkedListTraversal(head);//(head)= where to start printing from
	
	return 0;
}
