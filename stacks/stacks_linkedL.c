#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
     int data;
     struct Node *next;
} stack;
stack *head = NULL;

stack *createNode(stack *newElement, int value)
{
     newElement = (stack *)malloc(sizeof(stack));
     newElement->next = NULL;
     newElement->data = value;
     return newElement;
}

void push(int value)
{
     stack *newElement;
     newElement = createNode(newElement, value);
     if (head == NULL)
          head = newElement;
     else
     {
          newElement->next = head;
          head = newElement;
     }
}
void pop()
{
     if (head == NULL)
          printf("Stack is empty!\n");
     else
     {
          stack *temp = head;
          head = temp->next;
          free(temp);
     }
}

void display()
{
     if (head == NULL)
          printf("List is empty!\n");
     else
     {
          stack *temp = head;
          while (temp->next != NULL)
          {
               printf("\n\t|\t%d\t|\n\t-----------------", temp->data);
               temp = temp->next;
          }
          printf("\n\t|\t%d\t|\n\t-----------------", temp->data);
     }
}

int main()
{
     int value, choice;
     do
     {
          printf("1- push\n");
          printf("2- pop\n");
          printf("Choice = ");
          scanf("%d", &choice);
          switch (choice)
          {
          case 1:
               printf("Enter value = ");
               scanf("%d", &value);
               push(value);
               break;
          case 2:
               pop();
               break;
          default:
               printf("Invalid chocie. Try again.\n");
               break;
          }
          printf("\n------------------------------\n");
          display();
          printf("\n------------------------------\n");
     } while (1);

     return 0;
}