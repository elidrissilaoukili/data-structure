#include <stdio.h>
#include <stdlib.h>

#define SIZE 100
int queue[SIZE];
int rear = -1, front = -1;

// functions we are going to use
void enQueue_arrays(int value)
{
     if (rear == SIZE - 1)
          printf("Overflow, queue is full\n");
     else
     {
          if (front == -1)
               front = 0;
          rear++;
          queue[rear] = value;
          printf("Insertion DONE!\n");
     }
}
void deQueue_arrays()
{
     if (rear == front)
          printf("Underflow, queue is empty!\n");
     else
     {
          printf("%d deleted successful\n", queue[front]);
          front++;
          if (rear == front)
               rear = front = -1;
     }
}
void display_arrays()
{
     if (rear == -1)
          printf("Queue is empty!\n");
     else
          for (int i = front; i <= rear; i++)
               printf(" %d | ", queue[i]);
}

typedef struct queue_node
{
     int data;
     struct queue_node *next;
} queue_node;
queue_node *head = NULL;

queue_node *create_node(int value)
{
     queue_node *node = (queue_node *)malloc(sizeof(queue_node));
     if (node != NULL)
     {
          node->data = value;
          node->next = NULL;
     }
     else
          printf("Allocation failed!!\n");
     return node;
}

void enQueue_LL(int value) // insert at the end
{
     queue_node *element = create_node(value);
     if (head == NULL)
          head = element;
     else
     {
          queue_node *temp = head;
          if (temp->next != NULL)
               temp = temp->next;
          temp->next = element;
     }
}
void deQueue_LL() // delete from beginning
{
     queue_node *temp = head;
     if (head == NULL)
          printf("Queue is empty!!\n");
     if (head->next == NULL)
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
void display_LL()
{
     if (head == NULL)
          printf("Queue is empty!!\n");
     else
     {
          queue_node *temp = head;
          while (temp->next != NULL)
          {
               printf(" %d |", temp->data);
               temp = temp->next;
          }
          printf(" %d |", temp->data);
     }
}

int main()
{
     int choice, choice2, value;
     while (1)
     {
          printf("\n\n01 -> Queue, using arrrys\n");
          printf("02 -> Queue, using linked list\n");
          printf("03 -> Display queue, using arrrys\n");
          printf("04 -> Display queue, using linked list\n");
          printf("05 -> Display queue, using both arrays & linked list\n");
          printf("06 -> Understand the concept of Queues.\n");
          printf("07 -> Quit.\n");
          printf("\nChoice: ");
          scanf("%d", &choice);
          switch (choice)
          {
          case 1:
               printf("01 --> Push\n");
               printf("02 --> Pop\n");
               printf("Choice:: ");
               scanf("%d", &choice2);
               switch (choice2)
               {
               case 1:
                    printf("Value = ");
                    scanf("%d", &value);
                    enQueue_arrays(value);
                    break;
               case 2:
                    deQueue_arrays();
                    break;
               default:
                    printf("This choice not exit in the menu\n");
                    break;
               }
               break;

          case 2:
               printf("01 --> Push\n");
               printf("02 --> Pop\n");
               printf("Choice:: ");
               scanf("%d", &choice2);
               switch (choice2)
               {
               case 1:
                    printf("Value = ");
                    scanf("%d", &value);
                    enQueue_LL(value);
                    break;
               case 2:
                    deQueue_LL();
                    break;
               default:
                    printf("This choice not exit in the menu\n");
                    break;
               }
               break;

          case 3:
               display_arrays();
               break;

          case 4:
               display_LL();
               break;

          case 5:
               printf("\n\n");
               display_arrays();
               printf("\t\t");
               display_LL();
               printf("\n\n");
               break;

          case 6:
               printf("Queues: follows the concept of FIFO (First In First Out)\n");
               break;
          case 7:
               printf("Quiting.. \n");
               exit(0);
               break;

          default:
               printf("\nInvalid choice try again!\n");
               break;
          }
     }

     return 0;
}

/*
Queues: FIFO (First In First Out).
*/