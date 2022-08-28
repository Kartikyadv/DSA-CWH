#include<stdio.h>
#include<stdlib.h>

struct queue
{
    int size;
    int f;
    int r;
    int * arr;
};

int isFull(struct queue *q){
    if(q->r==q->size-1)
        return 1;
    else
    return 0;
}
int isEmpty(struct queue *q){
    if(q->f==q->r){
        return 1;
    }
    return 0;
}

void enqueue(struct queue *q, int val){
    if(isFull(q)){
        printf("This Queue is full\n");
    }
    else{
        q->r++;
        q->arr[q->r] = val;
    }
}

int dequeue(struct queue *q){
    int a = -1;
    if(isEmpty(q)){
        printf("This queue is Empty\n");
    }
    else{
        q->f++;
        a = q->arr[q->f];
        return a;
    }
}
int main()
{
    struct queue q;
    q.size = 400;
    q.f = q.r = 0;
    q.arr = (int*) malloc(q.size*sizeof(int));

    //BFS implementation
    int v;
    int i = 0; // source code (starting node)
    int visited[7] = {0,0,0,0,0,0,0}; // 0 for unvisited & 1 for visited
    int a[7][7] = {
        {0,1,1,1,0,0,0},
        {1,0,1,0,0,0,0},
        {1,1,0,1,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0},
    };
    printf("%d", i);
    visited[i] = 1; // marking visited
    enqueue(&q, i) ; // enqueue i(0) in starting for exploration
    while(!isEmpty(&q)){
        int node  =dequeue(&q);//for starting node = 0
        for (int j = 0; j < 7; j++)
        {
            if(a[node][j] ==1 && visited[j] == 0){// node = source node       j == 2nd element
                printf("%d", j);
                visited[j] = 1;// marking 2nd element as visited
                enqueue(&q, j) ;
            }
        }
    }
    return 0 ;
}