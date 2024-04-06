#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct node
{
    char data;
    struct node *left;
    struct node *right;
};

struct Stack
{
    struct node **a;
    int top;
    unsigned capacity;
};

struct Stack *createStack(unsigned capacity)
{
    struct Stack *exstack = (struct Stack *)malloc(sizeof(struct Stack));
    exstack->capacity = capacity;
    exstack->top = -1;
    exstack->a = (struct node **)malloc(exstack->capacity * sizeof(struct node *));
    return exstack;
}

bool isempty(struct Stack *exstack)
{
    if (exstack->top == -1)
        return true;
    return false;
}

bool isfull(struct Stack *exstack)
{
    if (exstack->top == (exstack->capacity) - 1)
        return true;
    return false;
}

void push(struct Stack *exstack, struct node *element)
{
    if (isfull(exstack))
    {
        printf("Stack Overflow");
        return;
    }
    exstack->a[++(exstack->top)] = element;
}

void pop(struct Stack *exstack)
{
    if (isempty(exstack))
    {
        printf("Stack Underflow");
        return;
    }
    exstack->a[--exstack->top];
}

struct node *top(struct Stack *exstack)
{
    return exstack->a[exstack->top];
}

bool isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/')
        return true;
    return false;
}

struct node *initialize(char x)
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
    printf("%c", root->data);
    inorder_traversal(root->right);
}

struct node *tree(char *arr)
{

    int i = 0;
    while (i != '\n')
    {
        i++;
    }
    struct Stack *s = createStack(i);
    while (i >= 0)
    {
        if (isOperator(arr[i]))
        {
            struct node *new = initialize(arr[i]);
            new->left = top(s);
            pop(s);
            new->right = top(s);
            pop(s);
            push(s, new);
        }
        else
        {
            struct node *root1 = initialize(arr[i]);
            push(s, root1);
        }
        i--;
    }
    return top(s);
}
int evaluateExpressionTree(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (!isOperator(root->data))
    {
        return root->data - '0';
    }
    int left = evaluateExpressionTree(root->left);
    int right = evaluateExpressionTree(root->right);
    switch (root->data)
    {
    case '+':
        return left + right;
    case '-':
        return left - right;
    case '*':
        return left * right;
    case '/':
        if (right != 0)
        {
            return left / right;
        }
        else
        {
            printf("Division by zero error\n");
            exit(1);
        }
    default:
        return 0;
    }
}

int main()

{
    printf("Enter prefix expression : ");
    char *arr = NULL;
    size_t size = 0;
    getline(&arr, &size, stdin);

    printf("\n");
    struct node *root = tree(arr);
    inorder_traversal(root);
    int x=evaluateExpressionTree(root);
    printf("\nThe evaluation is: %d",x);
    return 0;
}
