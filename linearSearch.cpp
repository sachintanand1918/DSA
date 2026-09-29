#include <stdio.h>

// ======================================================
// ALGORITHM: SEQUENTIAL SEARCH
// ======================================================
// 1. Start.
// 2. Read the number of elements n.
// 3. Read n elements into the array.
// 4. Read the element to be searched as key.
// 5. Set i = 0.
// 6. Compare key with each element of the array sequentially.
// 7. If arr[i] == key, display that the element is found
//    and its position, then stop the search.
// 8. If all elements are checked and the key is not found,
//    display "Element not found".
// 9. Stop.
// ======================================================

int main()
{
    int arr[100];
    int n, key;
    int i;
    int found = 0;

    // Step 2: Read number of elements
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Step 3: Read array elements
    printf("Enter %d elements:\n", n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Step 4: Read key
    printf("Enter element to search: ");
    scanf("%d", &key);

    // Step 5 & 6: Sequentially search the element
    for (i = 0; i < n; i++)
    {
        // Step 7: Compare current element with key
        if (arr[i] == key)
        {
            printf("Element found at position %d\n", i + 1);
            found = 1;
            break;
        }
    }

    // Step 8: Element not found
    if (found == 0)
    {
        printf("Element not found\n");
    }

    // Step 9: Stop
    return 0;
}