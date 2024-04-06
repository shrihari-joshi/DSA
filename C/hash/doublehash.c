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

    for (int i = 0; i < n; i++)
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
    int h1 = k % h->size;
    int h2 = 1 + (k % 11);
    if(h->status[h1] == 'E' || h->status[h1] == 'D')
    {
        h->keys[h1] = k;
        h->status[h1] = 'O';
        return;
    }
    else if (h->status[h1] == 'O')
    {
        while (true)
        {
            int index = (h1 + i * h2)%h->size;
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
}
int find(struct hash *h, int key)
{
    int c = 0;
    for (int i = 0; i < h->size; i++)
    {
        if (h->keys[i] == key && h->status[i] == 'O')
        {
            printf("%d FOUND\n", key);
            c++;
            return i + 1;
        }
    }
    if (c == 0)
        printf("%d NOT FOUND\n", key);
    return 0;
}
void delete(struct hash *h, int key)
{
    int c = 0;
    for (int i = 0; i < h->size; i++)
    {
        if (h->keys[i] == key)
        {
            printf("%d DELETED\n", key);
            c++;
            h->status[i] = 'D';
            // h->keys[i] = -1;
            return;
        }
    }
    if (c == 0)
        printf("%d NOT FOUND\n", key);
}
void print_hash(struct hash *h)
{
    for (int i = 0; i < h->size; i++)
    {
        printf("%d \t %d \t %c \n", i, h->keys[i], h->status[i]);
    }
}
int main()
{
    struct hash *h = initialize(13);
    // printf("hello123");
    insert(h, 79);
    insert(h, 69);
    insert(h, 98);
    insert(h, 72);
    insert(h, 14);
    insert(h, 50);
    // printf("hello");
    print_hash(h);
    find(h, 98);
    delete (h, 14);
    print_hash(h);
    find(h, 14);
}