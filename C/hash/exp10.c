#include <stdio.h>
#include <stdlib.h>
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
void maxHeapify(int arr[], int index, int n)
{
    int smallest = index;
    int left = index * 2 + 1;
    int right = index * 2 + 2;
    if (left < n && arr[smallest] > arr[left])
        smallest = left;
    if (right < n && arr[smallest] > arr[right])
        smallest = right;
    if (smallest != index)
    {
        swap(arr + smallest, arr + index);
        maxHeapify(arr, smallest, n);
    }
}

void buildMinHeap(int arr[], int n)
{
    for (int i = (n - 1) / 2; i >= 0; i--)
        maxHeapify(arr, i, n);
}
void HeapSort(int arr[], int n)
{
    int size = n - 1;
    while (size >= 0)
    {
        swap(arr, arr + size);
        maxHeapify(arr, 0, size);
        printArray(arr, size);
        size--;
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
int main()
{
    int n;
    printf("Enter no of elements to be inserted: ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", arr + i);
    printf("Original array\n");
    printArray(arr, n);
    buildMinHeap(arr, n);
    printf("After building min Heap\n");
    printArray(arr, n);
    printf("\nSorting\n");
    HeapSort(arr, n);
    printf("After sorting array\n");
    printArray(arr, n);+
    return 0;
}

