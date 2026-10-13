#include<stdio.h>
int main()
{
int arr[100],n,i,j,key;
printf("Enter the number of element:");
scanf("%d",&n); 
printf("Enter the element :\n");

for(i=0;i<n;i++)
{
    scanf("%d", &arr[i]);

}
for(i=1;i<n;i++)
{
    key = arr[i];
    j=i-1;
    while(j>=0 && arr[j] > key)
    {
        arr[j+1] =arr[j];
        j--;
    }
    arr[j+1]=key;

}
printf("sorted array is :\n");
for(i=0;i<n;i++)
{
    printf("%d\n",arr[i]);

}
return 0;
}