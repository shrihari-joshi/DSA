#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int*A;

int *Areg(int l,int *a){
    for(int i=0;i<l;i++){
        a[i]=0;
    }
    return a;
}
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
    for (int i = l - 1; i >= 0; i--)
    {
        printf("%d", bi[i]);
    }

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
    return c + 1;
}

int toggle(int x)
{
    if (x == 0)
        x = 1;
    else if (x == 1)
        x = 0;
    return x;
}
void print(int *X, int l){
    for(int i=l-1;i>=0;i--){
        printf("%d",X[i]);
    }
    printf("\t");
}
int* add(int* A, int* M, int l){
    int c=0;
    int i=0;
    int *res;
    for(i;i<l;i++){
        res[i] = (A[i] + M[i] + c )%2;
        c = (A[i] + M[i] + c )/2;
    }
    if(c!=0)
    res[i]=c;
    A=res;
    print(A,l);
    return A;
}

void rightshift(int *A, int *Q, int Q1, int l){
    Q1=Q[0];
    for(int i=0;i<l;i++){
        Q[i]=Q[i+1];
    }
    int x=A[0];
    Q[l-1]=x;
    for(int i=0;i<l;i++){
        A[i]=A[i+1];
    }
    A[l-1]=A[l-2];
    print(A,l);
    print(Q,l);
    printf("%d",Q1);
}
int* twoc(int *M, int n)
{
    int *x = M;
    int i=0;
    while(i<n){
        if(x[i]==1){
            i++;
            break;
        }
        i++;
    }
    while(i<n){
        x[i]=toggle(x[i]);
        i++;
    }
    return x;
}


int main()
{
    int n1, n2;
    printf("Enter Two Numbers\n");
    scanf("%d %d", &n1, &n2);
    int l = 0;
    if (n1 > n2)
        l = size(n1);

    else
        l = size(n2);
    
    printf("The Length will be %d\n", l);
    int x1[l];
    int x2[l];
    
    printf("The value in M will be: ");
    int *M = binary(l, n1, x1);
    printf("\n");
    
    printf("The value in Q will be: ");
    int *Q = binary(l, n2, x2);
    printf("\n");
    int a[l];
    A = Areg(l,a);
    int Q1=0;
    int i=l;
    while(i>=0)
    {
        if(Q[0]==0 && Q1==1){
            printf("ADD\t");
            A = add(A,M,l);
            printf("\n");
        }

        if(Q[0]==1 && Q1==0){
            int *temp = twoc(M,l);
            A = add(A,temp,l);
            print(Q,l);
            printf("%d",Q1);
            printf("\n");
        }
            rightshift(A,Q,Q1,l);
            printf("\nLoop %d Ends\n", i);
            i--;
    }
    return 0;
}
