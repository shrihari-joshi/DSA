#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char str[3];
int k = 0;
struct node *temp = NULL;

struct node
{
    int data;
    struct node *right;
    struct node *left;
    int height;
};
struct node *initialize(int x)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = x;
    new->left = NULL;
    new->right = NULL;
    int height = 0;
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
void preorder_traversal(struct node *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}
int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}
int getheight(struct node *root)
{
    if (root == NULL)
        return -1;
    return max(getheight(root->left), getheight(root->right)) + 1;
}

struct node *RotateLL(struct node *root, int value)
{
    if (root == temp)
    {
        struct node *tp = root;
        root = root->left;
        tp->left = root->right;
        root->right = tp;
    }

    else
    {
        if (value < root->data)
            root->left = RotateLL(root->left, value);
        else
            root->right = RotateLL(root->right, value);
    }
    root->height =getheight(root->left) -getheight(root->right);
    return root;
}

struct node *RotateRR(struct node *root, int value)
{
    if (root == temp)
    {
        struct node *tp = root;
        root = root->right;
        tp->right = root->left;
        root->left = tp;
    }

    else
    {
        if (value < root->data)
            root->left = RotateRR(root->left, value);
        else
            root->right = RotateRR(root->right, value);
    }
    root->height = getheight(root->left) - getheight(root->right);
    return root;
}

struct node *RotateLR(struct node *root, int value)
{
    if (root == temp)
    {
        struct node *tp = root;
        struct node *tp1 = root->left->right;
        struct node *tp2 = root->left;
        tp->left = tp1->right;
        tp2->right = tp1->left;
        tp1->left = tp2;
        tp1->right = tp;
        root = tp1;
    }

    else
    {
        if (value < root->data)
            root->left = RotateLR(root->left, value);
        else
            root->right = RotateLR(root->right, value);
    }
    root->height = getheight(root->left) - getheight(root->right);
    return root;
}

struct node *RotateRL(struct node *root, int value)
{
    if (root == temp)
    {
        struct node *tp = root;
        struct node *tp1 = root->right->left;
        struct node *tp2 = root->right;
        tp->right = tp1->left;
        tp2->left = tp1->right;
        tp1->left = tp;
        tp1->right = tp2;
        root = tp1;
    }

    else
    {
        if (value < root->data)
            root->left = RotateRL(root->left, value);
        else
            root->right = RotateRL(root->right, value);
    }
    root->height = getheight(root->left) - getheight(root->right);
    return root;
}


void fillString(struct node *root)
{
    if (root->height > 1 || root->height < -1)
    {
        if (root->left != NULL)
        {
            if (root->left->height == 1)
            {
                str[0] = 'L';
                str[1] = 'L';
            }

            else if (root->left->height == -1)
            {
                str[0] = 'L';
                str[1] = 'R';
            }
        }

        if (root->right != NULL)
        {
            if (root->right->height == -1)
            {
                str[0] = 'R';
                str[1] = 'R';
            }

            else if (root->right->height == 1)
            {
                str[0] = 'R';
                str[1] = 'L';
            }
        }
    }
}

struct node *insertion(struct node *root, int x) {
    if (root == NULL) {
        return initialize(x);
    }

    if (x < root->data) {
        root->left = insertion(root->left, x);
    } else if (x > root->data) {
        root->right = insertion(root->right, x);
    }

    root->height = max(getheight(root->left), getheight(root->right)) + 1;
    fillString(root);
    return root;
}

struct node* insert(struct node *root, int x){
    k=0;
    root = insertion(root,x);
}
int Decision()
{
    if (str[0] == 'L' && str[1] == 'L')
        return 1;

    else if (str[0] == 'R' && str[1] == 'R')
        return 2;

    else if (str[0] == 'L' && str[1] == 'R')
        return 3;

    else if (str[0] == 'R' && str[1] == 'L')
        return 4;
}

struct node *CheckImbalance(struct node *root, int value)
{
    if (root == NULL)
        return NULL;

    if ((root->height == 0) || (root->height == -1) || (root->height == 1))
    {
        if (value < root->data)
        {
            root = CheckImbalance(root->left, value);
            if (root != NULL)
                return root;
            else
                return NULL;
        }

        else
        {
            root = CheckImbalance(root->right, value);
            if (root != NULL)
                return root;
            else
                return NULL;
        }
    }

    else
    {
        struct node *imbalance = NULL;
        while (root->height > 1 || root->height < -1)
        {
            if (value < root->data)
            {
                imbalance = root;
                root = root->left;
            }
            else
            {
                imbalance = root;
                root = root->right;
            }
        }
        return imbalance;
    }
}

void balancefactor(struct node *root)
{
    if (root == NULL)
        return;

    root->height = getheight(root->left) - getheight(root->right);
    balancefactor(root->left);
    balancefactor(root->right);
}

int main()
{

    struct node *root = NULL;
    while (true)
    {
        printf("\nEnter value: ");
        int value;
        scanf("%d", &value);

        if (value == -1)
        {
            break;
        }

        root = insert(root, value);
        int flag = 0;
        while (true)
        {
            balancefactor(root);
            temp = CheckImbalance(root, value);
            if (temp != NULL)
            {
                printf("Imbalance at %d with BF %d \n", temp->data, temp->height);
                fillString(temp);
            }

            if (temp == NULL)
            {
                if (flag == 0)
                {
                    printf("\nBalanced");
                    printf("\nPREORDER:");
                    preorder_traversal(root);
                    printf("\nINORDER:");
                    inorder_traversal(root);
                    printf("\n");
                }
                break;
            }

            else
            {
                switch (Decision())
                {
                case 1: 
                {
                    root = RotateLL(root, value);
                    printf("LL Rotation");
                    break;
                }
                case 2: 
                {
                    root = RotateRR(root, value);
                    printf("RR Rotation");
                    break;
                }
                case 3: 
                {
                    root = RotateLR(root, value);
                    printf("LR Rotation");
                    break;
                }
                case 4: 
                {
                    root = RotateRL(root, value);
                    printf("RL Rotation");
                    break;
                }
                }
                printf("\nPREORDER");
                preorder_traversal(root);
                printf("\nINORDER");
                inorder_traversal(root);
                printf("\n");
                flag++;
            }
        }
    }
    return 0;
}