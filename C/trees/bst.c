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
void in_order(struct node *root)
{
    if (root == NULL)
        return;
    in_order(root->left);
    printf("%d ", root->data);
    in_order(root->right);
}
struct node *insert(struct node *root, int x)
{
    if(root == NULL)
    {
        struct node *new = initialize(x);
        return new;
    }

    if (root->data > x)
    {
        if (root->left == NULL)
        {
            struct node *new = initialize(x);
            root->left = new;
        }
        else
            insert(root->left, x);
    }

    if (root->data < x)
    {
        if (root->right == NULL)
        {
            struct node *new = initialize(x);
            root->right = new;
        }
        else
            insert(root->right, x);
    }
    return root;
}

int main()
{
    struct node *root = NULL;
    root = insert(root,20);
    root = insert(root,15);
    root = insert(root,25);
    root = insert(root,10);
    root = insert(root,18);
    root = insert(root,23);
    root = insert(root,5);
    in_order(root);
    return 0;
}