#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct Node
{
     int data;
     struct Node *prev;
     struct Node *next;
} node;
node *head = NULL;

int get_data(int data)
{
     scanf("%d", &data);
     return data;
}

node *createNode(node *newNode, int value)
{
     newNode = (node *)malloc(sizeof(node));
     newNode->data = value;
     newNode->next = NULL;
     newNode->prev = NULL;
     return newNode;
}

void inserting_choices()
{
     printf("\nTYPE 01 ---> Insert at beginning\n");
     printf("TYPE 02 ---> Insert at the end\n");
     printf("TYPE 03 ---> Insert at a position\n");
     printf("-------<Choose from the list above>------- Choice = ");
}

void deleting_choices()
{
     printf("\nTYPE 01 ---> Delete from beginning\n");
     printf("TYPE 02 ---> Delete from the end\n");
     printf("TYPE 03 ---> Delete from a position\n");
     printf("-------<Choose from the list above>------- Choice = ");
}

void sizeOfList()
{
     int length = 0;
     node *temp = head;
     if (head == NULL)
          printf("List contains 0 node.\n");
     else
     {
          while (temp->next != NULL)
          {
               length++;
               temp = temp->next;
          }
          printf("List contains %d nodes.\n", length);
     }
}

void display()
{
     printf("\n____________________________________________\n");
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
     printf("\t\t\t");
     sizeOfList();
     printf("\n--------------------------------------------\n");
}

void printRverse(node *head)
{
     if (head == NULL)
          return;
     printRverse(head->next);
     printf("%d->", head->data);
}

void display_reverse()
{
     printf("\n____________________________________________\n");
     printf("Given list in reverse order.\n");
     printRverse(head);
     printf("\n--------------------------------------------\n");
}

#include "insertion.h"
#include "deletion.h"
