#include <stdio.h>
#include <stdlib.h>

// Linked list O(1) enQueue and deQueue

typedef struct Queue
{
    int data;
    struct Queue *next;
} Queue;

Queue *head = NULL;
Queue *tail = NULL;

Queue *create_node(int value)
{
    Queue *node = (Queue *)malloc(sizeof(Queue));
    node->data = value;
    node->next = NULL;
    return node;
}

void enQueue(int value)
{
    Queue *element = create_node(value);
    if (tail == NULL)
    { // Queue is empty
        head = tail = element;
    }
    else
    {
        tail->next = element;
        tail = element;
    }
}

void deQueue()
{
    if (head == NULL)
    {
        printf("Underflow, queue is empty!\n");
        return;
    }
    Queue *temp = head;
    if (head == tail)
    { // Only one element in the queue
        head = tail = NULL;
    }
    else
    {
        head = head->next;
    }
    free(temp);
}

void display()
{
    printf("\n------------------------------------------------------\n");
    if (head == NULL)
    {
        printf("List is empty!\n");
    }
    else
    {
        Queue *temp = head;
        while (temp != NULL)
        {
            printf(" %d | ", temp->data);
            temp = temp->next;
        }
    }
    printf("\n------------------------------------------------------\n");
}

int main()
{
    while (1)
    {
        int value, choice;
        printf("TYPE 01 ---> push\n");
        printf("TYPE 02 ---> pop\n");
        printf("\nchoice = ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nValue = ");
            scanf("%d", &value);
            enQueue(value);
            display();
            break;
        case 2:
            deQueue();
            display();
            break;
        default:
            printf("No valid option\n");
            break;
        }
    }
    return 0;
}
