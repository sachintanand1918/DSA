#include <stdio.h>
int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    if(a % b ==0)
    printf("%d is divisible by b",a);
    else 
    printf(" %d  is not divisible by b",b);
    return 0;
}