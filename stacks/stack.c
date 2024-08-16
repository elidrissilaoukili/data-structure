#include <stdio.h>
#include <stdlib.h>

#define SIZE 100
int stack[SIZE];
int top = -1;

void push_array(int value)
{
     if (top == SIZE - 1)
          printf("Overflow, Stack is full.\n");
     else
     {
          top++;
          stack[top] = value;
          printf("Insertion completed.\n");
     }
}

void pop_array()
{
     if (top == -1)
          printf("Underflow, Stack is empty§\n");
     else
     {
          printf("%d deleted, ", stack[top]);
          top--;
     }
}

void display_array()
{
     if (top == -1)
          printf("Underflow, Stack is already empty.\n");
     else
     {
          printf("Stack's elements are:\n");
          for (int i = top; i >= 0; i--)
               printf("\n\t|\t%d\t|\n\t-----------------", stack[i]);
     }
}

typedef struct Node
{
     int data;
     struct Node *next;
} stack_ll;
stack_ll *head = NULL;

stack_ll *createNode(stack_ll *newElement, int value)
{
     newElement = (stack_ll *)malloc(sizeof(stack_ll));
     newElement->next = NULL;
     newElement->data = value;
     return newElement;
}

void push_ll(int value)
{
     stack_ll *newElement;
     newElement = createNode(newElement, value);
     if (head == NULL)
          head = newElement;
     else
     {
          newElement->next = head;
          head = newElement;
     }
}
void pop_ll()
{
     if (head == NULL)
          printf("Stack is empty!\n");
     else
     {
          stack_ll *temp = head;
          head = temp->next;
          free(temp);
     }
}

void display_ll()
{
     if (head == NULL)
          printf("List is empty!\n");
     else
     {
          stack_ll *temp = head;
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
     int value, choice, choice2;
     char c;
     printf("\n\t**************** Stacks using Arrays & Linked lists ****************\n");
     do
     {
          printf("TYPE 01 ---> Using arrays.\n");
          printf("TYPE 02 ---> Using linked list.\n");
          printf("TYPE 03 ---> Display stack of array.\n");
          printf("TYPE 04 ---> Display stack of linked list.\n");
          printf("TYPE 05 ---> Display stack of linked list & arrays.\n");
          printf("TYPE 06 ---> Understand the concept of stacks.\n");
          printf("TYPE 07 ---> Break out.\n");
          printf("\nChoice = ");
          scanf("%d", &choice);
          switch (choice)
          {
          case 1:
               printf("\n1- push\n");
               printf("2- pop\n");
               printf("Choice = ");
               scanf("%d", &choice2);
               switch (choice2)
               {
               case 1:
                    printf("Enter value = ");
                    scanf("%d", &value);
                    push_array(value);
                    break;
               case 2:
                    pop_array();
                    break;
               default:
                    printf("Invalid chocie. Try again.\n");
                    break;
               }
               printf("\n------------------------------\n");
               display_array();
               printf("\n------------------------------\n");
               break;

          case 2:
               printf("\n1- push\n");
               printf("2- pop\n");
               printf("Choice = ");
               scanf("%d", &choice2);
               switch (choice2)
               {
               case 1:
                    printf("Enter value = ");
                    scanf("%d", &value);
                    push_ll(value);
                    break;
               case 2:
                    pop_ll();
                    break;
               default:
                    printf("Invalid chocie. Try again.\n");
                    break;
               }
               printf("\n------------------------------\n");
               display_ll();
               printf("\n------------------------------\n");
               break;

          case 3:
               printf("\n------------------------------\n");
               display_array();
               printf("\n------------------------------\n");
               break;
          case 4:
               printf("\n------------------------------\n");
               display_ll();
               printf("\n------------------------------\n");
               break;
          case 5:
               printf("\n------------------------------\n");
               printf("\t******************* Stack of linked list *******************\n");
               display_ll();
               printf("\n\t******************* Stack of array *******************\n");
               display_array();
               printf("\n------------------------------\n");
               break;
          case 6:
               printf("\n\t---Stacks follow the concept of LIFO (Last In First Out)\n\n");
               break;
          case 7:
               printf("Quiting task..\n");
               exit(0);
               break;
          default:
               printf("Invalid choice, try again!\n");
               break;
          }
     } while (1);

     return 0;
}

/*
Stacks: LIFO (Last In First Out).
*/