#include <stdio.h>
#include <stdlib.h>
struct myAraay { //ABSTRACT DATATYPE
	int total_size;
	int used_size;
	int * ptr;//request memory in heap
};

void createArray(struct myArray * a, int tsize, int usize) {
// 	(*a).total_size = tsize;
// 	(*a).used_size = usize;
// 	(*a).ptr = (int *) malloc(tsize*sizeof(int));
// 	          OR
	a->total_size = tsize;
	a->used_size = usize;
	a->ptr = (int *)malloc(tsize * sizeof(int));//pointing 1st element of array in HEAP
}

void show(struct myArray *a) {
	for(int i =0; i < a->used_size; i++) {
		printf("%d\n", (a->ptr)[i]);
	}
}

void setVal(struct myArray *a) {
	int n;
	for(int i =0; i < a->used_size; i++) {
		printf("Enter element %d", i);
		scanf("%d", &n);
		(a->ptr)[i] = n;
	}

}

int main() {
	struct myArray marks;//making storage of int total size = 4 byte etc
	createArray(&marks, 10, 2);//taking address of mark structure and total & used size
	printf("We are running setVal now\n");
	setVal(&marks);//taking value from user
	//passing struct address by myarray
	printf("We are running show now\n");
	show(&marks);
	return 0;
}
