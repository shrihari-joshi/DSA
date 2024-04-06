#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define max 3
struct Queue
{
    int *arr;
    int front;
    int rear;
    int N;
};
struct Queue *initialize(struct Queue *q, int size)
{
    q->arr = (int *)malloc(size * sizeof(int));
    q->rear = -1;
    q->front = -1;
    q->N = size;
    return q;
}

bool isFull(struct Queue *q)
{
    if ((q->rear)== q->N-1)
    {
        return true;
    }
    else
        return false;
}

bool isEmpty(struct Queue *q)
{
    if (q->front == -1)
    {
        return true;
    }
    else
        return false;
}

void enqueue(struct Queue *q, int x)
{   
    if (isFull(q))
        return;

    if (isEmpty(q))
        q->front = 0;
        q->rear++;
        q->arr[q->rear] = x;
    return;
}

int dequeue(struct Queue *q)
{
    int val;
    if (isEmpty(q))
    {
        return -1;
    }
    else if (q->front == q->rear)
    {
        val = q->arr[q->front];
        q->rear = -1;
        q->front = -1;
    }
    else
    {
        val = q->arr[q->front];
        q->front++;
    }
    return val;
}
bool isOdd(int x){
    if(x%2==0)
    return false;
    return true;
}
int vip(int arr[], int n)
{
    struct Queue q1;
    struct Queue q2;
    initialize(&q1, n);
    initialize(&q2, n);
    for (int i = 0; i < n; i++)
    {   
        if(isOdd(arr[i]))
        enqueue(&q1, arr[i]);
        else
        enqueue(&q2, arr[i]);
    }
    while(!isEmpty(&q2)){
        printf("%d\t",dequeue(&q2));
    }
    while(!isEmpty(&q1)){
        printf("%d\t",dequeue(&q1));
    }
    
}

int main()
{
    int size =10;
    struct Queue *queue[max]; 
 for(int i=0;i<max;i++){ 
 queue[i]=initialize(queue[i],size); 
 } 
 enqueue(queue[0],1); 
 enqueue(queue[0],2); 
 enqueue(queue[1],1); 
 enqueue(queue[1],2); 
 enqueue(queue[2],3); 
 enqueue(queue[2],4); 
 for(int i=0;i<max;i++){ 
 printf("Element of queue at index %d : ",i); 
 while(!isEmpty(queue[i])){ 
 printf("%d ",dequeue(queue[i])); 
 } 
 printf("\n"); 
 } 
 return 0; 
}
