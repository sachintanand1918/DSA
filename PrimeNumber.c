#include<stdio.h>



bool isprime(int n){
        if (n<=1)
        return false;
        for (int i=2;i<=n/2;i++) 
    if (n%i== 0)
return false;
return true;   }

int main()
{
    int n =7;
    if(isprime(n))printf("%s","true");
    else printf("$s","false");
    return 0;
}