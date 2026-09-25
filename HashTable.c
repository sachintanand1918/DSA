#include <stdio.h>

#define SIZE 10

int hashTable[SIZE];

/*
Algorithm for insertion using Linear Probing:
1. Calculate the hash index.
2. If the index is empty, insert the key.
3. If the index is occupied, move to the next index.
4. Use modulo to wrap around.
5. Repeat until an empty location is found.
6. If all locations are checked, the table is full.
*/

void insert(int key)
{
    int index = key % SIZE;
    int startIndex = index;

    while (hashTable[index] != -1)
    {
        index = (index + 1) % SIZE;

        // All positions checked
        if (index == startIndex)
        {
            printf("Hash table is full.\n");
            return;
        }
    }

    hashTable[index] = key;
}

/*
Algorithm for searching:
1. Calculate the initial hash index.
2. Check the current position.
3. If key is found, return success.
4. If the position is empty, key is not present.
5. Otherwise move to the next position.
6. Continue until the starting position is reached.
*/

int search(int key)
{
    int index = key % SIZE;
    int startIndex = index;

    while (hashTable[index] != -1)
    {
        if (hashTable[index] == key)
        {
            return 1;
        }

        index = (index + 1) % SIZE;

        if (index == startIndex)
        {
            break;
        }
    }

    return 0;
}

void display()
{
    int i;

    for (i = 0; i < SIZE; i++)
    {
        if (hashTable[i] == -1)
        {
            printf("%d : EMPTY\n", i);
        }
        else
        {
            printf("%d : %d\n", i, hashTable[i]);
        }
    }
}

int main()
{
    int i;

    // Initialize hash table
    for (i = 0; i < SIZE; i++)
    {
        hashTable[i] = -1;
    }

    insert(23);
    insert(15);
    insert(42);
    insert(35);
    insert(52);
    insert(25);

    display();

    if (search(25))
    {
        printf("25 Found\n");
    }
    else
    {
        printf("25 Not Found\n");
    }

    return 0;
}