#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct Node
{
     int data;
     struct Node *next;
} node;

node *head = NULL;

node *allocate(node *newNode, int value)
{
     newNode = (node *)malloc(sizeof(node));
     newNode->data = value;
     newNode->next = NULL;
     return newNode;
}

void insrting_choices()
{
     printf("\nTYPE 01 ---> Insert at beginning,\n");
     printf("TYPE 02 ---> Insert at end,\n");
     printf("TYPE 03 ---> Insert at a position,\n");
     printf("Choice = ");
}
void deleteing_choices()
{
     printf("TYPE 01 ---> Delete beginning,\n");
     printf("TYPE 02 ---> Delete end,\n");
     printf("TYPE 03 ---> Delete from a position,\n");
     printf("Choice = ");
}
int get_data(int data)
{
     scanf("%d", &data);
     return data;
}

void sizeOfList()
{
     node *temp = head;
     if (head == NULL)
          printf("List is contains 0 node.\n");
     else
     {
          int count = 0;
          while (temp->next != NULL)
          {
               count++;
               temp = temp->next;
          }
          printf("The list contains %d nodes.", count);
     }
}

void listInReverseOrder()
{
     node *prevNode, *curNode;

     if (head != NULL)
     {
          prevNode = head;
          curNode = head->next;
          head = head->next;

          prevNode->next = NULL; // convert the first node as last

          while (head != NULL)
          {
               head = head->next;
               curNode->next = prevNode;

               prevNode = curNode;
               curNode = head;
          }
          head = prevNode; // convert the last node as head
     }
}

void display()
{
     printf("\n_______________________________________________________\n");
     node *temp = head;
     if (head == NULL)
          printf("List is already empty!\n");
     else
     {
          while (temp->next != NULL)
          {
               printf("%d->", temp->data);
               temp = temp->next;
          }
          printf("%d", temp->data);
     }
     printf("\t\t\t|||| \t");
     sizeOfList();
     printf("\n-------------------------------------------------------\n");
}

#include "insertion.h"
#include "deletion.h"
