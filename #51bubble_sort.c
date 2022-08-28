#include<stdio.h>

void printArray(int *A, int n){
    for (int i = 0; i < n ; i++)
    {
        printf("%d ", A[i]);
    }    
    printf("\n");
}
void  bubbleSort(int* A, int n){
    int temp;
    int isSorted = 0;
    for (int i = 0; i < n-1; i++)// for no. of pass
    {
        printf("working on pass no. %d\n", i+1);// i starts from 0
        isSorted = 1;
       for (int j = 0; j < n-1-i; j++)// for no. of comparison in each pass
       {
           if(A[j]>A[j+1]){
               temp = A[j];
               A[j] = A[j+1];
               A[j+1] = temp;
               isSorted = 0;
           }
       }
       if (isSorted){
           return;
       }
       
    }
    
}
int main(){
    int A[] = {12, 54, 65, 7, 23, 9};// unsorted
   // int A[] = {1, 2, 3, 4, 5, 6};// sorted 
    int n = 6;//n = no. of terms in array
    printArray(A, n);// printing the array before sorting
    bubbleSort(A, n);// function to sort the array
    printArray(A, n);// printing the array after sorting
    
    return 0;
}