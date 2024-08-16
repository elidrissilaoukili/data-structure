#include <stdio.h>
#include <stdlib.h>

#define SIZE 100
int queue[SIZE];
int rear = -1, front = -1;

void enQueue(int value)
{
     if (rear == SIZE - 1)
          printf("Overflow, queue is full\n");
     else
     {
          if (front == -1)
               front = 0;
          rear++;
          queue[rear] = value;
          printf("Value %d added to the queue successful.\n", value);
     }
}

void deQueue()
{
     if (rear == front)
          printf("Underflow, queue is already empty!\n");
     else
     {
          printf("%d deleted\n", queue[front]);
          front++;
          if (front == rear)
               rear = front = -1;
     }
}

void display_array()
{
     printf("\n------------------------------------------------------------\n");
     if (rear == -1)
          printf("Queue is empty!\n");
     else
     {
          for (int i = front; i <= rear; i++)
               printf(" %d |", queue[i]);
     }
     printf("\n------------------------------------------------------------\n");
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
               display_array();
               break;
          case 2:
               deQueue();
               display_array();
               break;

          default:
               printf("no valid\n");
               break;
          }
     }
     return 0;
}