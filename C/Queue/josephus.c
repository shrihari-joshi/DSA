#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

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
    if ((q->rear + 1) % q->N == q->front)
    {
        printf("Queue Overflow\n");
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
    if (isEmpty(q))
    {
        q->front = 0;
        q->rear++;
        q->arr[q->rear] = x;
    }
    else if (isFull(q))
    {
        return;
    }
    else
    {
        q->rear = (q->rear + 1) % q->N;
        q->arr[q->rear] = x;
    }
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
        q->front = (q->front + 1) % q->N;
    }
    return val;
}

int winner(int arr[], int n, int k)
{
    struct Queue q1;
    initialize(&q1, n);

    for (int i = 1; i <= n; i++)
    {
        enqueue(&q1, arr[i]);
    }
    int c = 1;
    while (!(q1.front == q1.rear))
    {
        if (c % k != 0)
            enqueue(&q1, dequeue(&q1));
        else
            dequeue(&q1);
        c++;
    }
    return q1.arr[q1.front] - 1;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n, k;
    printf("Enter the value of n and k:\n");
    scanf("%d", &n);
    scanf("%d", &k);
    int result = winner(arr, n, k);
    printf("%d", result);
    return 0;
}
