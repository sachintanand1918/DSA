#include <stdio.h>

int main()
{
    int n, blockSize, key;
    int i, j;
    
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter elements in sorted order:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Enter block size: ");
    scanf("%d", &blockSize);

    // Calculate number of blocks
    int blocks = (n + blockSize - 1) / blockSize;

    // Index array stores the last element of each block
    int index[blocks];

    j = 0;

    for(i = blockSize - 1; i < n; i = i + blockSize)
    {
        index[j] = a[i];
        j++;
    }

    // Store last element of the last block
    if(j < blocks)
    {
        index[j] = a[n - 1];
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    // Find the required block
    int block = -1;

    for(i = 0; i < blocks; i++)
    {
        if(index[i] >= key)
        {
            block = i;
            break;
        }
    }

    // Key is greater than the last element
    if(block == -1)
    {
        printf("Element Not Found");
        return 0;
    }

    // Starting index of selected block
    int start = block * blockSize;

    // Ending index of selected block
    int end = start + blockSize - 1;

    if(end >= n)
    {
        end = n - 1;
    }

    // Sequential search inside the selected block
    for(i = start; i <= end; i++)
    {
        if(a[i] == key)
        {
            printf("Element Found at index %d", i);
            return 0;
        }
    }

    printf("Element Not Found");

    return 0;
}