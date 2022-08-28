#include <stdio.h>
int linearSearch(int arr[], int size, int element){
	int i = 0;
	for(; i < size; i++)
	{
		if(arr[i]==element){
			return i;
		}
	}
	return -1;
}

int binarySearch(int arr[], int size, int element){
	int low, mid, high;
	low = 0;
	high = size - 1;
	// keep searching until low <= high
	while(low<=high){
		mid = (low + high)/2;
		if(arr[mid] == element){
			return mid;
		}	
		if(arr[mid]<element){
			low = mid + 1;
		}
		else{
			high = mid - 1;
		}
	}
	return -1;
}

int main(){
	//unsroted array for linear search
	//int arr[] = {1,3,5,56,4,7,353,22,5,6,45,,67};
	// int size = sizeof(arr)/sizeof(int);
	
	//sorted array for binary search
	int arr[] = {1,3,5,56,64,73,123,225,444};
	int size = sizeof(arr)/sizeof(int);
	int element = 64;
	int searchIndex = binarySearch(arr, size, element);
	printf("The element %d was found at index %d \n", element, searchIndex);
	return 0;
	}









