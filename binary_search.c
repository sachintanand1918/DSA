#include <stdio.h>

int binary_search(const int array[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int middle = left + (right - left) / 2;

        if (array[middle] == target) {
            return middle;
        }

        if (array[middle] < target) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }

    return -1;
}

int main(void) {
    int size;

    printf("Enter the number of elements: ");
    if (scanf("%d", &size) != 1 || size <= 0) {
        printf("Invalid array size.\n");
        return 1;
    }

    int array[size];

    printf("Enter %d sorted elements: ", size);
    for (int index = 0; index < size; index++) {
        if (scanf("%d", &array[index]) != 1) {
            printf("Invalid element.\n");
            return 1;
        }
    }

    int target;
    printf("Enter the value to search for: ");
    if (scanf("%d", &target) != 1) {
        printf("Invalid target.\n");
        return 1;
    }

    int result = binary_search(array, size, target);
    if (result == -1) {
        printf("%d was not found.\n", target);
    } else {
        printf("%d was found at index %d.\n", target, result);
    }

    return 0;
}
