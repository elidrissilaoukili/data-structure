#include <stdio.h>
#include <stdlib.h>

typedef struct Queue
{
     int data;
     struct Queue *next;
} queue;

queue *head = NULL;

queue *create_node(int value)
{
     queue *node = (queue *)malloc(sizeof(queue));
     node->data = value;
     node->next = NULL;
     return node;
}

void enQueue(int value)
{
     queue *element = create_node(value);
     if (head == NULL)
          head = element;
     else
     {
          queue *temp = head;
          while (temp->next != NULL)
               temp = temp->next;
          temp->next = element;
     }
}

void deQueue()
{
     if (head == NULL)
          printf("Underflow, queue is empty!\n");
     else
     {
          queue *temp = head;
          if (temp->next == NULL)
          {
               head = NULL;
               free(temp);
          }
          else
          {
               head = temp->next;
               free(temp);
          }
     }
}

void display()
{
     printf("\n------------------------------------------------------\n");
     if (head == NULL)
          printf("List is empty!\n");
     else
     {
          queue *temp = head;
          while (temp->next != NULL)
          {
               printf(" %d | ", temp->data);
               temp = temp->next;
          }
          printf(" %d | ", temp->data);
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
               printf("no valid\n");
               break;
          }
     }
     return 0;

     return 0;
}