#include <stdio.h>
#include <stdbool.h>

#define max 10

struct Stack
{
    int array[max];
    int top;
};

void initialize(struct Stack *s)
{
    s->top = -1;
}

bool isFull(struct Stack *s)
{
    if (s->top == max - 1)
    {
        //  printf("Stack Overflow\n");
        return true;
    }
    else
        return false;
}

bool isEmpty(struct Stack *s)
{
    if (s->top == -1)
    {
        //   printf("Stack Underflow\n");
        return true;
    }
    else
        return false;
}

void push(struct Stack *s, int x)
{

    if (isFull(s))
        return;

    else
        s->array[++s->top] = x;
}

int pop(struct Stack *s)
{
    if (isEmpty(s))
        return 0;

    else
        return s->array[s->top--];
}

int peek(struct Stack *s)
{
    if (isEmpty(s))
    {
        return -1;
    }
    return s->array[s->top];
}

struct Queue
{
    struct Stack s1;
    struct Stack s2;
};

void enqueue(struct Queue *q, int element)
{
    if (isFull(&q->s1))
    {
        // printf("Queue is full\n");
        return;
    }
    while (!isEmpty(&q->s1))
    {
        push(&q->s2, pop(&q->s1));
    }
    push(&q->s1, element);

    while (!isEmpty(&q->s2))
    {
        push(&q->s1, pop(&q->s2));
    }
}

int dequeue(struct Queue *q)
{
    if (isEmpty(&q->s1))
    {
        return -1;
    }
    return pop(&q->s1);
}

void print(struct Queue *q)
{
    while (!isEmpty(&q->s1))
    {
        printf("%d\n", pop(&q->s1));
    }
}

int main()
{
    struct Queue queue;
    initialize(&queue.s1);
    initialize(&queue.s2);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);

    printf("%d is Dequeued\n", dequeue(&queue));
    printf("%d is Dequeued\n", dequeue(&queue));
    enqueue(&queue, 40);
    enqueue(&queue, 50);
    enqueue(&queue, 60);
    printf("%d is Dequeued\n", dequeue(&queue));
    print(&queue);
    return 0;
}
