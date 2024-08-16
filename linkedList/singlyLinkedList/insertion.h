#pragma once
#include "functions.h"

void insertAtBeginning(int value)
{
     node *newNode;
     newNode = allocate(newNode, value);
     if (head == NULL)
          head = newNode;
     else
     {
          newNode->next = head;
          head = newNode;
     }
}

void insertAtEnd(int value)
{
     node *newNode;
     newNode = allocate(newNode, value);
     if (head == NULL)
          head = newNode;
     else
     {
          node *temp = head;
          while (temp->next != NULL)
               temp = temp->next;
          temp->next = newNode;
          // newNode->next = NULL;
     }
}

void insertAtPosition(int value, int pos)
{
     node *newNode;
     newNode = allocate(newNode, value);
     if (head == NULL)
          head = newNode;
     if (pos == 0 || pos == 1)
          insertAtBeginning(value);
     else
     {
          node *temp = head;
          for (int i = 1; i < pos - 1; i++)
               temp = temp->next;
          newNode->next = temp->next;
          temp->next = newNode;
     }
}
