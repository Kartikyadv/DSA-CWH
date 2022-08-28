#include <stdio.h>

void display(int arr[], int n){
	int i =0;
	for(;i< n ;i++ )
	{                                   //traversing array
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void indDeletion(int arr[],int size,int index){
	int i = index;
	for(; i < size - 1; i++)            // deletingarray
	{
		arr[i] = arr[i+1];
	}
}

int main(){
	int arr[100] = {7, 8, 12, 27, 88};
	int size = 5, index = 1;
	display(arr, size);
	indDeletion(arr, size, index);
	size -=1;
	display(arr, size);
	return 0;
}
