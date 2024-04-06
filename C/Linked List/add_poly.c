#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int constant;
    int pow;
    struct node *next;
} Node;


void print_list(struct node *ptr)
{
    ptr = ptr->next;
    while (ptr != NULL)
    {
        printf("%dx^%d \t", ptr->constant, ptr->pow);
        ptr = ptr->next;
    }
}

struct node *initialize(int c, int p)
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->constant = c;
    head->pow = p;
    head->next = NULL;
    return head;
}

struct node *insert_front(struct node *head, int c, int p)
{
    struct node *new = initialize(c, p);
    new->next = head;
    return new;
}

struct node *insert_end(struct node *head, int c, int p)
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
    struct node *new = initialize(c, p);
    ptr->next = new;
    new->next = NULL;
    return head;
}

struct node *insert_index(struct node *head, int c, int p, int i)
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
    struct node *new = initialize(c, p);
    new->next = ptr->next;
    ptr->next = new;
    return head;
}
void multiply(int c1[], int c2[], int p1[], int p2[], int m, int n)
{
    printf("Multiplication will be:\n");
    struct node *poly1 = initialize(c1[0], p1[0]);
    struct node *poly2 = initialize(c2[0], p2[0]);
    struct node *result = initialize(0, 0);

    for (int i = 1; i < m; i++)
    {
        poly1 = insert_end(poly1, c1[i], p1[i]);
    }
    for (int i = 1; i < n; i++)
    {
        poly2 = insert_end(poly2, c2[i], p2[i]);
    }
    if(poly1 == NULL)
    result = poly2;

    if(poly2 == NULL)
    result = poly1;

    while(poly1 != NULL && poly2 != NULL)
    {
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int c = poly1->constant*poly2->constant;
                int p = poly1->pow + poly2->pow;
                result = insert_end(result,c,p);
            }
        }
    }
    print_list(result);
}
void add(int c1[], int c2[], int p1[], int p2[], int n)
{
    struct node *poly1 = initialize(c1[0], p1[0]);
    struct node *poly2 = initialize(c2[0], p2[0]);
    struct node *result = initialize(0, 0);

    for (int i = 1; i < n; i++)
    {
        poly1 = insert_end(poly1, c1[i], p1[i]);
    }
    for (int i = 1; i < n; i++)
    {
        poly2 = insert_end(poly2, c2[i], p2[i]);
    }

    while (poly1 != NULL || poly2 != NULL)
    {
        if (poly1 == NULL)
        {
            result = insert_end(result, poly2->constant, poly2->pow);
            poly2 = poly2->next;
        }
        else if (poly2 == NULL)
        {
            result = insert_end(result, poly1->constant, poly1->pow);
            poly1 = poly1->next;
        }
        else if (poly1->pow > poly2->pow)
        {
            result = insert_end(result, poly1->constant, poly1->pow);
            poly1 = poly1->next;
        }
        else if (poly1->pow < poly2->pow)
        {
            result = insert_end(result, poly2->constant, poly2->pow);
            poly2 = poly2->next;
        }
        else if (poly1->pow == poly2->pow)
        {
            int x = poly1->constant + poly2->constant;
            result = insert_end(result, x, poly1->pow);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }

    print_list(result);
    arrange(result);
}
void arrange(struct node *poly)
{
    struct node *current, *index;
    int temp1;
    int temp2;
    for(current = poly;current != NULL; current = current->next)
    {
        for(index = current->next; index != NULL; index = index->next)
        {
            if(current->constant > index->constant)
            {
                temp1 = current->constant;
                current->constant = index->constant;
                index->constant = temp1;
                temp2 = current->pow;
                current->pow = index->pow;
                index->pow = temp2;
            }
        }

    }  
    printf("the sorted polynomial is:\n");
    print_list(poly);
}

int main()
{
    int m;
    printf("Enter the number of terms in polynomial 1\n");
    scanf("%d", &m);
    int n;
    printf("Enter the number of terms in polynomial 2\n");
    scanf("%d", &n);
    printf("Enter the constant and power of each term for polynomial 1\n");
    int c1[n];
    int p1[n];
    for (int i = 0; i < m; i++)
    {
        scanf("%d\t%d", &c1[i], &p1[i]);
    }

    printf("Enter the constant and power of each term for polynomial 2\n");
    int c2[n];
    int p2[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d\t%d", &c2[i], &p2[i]);
    }
    multiply(c1, c2, p1, p2, m,n);
    return 0;
}