#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* right;
    struct node* left;
};
struct node *initialize(int x){
    struct node *new=(struct node*)malloc(sizeof(struct node));
    new->data=x;
    new->left=NULL;
    new->right=NULL;
    return new;
}
void inorder_traversal(struct node *root){
    if(root==NULL)
    return;
        inorder_traversal(root->left);
        printf("%d ",root->data);
        inorder_traversal(root->right);
}
void pre_traversal(struct node *root){
    if(root==NULL)
    return;
        printf("%d ",root->data);
        pre_traversal(root->left);
        pre_traversal(root->right);
}
void post_traversal(struct node *root){
    if(root==NULL)
    return;
        post_traversal(root->left);
        post_traversal(root->right);
        printf("%d ",root->data);
}


int main(){
    struct node* root = initialize(1);
    root->left=initialize(2); 
    root->right=initialize(3); 
    root->left->left=initialize(4); 
    root->left->right=initialize(5);
    root->right->left=initialize(6);
    root->right->right=initialize(7);
    inorder_traversal(root);
    printf("\n");
    pre_traversal(root);
    printf("\n");
    post_traversal(root);
    return 0;
}