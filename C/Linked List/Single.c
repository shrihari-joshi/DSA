#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

struct node *insert_front(struct node *next, int x);
struct node *insert_end(struct node *next, int x);
struct node *insert_index(struct node *next, int x, int i);

void print_list(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
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
    struct node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;

    return head;
}
struct node *insert_atindex(struct node *head, int x, int i)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p=head;
    for (int j = 0; j < i; j++)
    {
        p=p->next;
    }
    ptr->data=x;
    ptr->next=p->next;
    p->next = ptr;
    return head;
}

struct node *remove_duplicates(struct node *head) {
    struct node *current;
    
    for(current = head;current != NULL;current = current->next)
    {
        struct node *runner = current;

        while (runner->next != NULL) 
        {
            if (runner->next->data == current->data) 
            {
                runner->next = runner->next->next;
            } 
            else 
            {
                runner = runner->next;
            }
        }
        
    }

    return head;
}



int main(){
    struct node *head;
    head=(struct node *)malloc(sizeof(struct node));
    head->data=10;
    head->next=NULL;
    head = insert_front(head,20);
    head = insert_front(head,30);
    head = insert_front(head,40);
    head = insert_front(head,10);
    head = insert_front(head,50);
    head = insert_front(head,60);
    head = insert_end(head,70);
    print_list(head);
    head = remove_duplicates(head);
    printf("\nThe new list will be:\n\n");
    print_list(head);
    return 0;
}