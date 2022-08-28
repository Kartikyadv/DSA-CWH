#include <stdio.h>

void printArray(int *A, int n){
    for (int i = 0; i < n ; i++)
    {
        printf("%d ", A[i]);
    }    
    printf("\n");
}

void insertionSort(int *A,int n){
    int key, j;
    for (int i = 0; i <= n-1; i++)
    {
        key = A[i];
        j = i-1;// i = index value j = index - 1
        /* Loop for each pass  */
        while(j>= 0 && A[j] > key){// < for descending & > for ascending
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;// where j = -1 so -1 + 1 = 0 index
    }
    
}
int main(){
    // -1   0   1   2   3   4   5
    //     12, 54, 65, 7,  23,  9
    int A[] = {12, 54, 65, 7, 23, 9};// unsorted
    int n = 6;
    printArray(A, n);
    insertionSort(A, n);
    printArray(A, n);
    return 0;
}