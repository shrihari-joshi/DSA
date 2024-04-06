#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *pre;
} Node;

void print_list(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d", ptr->data);
        ptr = ptr->next;
    }
}

struct node *initialize(int c)
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->data = c;
    head->next = NULL;
    head->pre = NULL;
    return head;
}

struct node *insert_front(struct node *head, int c)
{
    struct node *new = initialize(c);
    new->next = head;
    new->pre=NULL;
    return new;
}

struct node *insert_end(struct node *head, int c)
{
    struct node *ptr = head;
    if (ptr == NULL)
    {
        return ptr;
    }
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    struct node *new = initialize(c);
    ptr->next = new;
    new->next = NULL;
    new->pre = ptr;
    return head;
}

struct node *insert_index(struct node *head, int c, int i)
{
    struct node *ptr = head;
    for (int j = 0; j < i - 1 && ptr != NULL; j++)
    {
        ptr = ptr->next;
    }
    if (ptr == NULL)
    {
        printf("Index out of bounds\n");
        free(ptr);
        return head;
    }
    struct node *new = initialize(c);
    new->next = ptr->next;
    struct node *temp=ptr->next;
    ptr->next = new;
    new->pre=ptr;
    temp->pre=new;
    return head;
}


int main()
{
    struct node *head = initialize(10);
    head = insert_end(head,20);
    head = insert_end(head,30);
    head = insert_front(head,100);
    print_list(head);
    
    return 0;
}