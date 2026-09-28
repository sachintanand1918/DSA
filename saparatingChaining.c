#include <stdio.h>
#include <stdlib.h>

#define SIZE 7

// Node of linked list
struct Node
{
    int key;
    struct Node *next;
};

// Hash table
struct Node *hashTable[SIZE];

// Hash function
int hashFunction(int key)
{
    return key % SIZE;
}

// Insert a key
void insert(int key)
{
    int index = hashFunction(key);

    struct Node *newNode =
        (struct Node *)malloc(sizeof(struct Node));

    newNode->key = key;

    // Insert at beginning of chain
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

// Search a key
int search(int key)
{
    int index = hashFunction(key);

    struct Node *current = hashTable[index];

    while (current != NULL)
    {
        if (current->key == key)
        {
            return 1;
        }

        current = current->next;
    }

    return 0;
}

// Display hash table
void display()
{
    int i;

    for (i = 0; i < SIZE; i++)
    {
        struct Node *current = hashTable[i];

        printf("%d: ", i);

        while (current != NULL)
        {
            printf("%d -> ", current->key);
            current = current->next;
        }

        printf("NULL\n");
    }
}

int main()
{
    // Initialize hash table
    for (int i = 0; i < SIZE; i++)
    {
        hashTable[i] = NULL;
    }

    insert(10);
    insert(20);
    insert(15);
    insert(7);
    insert(17);
    insert(24);
    insert(31);

    display();

    if (search(24))
        printf("24 Found\n");
    else
        printf("24 Not Found\n");

    return 0;
}