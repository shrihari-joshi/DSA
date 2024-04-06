#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *pre;
} Node;

void printlist(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    return;
}

struct node *initialize(int c)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = c;
    ptr->next = NULL;
    ptr->pre = NULL;
    return ptr;
}
struct node *insertfront(struct node *head, int c)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = c;
    new->pre = NULL;
    new->next = head;
    head->pre = new;
    return new;
}

struct node *insertend(struct node *head, int c)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    struct node *ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = new;
    new->data = c;
    new->pre = ptr;
    new->next = NULL;
    return head;
}

struct node *insertindex(struct node *head, int c, int i)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    struct node *ptr = head;
    for (int j = 0; j < i; j++)
    {
        ptr = ptr->next;
    }
    struct node *temp = ptr;
    new->next = ptr->next;
    ptr->next = new;
    new->pre = ptr;
    temp->pre = new;
    return head;
}

struct node *merge(struct node *l1, struct node *l2)
{
    struct node *result = initialize(-1);
    while (l2 != NULL)
    {
        l1 = insertend(l1, l2->data);
        l2 = l2->next;
    }
    return l1;
}
struct node *sort2(struct node *head)
{   struct node *current, *index;
    int temp;
    if (head == NULL)
        return NULL;
    for (current = head; current->next != NULL; current = current->next)
    {
        for (index = current->next; index != NULL; index = index->next)
        {
            if(current->data > index->data){
                temp= current->data;
                current->data=index->data;
                index->data=temp;
            }
        }
    }
    while (head->pre != NULL)
    {
        head = head->pre;
    }
    printlist(head);
    return head;
}

void sort(struct node *head)
{
    if (head == NULL || head->next == NULL)
        return;

    int swapped;
    struct node *current;
    struct node *prev = NULL;

    while (1)
    {
        swapped = 0;
        current = head;

        while (current->next != prev)
        {
            if (current->data > current->next->data)
            {
                int tempData = current->data;
                current->data = current->next->data;
                current->next->data = tempData;
                swapped = 1;
            }
            current = current->next;
        }
        prev = current;
        if (!swapped)
            break;
    }
    printlist(head);
}


int main()
{
    struct node *l1 = initialize(1);
    l1 = insertend(l1, 3);
    l1 = insertend(l1, 4);
    l1 = insertend(l1, 9);
    struct node *l2 = initialize(2);
    l2 = insertend(l2, 5);
    l2 = insertend(l2, 7);
    l2 = insertend(l2, 8);
    printf("List 1 is: ");
    printlist(l1);
    printf("\nList 2 is: ");
    printlist(l2);
    merge(l1, l2);
    printf("\nMerged List is: ");
    printlist(l1);

    printf("\nSorted List is: ");
    sort2(l1);
    return 0;
}
