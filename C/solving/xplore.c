#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

long long int nth(long long int n,long long int x,long long int y)
{
    if(n==1)
        return x;
    if(n==2)
        return y;
    
    return (nth(n-1,x,y) - nth(n-2,x,y));
}

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    long long int x,y,n,result,temp;
    result =-1;
    scanf("%lld %lld",&x,&y);
    scanf("%lld",&n);
    temp = nth(n,x,y);
    
    result = temp % 1000000007;
    if(result<0)
    {
        // result = 1000000007 + result;
    }
    printf("%lld",result);
    return result;
}
