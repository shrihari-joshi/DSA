#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    char data;
    struct node *next;
    struct node *pre;
} Node;

void print_list(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%c", ptr->data);
        ptr = ptr->next;
    }
}

struct node *initialize(char c)
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->data = c;
    head->next = NULL;
    head->pre = NULL;
    return head;
}

struct node *insert_front(struct node *head, char c)
{
    struct node *new = initialize(c);
    new->next = head;
    new->pre=NULL;
    return new;
}

struct node *insert_end(struct node *head, char c)
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

struct node *insert_index(struct node *head, char c, int i)
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
void palindrome(char arr[], int n){
    struct node *num = initialize(arr[0]);
    for(int i=1;i<n;i++){
        num=insert_end(num,arr[i]);
    }
    print_list(num);
    struct node *ptr=num;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    if(num->data==ptr->data)
    {
        num=num->next;
        ptr=ptr->pre;
    }
    else{
        printf("Not a Palindrome");
        return;
    }
    printf("It is a Palindrome");
}

int main()
{   
    int n;
    printf("Enter the number of digits");
    scanf("%d",&n);
    printf("Enter the number to be checked:");
    char arr[n];
    for(int i=0;i<n;i++){
        scanf("%c", &arr[i]);
    }
    palindrome(arr,n);
    return 0;
}