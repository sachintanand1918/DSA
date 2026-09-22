#include <stdio.h>
#define CAPACITY 5

int queue[CAPACITY];
int front = -1;
int rear = -1;

// Insert (Enqueue)
void enqueue(int value)
{
    // Queue is full
    if ((rear + 1) % CAPACITY == front)
    {
        printf("Queue Overflow\n");
        return;
    }

    // Queue is empty
    if (front == -1)
    {
        front = rear = 0;
    }
    else
    {
        rear = (rear + 1) % CAPACITY;
    }

    queue[rear] = value;

    printf("%d inserted\n", value);
}

// Delete (Dequeue)
void dequeue()
{
    // Queue is empty
    if (front == -1)
    {
        printf("Queue Underflow\n");
        return;
    }

    printf("%d deleted\n", queue[front]);

    // Only one element was present
    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % CAPACITY;
    }
}

// Display
void display()
{
    if (front == -1)
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue: ");

    int i = front;

    while (1)
    {
        printf("%d ", queue[i]);

        if (i == rear)
            break;

        i = (i + 1) % CAPACITY;
    }

    printf("\n");
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    display();

    dequeue();
    dequeue();

    display();

    enqueue(60);
    enqueue(70);

    display();

    return 0;
}