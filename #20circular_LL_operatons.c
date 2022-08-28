#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node * next;
	};

void linkedListTraversal(struct Node*head){
    struct Node * ptr = head;
    do{
	printf("Element is : %d\n", ptr->data);
	ptr = ptr->next;
    }while(ptr!=head);
}

struct Node * insertAtFirst(struct Node*head, int data){
	struct Node * ptr= (struct Node *) malloc(sizeof(struct Node));
	ptr->data = data;
	
	struct Node * p = head->next;
	while(p->next != head){
		p = p->next;
	}
	//at this point p point to the last node of the circular list
	p->next = ptr;
	ptr->next = head;
	head = ptr;
	return head;
}
int main(){
	struct Node * head;
	struct Node * second;
	struct Node * third;
	struct Node * fourth;
	
	head = (struct Node *) malloc(sizeof(struct Node));
	second = (struct Node *) malloc(sizeof(struct Node));
	third = (struct Node *) malloc(sizeof(struct Node));
	fourth = (struct Node *) malloc(sizeof(struct Node));
	
	head ->data = 7; 
	head ->next = second; 
	
	second ->data = 11; 
	second ->next = third; 
	
	third ->data = 66; 
	third ->next = fourth; 
	
	fourth ->data = 100; 
	fourth ->next = head; 
	printf("circular LL before insertion\n");
	linkedListTraversal(head);//(head)= where to start printing from
	head = insertAtFirst(head, 44);
	head = insertAtFirst(head, 3);
	printf("\n\ncircular LL after insertion\n");
	linkedListTraversal(head);//(head)= where to start printing from
	return 0;
}
