#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int size = 0;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void min_heap(int array[], int size, int i)
{
    if(size == 1)
    {
        printf("Only one element");
        return;
    }
    else
    {
        int parent = i;
        int l = 2*i + 1;
        int r = 2*i + 2;

        if(l<size && array[l] < array[parent])
            parent = l;
        if(r<size && array[r] < array[parent])
            parent = r;
        if(parent != i)
        {
            swap(&array[parent], &array[i]);
            min_heap(array, size, parent);
        }
    }
}
void insert(int array[], int new){
    if(size == 0)
    {
        array[size] = new;
        size++;
    }
    else
    {
        array[size] = new;
        size++;
        for(int i=(size/2) - 1;i>=0;i--)
            min_heap(array,size,i);
            
        printf("Heap will be: ");
        print(array,size);
        printf("\n");
    }
}
void delete(int array[], int num)
{
    int temp = size;
    int i=0;
    for(i;i<temp;i++)
    {
        if(num == array[i])
        break;
    }
    swap(&array[i], &array[temp-1]);
    temp--;
    for(int i= (temp/2) - 1;i>=0;i--)
        min_heap(array,temp, i);
    
}

void heapsort(int array[])
{
    int x = size;
    for(int i=0;i<x;i++){
        delete(array,array[i]);
    }
        
}
void print(int array[], int size){
    for(int i=0;i<size;i++)
        printf("%d ",array[i]);
    printf("\n");
}
int main(){
    int array[10];
    int temp[10];
    printf("Enter the number of elements: ");
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&temp[i]);
        // insert(array,temp[i]);        
    }
    for(int i=0;i<n;i++){
        insert(array,temp[i]);        
    }
    printf("\nMin Heap will be: \n");
    print(array, size);
    printf("\nHeapsort will be: \n");
    heapsort(array);
    print(array,size);
}