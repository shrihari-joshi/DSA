#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;
struct node *initialize(int x);
struct node *insert_front(struct node *head, int x);
struct node *insert_end(struct node *head, int x);
struct node *insert_index(struct node *head, int x, int i);

void print_list(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

struct node *initialize(int x)
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->data = x;
    head->next = NULL;
    return head;
}
struct node *insert_front(struct node *head, int x)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->next = head;
    ptr->data = x;
    return ptr;
}

struct node *insert_end(struct node *head, int x)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = x;
    ptr->next = NULL;
    if (head == NULL)
    {
        return ptr;
    }
    struct node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;

    return head;
}
struct node *insert_atindex(struct node *head, int x, int i)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = x;
    struct node *p = head;
    for (int j = 0; j < i-1 && p!=NULL; j++)
    {
        p = p->next;
    }
    if (p == NULL)
    {
        printf("Index out of bounds\n");
        free(ptr);
        return head;
    }
    ptr->next = p->next;
    p->next = ptr;
    return head;
}
void swap(struct node *head){
    int temp=0;
    struct node *p=head;
    while(p!=NULL && p->next!=NULL){
        temp=p->data;
        p->data=p->next->data;
        p->next->data=temp;
        p=p->next->next;
    }
    print_list(head);
}
int main()
{
    struct node *p = initialize(10);
    p = insert_end(p, 20);
    p = insert_end(p, 30);
    p = insert_end(p, 40);
    p = insert_end(p, 50);
    swap(p);
    return 0;
}