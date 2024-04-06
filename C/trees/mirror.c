#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int arr1[6]={0,0,0,0,0,0}, arr2[6]={0,0,0,0,0,0};
int j = 0;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *initialize(int x)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = x;
    new->left = NULL;
    new->right = NULL;
}

struct node *create()
{
    struct node *temp, *root;
    int data, choice;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("\n Press 0 to exit");
    printf("\nPress 1 for new node");
    printf("\n Enter your choice : ");
    scanf("%d", &choice);
    if (choice == 0)
        return 0;
    else
    {
        printf("Enter the data:");
        scanf("%d", &data);
        temp->data = data;
        printf("\n Enter the left child of %d", data);
        temp->left = create();
        printf("\n Enter the right child of %d", data);
        temp->right = create();
        return temp;
    }
}

void inorder_traversal(struct node *root)
{
    if (root == NULL)
        return;
    inorder_traversal(root->left);
    printf("%d", root->data);
    arr1[j] = root->data;
    j++;
    inorder_traversal(root->right);
    
}
void checkmirror(int arr1[], int arr2[])
{   int c=0;
    for (int i = 0; i < 3; i++)
    {   if(arr1[i]==arr1[i+3])
        continue;
        else c++;
    }
    if(c==0)
    printf("Trees are not Identical");
    else 
    printf("Identical");
}
void mirror(struct node *root)
{
    if (root == NULL)
        return;
    struct node *temp;
    temp = root->left;
    root->left = root->right;
    root->right = temp;
    mirror(root->left);
    mirror(root->right);
}
int main()
{
    struct node *root = create();
    printf("Inorder Traversal of Original Tree:\n");
    inorder_traversal(root);
    printf("\n");
    for(int n=0;n<6;n++){
        printf("%d ",arr1[n]);
    }
    mirror(root);
   printf("\nInorder Traversal of Mirror Tree:\n");
    inorder_traversal(root);

    struct node *root2 = create();
    inorder_traversal(root2);
    printf("\n");
    //  for(int n=0;n<3;n++){
    //     printf("%d ",arr2[n]);
    // }
    checkmirror(arr1, arr2);
    return 0;
}
