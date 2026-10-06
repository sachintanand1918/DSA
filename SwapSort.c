 #include<stdio.h>
void swap(int a[],int i,int j)
{
    int temp =a[i];
    a[i]=a[j];
    a[j]=temp;

}
int PARTITION(int a[],int p,int r)
{ 
int x =a[r];
int i = p-1;
int j;
for(j = p;j<=r-1;j++) 
{
    if(a[j]<=x)
    {
       i=i+1;
       swap(a,i,j);
    } 
}
swap(a,i+1,r);
return i+1;
}
void quicksort(int a[],int p,int r)
{
    if (p<r)
    {
        int q = PARTITION(a,p,r);
        quicksort(a,p,q-1);
        quicksort(a,q+1,r);

    }
}

int main()
{
    int a[5], i;
    printf("Enter 5 elements:\n");

    for (i = 0; i < 5; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &a[i]);
    }

    quicksort(a, 0, 4);
    printf("Sorted array is: \n");

    for (i = 0; i < 5; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}
