#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct hash
{
    int size;
    int *keys;
    char *status;
};
int count = 0;

struct hash *initialize(int n)
{
    struct hash *h = (struct hash *)malloc(sizeof(struct hash));
    h->size = n;
    h->keys = (int *)malloc(n * sizeof(int));
    h->status = (char *)malloc(n * sizeof(int));
    
    for(int i=0;i<n;i++)
    {
        h->status[i] = 'E';
        h->keys[i] = -1;
    }
    return h;
}

void insert(struct hash *h, int k)
{
    if (count == h->size)
    {
        printf("Hash map is full");
        return;
    }
    int i = 0;
    
    while (true)
    {
        int index = (k % h->size + i) % h->size;
        if (h->status[index] == 'E' || h->status[index] == 'D')
        {
            h->keys[index] = k;
            h->status[index] = 'O';
            count++;
            break;
        }
        else
        i++;
    }
}
int find(struct hash* h, int key){
    int c=0;
    for(int i=0;i<h->size;i++){
        if(h->keys[i]==key && h->status[i] == 'O')
        {
            printf("%d FOUND\n", key);
            c++;
            return i+1;
        }
    }
    if(c==0)
    printf("%d NOT FOUND\n", key);
    return 0;
}
void delete(struct hash* h, int key){
    int c=0;
    for(int i=0;i<h->size;i++){
        if(h->keys[i]==key)
        {
            printf("%d DELETED\n", key);
            c++;
            h->status[i] = 'D';
            // h->keys[i] = -1;
            return;
        }
    }
    if(c==0)
    printf("%d NOT FOUND\n", key);
}
void print_hash(struct hash* h)
{
    for(int i=0;i<h->size;i++)
    {
        printf("%d \t %d \t %c \n",i,h->keys[i],h->status[i]);
    }

}
int main()
{
    struct hash *h = initialize(10);
    // printf("hello123");
    insert(h,9);
    insert(h,19);
    insert(h,29);
    insert(h,39);
    insert(h,49);
    insert(h,59);
    // printf("hello");
    print_hash(h);
    find(h,28);
    delete(h,49);
    print_hash(h);
    find(h,49);
}