#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

void print_list(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

struct node *initialize(struct node *head, int x)
{
    head = (struct node *)malloc(sizeof(struct node));
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
struct node *insert_index(struct node *head, int x, int i)
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
int end(struct node *head){
    struct node *ptr = head;
    while(ptr->next != NULL)
    {
        ptr = ptr->next;
    }
        
    return ptr->next->data;
}
struct node *delete_end(struct node *head){
    struct node *ptr = head;
    while(ptr->next->next != NULL)
        ptr = ptr->next;
    ptr->next = NULL;
    return head;
}
struct node *delete_front(struct node *head){
    struct node *ptr = head->next;
    head->next = NULL;
    return ptr;
}
int palindrome(char arr[], int n)
{
    struct node *head = initialize(head,arr[0]);
    for(int i=1;i<n;i++)
        insert_end(head,arr[i]);

    // print_list(head);
    printf("%c",end(head));
    for(int i=0;i<(n/2) - 1 ;i++)
    {
        if(head->data == end(head))
        {
            head = delete_end(head);
            head = delete_front(head);
        }
        else 
        return 0;
    }
    return 1;
    
}
void identify(int arr1[], int arr2[], int n)
{
    struct node *p = NULL;
    struct node *q = NULL;
    int size=n;
    initialize(p, arr1[0]);
    initialize(q, arr2[0]);
    for(int i=0;i<size;i++){
        p=insert_end(p,arr1[i]);
        q=insert_end(q,arr2[i]);
    }
    print_list(p);
    print_list(q);

     while (p != NULL && q != NULL)
    {
        if (p->data != q->data)
        {
            printf("Linked Lists are not Identical\n");
            return;
        }
        p = p->next;
        q = q->next;
    }
    
    if (p == NULL && q == NULL)
    {
        printf("Linked Lists are Identical\n");
    }
    else
    {
        printf("Linked Lists are not Identical\n");
    }
    
}

int main()
{   int n;
    printf("Enter the size of the Lists: ");
    scanf("%d", &n);
    int arr1[n], arr2[n];
    printf("Enter the elements for List 1:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr1[i]);
    }
    printf("Enter the elements for List 2:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr2[i]);
    }
    identify(arr1, arr2,n);
    // int res = palindrome(arr1,n);
    // printf("The result is: %d",res);
    return 0;
}