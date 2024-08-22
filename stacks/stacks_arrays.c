#include <stdio.h>
#include <stdlib.h>

#define SIZE 100
int stack[SIZE];
int top = -1;

void push(int value)
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

void pop()
{
     if (top == -1)
          printf("Underflow, Stack is empty!\n");
     else
     {
          printf("%d deleted, ", stack[top]);
          top--;
     }
}

void display()
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

void display2()
{
     if (top == -1)
          printf("Underflow, Stack is already empty.\n");
     else
     {
          printf("Stack's elements are:\n");
          for (int i = top; i >= 0; i--)
               printf("%d->", stack[i]);
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