#include <stdio.h>
#include <stdlib.h>

int *convert(int n, int *ptr)
{
    int i = 0;
    int j = 0;

    while (n > 0)
    {
        int z = n % 2;
        n = n / 2;
        *(ptr + i) = z;
        i++;
        j++;
    }
    return ptr;
}

void twos_compliment(int *ptrM, int length)
{
    int i = 0;

    while (*(ptrM + i) != 1)
    {
        i++;
    }
    for (int j = i + 1; j < length; j++)
    {
        if (*(ptrM + j) == 0)
        {
            *(ptrM + j) = 1;
        }
        else
        {
            *(ptrM + j) = 0;
        }
    }
}

void printN(int *n, int l)
{
    for (int i = l - 1; i >= 0; i--)
    {
        printf("%d", *(n + i));
    }
    printf("\t");
}

int findlength(int n)

{
    int i = 0;

    while (n > 0)
    {
        n = n / 2;
        i++;
    }
    return i;

}

void als(int *ptrQ, int *ptrA, int al, int ql)
{
    for (int j = al-1; j >= 0; j--)
    {
        *(ptrA + j) = *(ptrA + (j - 1));
    }

    *(ptrA) = *(ptrQ + (ql - 1));

    for (int j = ql-1; j >= 0; j--)
    {
        *(ptrQ + j) = *(ptrQ + (j - 1));
    }
}

void add(int *ptrA, int *ptrM, int ml)
{
    int carry = 0;
   
    for(int i = 0; i < ml; i++)
    {
        if((*(ptrA + i)) + (*(ptrM + i)) + carry == 1)
        {
            *(ptrA + i) = 1;
            carry = 0;
        }
        else if((*(ptrA + i)) + (*(ptrM + i)) + carry == 2)
        {
            *(ptrA + i) = 0;
            carry = 1;
        }
        else if((*(ptrA + i)) + (*(ptrM + i)) + carry == 3)
        {
            *(ptrA + i) = 1;
            carry = 1;
        }
        else
        {
            *(ptrA + i) = 0;
            carry = 0;
        }
    }
}

void algo(int *ptrA, int *ptrQ, int *ptrM, int *ptrM1, int ql, int al, int ml)
{
    printf("\n\n");
    printf(" 'A'");
    printf("\t'Q'");
    printf("   'Count'");
    printf("  'Operations'");
    printf("\n\n");
    printN(ptrA, al);
    printN(ptrQ, ql);
    printf(" 4\t");
    printf("Initial");
    printf("\n");
    printf("-------------------------------------------");
   
    for(int i = ql; i > 0; i--)
    {
        als(ptrQ, ptrA, al, ql);
        printf("\n");
        printN(ptrA, al);
        printN(ptrQ, ql);
        printf(" %d\t", i);
        printf("Left Shift");
       
        if(*(ptrA + ql) == 1)
        {
            add(ptrA, ptrM, ml);
            printf("\n");
            printN(ptrA, al);
            printN(ptrQ, ql);
            printf(" %d\t", i);
            printf("A <- A + M");
        }
        else
        {
            add(ptrA, ptrM1, ml);
            printf("\n");
            printN(ptrA, al);
            printN(ptrQ, ql);
            printf(" %d\t", i);
            printf("A <- A - M");
        }
       
        if(*(ptrA + ql) == 1)
        {
            printf("\n");
            printN(ptrA, al);
            printN(ptrQ, ql);
            printf(" %d\t", i);
            printf("Q0 = 0");
        }
        else
        {
            *(ptrQ + (i-i)) = 1;
            printf("\n");
            printN(ptrA, al);
            printN(ptrQ, ql);
            printf(" %d\t", i);
            printf("Q0 = 1");
        }
    printf("\n");
    printf("-------------------------------------------");
    }
   
    if(*(ptrA + ql) == 1)
    {
        printf("\n\nSince: A is negative (A%d = 1)\nWe restore.\n", ql);
        printf("i.e. A <- A + M");
        add(ptrA, ptrM, ml);
        printf("\n");
        printf("A : ");
        printN(ptrA, al);
        printf("\nQ : ");
        printN(ptrQ, ql);
    }
}

int main()
{
    int *ptrM = (int *)calloc(32, sizeof(int));
    int *ptrQ = (int *)calloc(32, sizeof(int));
    int *ptrM1 = (int *)calloc(32, sizeof(int));
    int *ptrA = (int *)calloc(32, sizeof(int));
    int m, q;
    printf("\n--|| NON RESTORING DIVISION ||--\n\n");
    printf("ENTER THE DIVIDEND (Q): ");
    scanf("%d", &q);
    printf("ENTER THE DIVISOR (M): ");
    scanf("%d", &m);
    printf("\n");
   
    int ml, ql, al;
    int flag = 0;
   
    ml = findlength(m);
    ql = findlength(q);
    ml = ql + 1;
    al = ml;
   

    ptrM = convert(m, ptrM);
    ptrQ = convert(q, ptrQ);
    ptrM1 = convert(m, ptrM1);
    twos_compliment(ptrM1, ml);
   
    printf("DIVIDEND (Q) = ");
    printN(ptrQ, ql);
    printf("\n");
    printf("DIVISOR (M) = ");
    printN(ptrM, ml);
    printf("\n");
    printf("(-M) = ");
    printN(ptrM1, ml);
    printf("\n");
    printf("ACCUMULATOR (A) = ");
    printN(ptrA, al);
   
    algo(ptrA, ptrQ, ptrM, ptrM1, ql, al, ml);
   
    printf("\n\n");
    printf("Remainder (A): ");
    printN(ptrA, al);
    printf("\n");
    printf("Quotient (Q): ");
    printN(ptrQ, al);
   
    return 0;
}