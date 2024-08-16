#pragma once
#include "functions.h"

void deleteAtBeginning()
{
     if (head == NULL)
          printf("List is already empty!\n");
     else
     {
          node *temp = head;
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

void deleteAtEnd()
{
     if (head == NULL)
          printf("List is already empty!\n");
     else
     {
          node *temp = head, *temp2;
          if (temp->next == NULL)
          {
               head = NULL;
               free(temp);
          }
          else
          {
               while (temp->next != NULL)
               {
                    temp2 = temp;
                    temp = temp->next;
               }
               temp2->next = NULL;
               free(temp);
          }
     }
}

void deleteAtPosition(int pos)
{
     int i, flag = 0;
     if (head == NULL)
          printf("List is already empty!\n");
     if (pos == 0 || pos == 1)
          deleteAtBeginning();
     else
     {
          node *temp = head, *temp2;
          for (i = 0; i < pos - 1; i++)
          {
               temp2 = temp;
               temp = temp->next;
          }
          temp2->next = temp->next;
          free(temp);
     }
}
