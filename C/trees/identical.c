#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *right;
    struct node *left;
};
struct node *initialize(int x)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = x;
    new->left = NULL;
    new->right = NULL;
    return new;
}
void inorder_traversal(struct node *root)
{
    if (root == NULL)
        return;
    inorder_traversal(root->left);
    printf("%d ", root->data);
    inorder_traversal(root->right);
}
void identical(struct node *root1, struct node *root2)
{
    int c=0;
    if (root1 == NULL || root2 == NULL)
        return;
    else
    {
        if(root1->data == root2->data){
            
            identical(root1->left, root2->left);
            identical(root1->right, root2->right);
        }
        
        if(root1->data != root2->data){
            printf("Not-Equal ");
            c=1;
            return;

        }
    }
    if(c==0)
    printf("Equal ");
}

int main()
{
    struct node *root = initialize(1);
    root->left = initialize(2);
    root->right = initialize(3);
    root->left->left = initialize(4);
    root->left->right = initialize(5);
    root->right->left = initialize(6);
    root->right->right = initialize(7);
    inorder_traversal(root);
    printf("\n");

    struct node *root2 = initialize(1);
    root2->left = initialize(2);
    root2->right = initialize(3);
    root2->left->left = initialize(8);
    root2->left->right = initialize(5);
    root2->right->left = initialize(6);
    root2->right->right = initialize(7);
    inorder_traversal(root2);

    identical(root, root2);
    return 0;
}