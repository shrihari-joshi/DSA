#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


int *binary(int l, int n, int *bi)
{
    int c = 0;
    for (int i = 0; n > 0; i++)
    {
        bi[i] = n % 2;
        n = n / 2;
        c++;
    }
    for(int i=c;i<l;i++){
        bi[i]=0;
    }
    // for (int i = l - 1; i >= 0; i--)
    // {
    //     printf("%d", bi[i]);
    // }

    return bi;
}
int size(int n)
{
    int c = 0;
    for (int i = 0; n > 0; i++)
    {
        n = n / 2;
        c++;
    }
    return c;
}
int AND(int *A, int*B, int l){
    int c=0;
    // printf("hiii");
    
    for(int i=0;i<l;i++){
        if(A[i]==1 && B[i] ==1)
            c++;
    }
    return c;
}
int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
     int n1, n2;
    scanf("%d %d", &n1, &n2);
    int l = 0;
    if (n1 > n2)
        l = size(n1);

    else
        l = size(n2);
    int x1[l];
    int x2[l];

    int *A = binary(l,n1, x1);
    // printf("hii");
    int *B = binary(l,n2,x2);
    // printf("hii22");
    int x = AND(A,B,l);
    // printf("hii3");
    
    printf("%d",x);
    return 0;
}
